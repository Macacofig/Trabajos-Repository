import numpy as np

class LogisticRegressionOvR:
    """
        Implementación desde cero de Regresión Logística Multiclase
        usando estrategia One-vs-Rest (uno contra todos).
        
        Para cada clase, entrena un clasificador binario que distingue
        esa clase de todas las demás.
    """
    def __init__(self, learning_rate=0.1, n_iter=1000, lambda_reg=0.01, verbose=True):
        """
            Inicializa el clasificador de Regresión Logística One-vs-Rest.
            
            Parámetros:
            -----------
            learning_rate : float, opcional (default=0.1)
                Tasa de aprendizaje para el descenso de gradiente.
                Controla el tamaño de los pasos durante la optimización.
                - Muy alto (ej: 1.0): Puede divergir
                - Muy bajo (ej: 0.001): Entrenamiento muy lento
                - 0.1: Valor típico para problemas de clasificación
            
            n_iter : int, opcional (default=1000)
                Número máximo de iteraciones de entrenamiento.
                - Determina cuántas veces se actualizan los pesos
                - 1000 es suficiente para converger sin sobreajustar
            
            lambda_reg : float, opcional (default=0.01)
                Parámetro de regularización L2 (Ridge).
                Penaliza pesos grandes para evitar sobreajuste.
                - 0: Sin regularización (riesgo de sobreajuste)
                - 0.01: Regularización suave
                - 1.0: Regularización fuerte (riesgo de subajuste)
            
            verbose : bool, opcional (default=True)
                Controla la impresión de mensajes durante el entrenamiento.
                - True: Muestra progreso y costos
                - False: Entrenamiento silencioso
            
            Atributos que se crean:
            -----------------------
            self.learning_rate = 0.1
            self.n_iter = 1000
            self.lambda_reg = 0.01
            self.verbose = True
            self.models = {}      # Diccionario vacío para guardar cada clasificador binario
            self.n_classes = None # Se establecerá durante fit()
            
        """
        self.learning_rate = learning_rate
        self.n_iter = n_iter
        self.lambda_reg = lambda_reg
        self.verbose = verbose
        self.models = {}
        self.n_classes = None
    
    def sigmoid(self, z):
        """
        Función de activación sigmoide.
        Transforma valores a rango [0, 1] para representar probabilidades.
        
        Fórmula: σ(z) = 1 / (1 + exp(-z))
        
        Parámetros:
        - z: entrada lineal
        
        Retorna:
        - valor sigmoide entre 0 y 1
        """
        
        z = np.clip(z, -20, 20)
        return 1.0 / (1.0 + np.exp(-z))
    
    def compute_cost(self, X, y, w, b):
        """
        Calcula la función de costo (entropía cruzada) con regularización L2.
        
        Parámetros:
        - X: características (n_samples, n_features)
        - y: etiquetas binarias
        - w: pesos del modelo
        - b: sesgo
        
        Retorna:
        - valor del costo (escalar)
        """
        
        m = X.shape[0]
        z = X.dot(w) + b
        predictions = self.sigmoid(z)
        
        # Cross-entropy
        cost = -np.mean(y * np.log(predictions + 1e-8) +  # +1e-8 evita log(0)
                       (1 - y) * np.log(1 - predictions + 1e-8))
        
        # Regularización L2
        # Sobre Ajuste Regresion Logistica
        reg_cost = (self.lambda_reg / (2 * m)) * np.sum(w**2)# ¡IMPORTANTE!
        
        return cost + reg_cost
    
    def train_binary_classifier(self, X, y_binary, class_idx):
        """
        Entrena un clasificador binario para una clase específica.
        
        Parámetros:
        - X: características de entrenamiento
        - y_binary: etiquetas binarias (1 para la clase, 0 para otras)
        - class_idx: índice de la clase actual
        
        Retorna:
        - w: pesos entrenados
        - b: sesgo entrenado
        - costs: historial de costos durante entrenamiento
        """
       
        m, n = X.shape
        w = np.random.randn(n) * 0.0001
        b = 0.0
        
        costs = []
        
        for i in range(self.n_iter):
            # Forward
            z = X.dot(w) + b
            predictions = self.sigmoid(z)
            error = predictions - y_binary
            
            # Gradientes
             # ACTUALIZACIÓN CON REGULARIZACIÓN L2
            dw = (X.T.dot(error) / m) + (self.lambda_reg / m) * w # ¡TÉRMINO DE REGULARIZACIÓN!
            db = np.mean(error)
            
            # Actualizar
            w -= self.learning_rate * dw
            b -= self.learning_rate * db
            
            if i % 100 == 0:
                cost = self.compute_cost(X, y_binary, w, b)
                costs.append(cost)
                
                if self.verbose and i % 500 == 0:
                    print(f"    Clase {class_idx}, Iteracion {i}: Costo = {cost:.4f}")
        
        return w, b, costs
    
    def fit(self, X, y):
        """
            Entrena todos los clasificadores binarios (One-vs-Rest).
            
            Parámetros:
            - X: características de entrenamiento
            - y: etiquetas multiclase
        """
        self.n_classes = len(np.unique(y))
        
        if self.verbose:
            print("\n" + "="*60)
            print("ENTRENANDO REGRESION LOGISTICA (One-vs-Rest)")
            print("="*60)
        
        for c in range(self.n_classes):
            if self.verbose:
                print(f"\n  Clase {c}...")
            
            y_binary = (y == c).astype(float)
            w, b, costs = self.train_binary_classifier(X, y_binary, c)
            
            self.models[c] = {'w': w, 'b': b}
        
        if self.verbose:
            print("Entrenamiento completado")
    
    def predict(self, X):
        """
            Predice clases para nuevas muestras.
            
            Parámetros:
            - X: características a predecir
            
            Retorna:
            - predicciones de clase (índices)
        """
        n_samples = X.shape[0]
        scores = np.zeros((n_samples, self.n_classes))
        
        for c in range(self.n_classes):
            w = self.models[c]['w']
            b = self.models[c]['b']
            scores[:, c] = X.dot(w) + b
        
        probabilities = self.sigmoid(scores)
        return np.argmax(probabilities, axis=1)
    
    def accuracy(self, X, y):
        """Calcular exactitud"""
        predictions = self.predict(X)
        return np.mean(predictions == y)
