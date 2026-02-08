import numpy as np
import matplotlib.pyplot as plt

# Clase de Regresion lineal con descenso de gradiente y utilidades de preprocesamiento
class Regresion:
    """
    Clase Regresion
    ----------------
    Implementa un modelo de regresion lineal entrenado mediante descenso de gradiente
    con regularizacion L2 y utilidades de limpieza, normalizacion, K-Fold y pipeline.
    """

    def __init__(self):
        # Inicializa atributos
        self.__X = None                # matriz de features (con bias)
        self.__y = None                # variable objetivo
        self.__X_testing = None        # placeholder para X_test
        self.__y_testing = None        # placeholder para y_test
        self.__theta = None            # parametros del modelo
        self.__history = None          # historial de costo durante el entrenamiento

    # Carga datos y prepara X con bias y theta inicial
    def fit(self, x, y):
        m, n = x.shape
        # agrega columna de 1s para bias
        self.__X = np.append(np.ones((m, 1)), x.reshape(m, -1), axis=1)
        self.__y = y.reshape(-1, 1)   # fuerza formato columna
        self.__theta = np.zeros(n + 1) # inicializa parametros en ceros

    # Division estratificada en train/test segun percentiles de y
    def split_test_stratified(self, test_size=0.2, bins=5, random_state=None):
        if self.__X is None or self.__y is None:
            raise ValueError("Primero cargue los datos con fit()")
        y = self.__y.flatten()
        m = len(y)
        test_samples = int(m * test_size)

        if random_state is not None:
            np.random.seed(random_state)

        # Crea estratos usando percentiles
        percentiles = np.linspace(0, 100, bins + 1)
        bins = np.percentile(y, percentiles)
        y_binned = np.digitize(y, bins[:-1])

        train_indices = []
        test_indices = []

        for stratum in np.unique(y_binned):
            stratum_indices = np.where(y_binned == stratum)[0]
            stratum_size = len(stratum_indices)
            stratum_test_size = int(stratum_size * test_size)
            np.random.shuffle(stratum_indices)
            test_indices.extend(stratum_indices[:stratum_test_size])
            train_indices.extend(stratum_indices[stratum_test_size:])

        np.random.shuffle(train_indices)
        np.random.shuffle(test_indices)

        # Crear splits finales
        self.__X_test = self.__X[test_indices]
        self.__y_test = self.__y[test_indices]
        self.__X = self.__X[train_indices]
        self.__y = self.__y[train_indices]

        self.__y = self.__y.reshape(-1, 1)
        self.__y_test = self.__y_test.reshape(-1, 1)

        print(f"Division estratificada completada: {len(self.__y)} train, {len(self.__y_test)} test")
        print(f"Distribucion en test: {np.histogram(self.__y_test, bins=bins)[0]}")

    # Propiedades para acceder a X y y
    @property
    def get_X(self):
        return self.__X

    @property
    def get_y(self):
        return self.__y

    @property
    def get_X_test(self):
        return self.__X_test

    @property
    def get_y_test(self):
        return self.__y_test

    def get_param(self):
        return self.__theta

    # Normaliza features usando media y desviacion de train
    def normalizar_seguro(self):
        self._mean = self.__X[:,1:].mean(0)
        self._std = self.__X[:,1:].std(0)
        self._std[self._std == 0] = 1  # evitar division por cero
        self.__X[:,1:] = (self.__X[:,1:] - self._mean) / self._std
        if hasattr(self, "_Regresion__X_test") and self.__X_test.shape[1] == self.__X.shape[1]:
            self.__X_test[:,1:] = (self.__X_test[:,1:] - self._mean) / self._std

    # Calcula el costo MSE
    def get_j(self, theta):
        theta = theta.reshape(-1, 1)
        m = self.__X.shape[0]
        h = self.__X.dot(theta)
        error = h - self.__y
        j = 1 / (2 * m) * np.power(error, 2) # ERROR CUADRATICO MEDIO
        return j.sum()

    # Calcula gradiente sin regularizacion
    def get_gradiente(self, theta):
        theta = theta.reshape(-1, 1)
        m = self.__X.shape[0]
        h = self.__X.dot(theta)
        error = h - self.__y
        grad = (1/m) * self.__X.T.dot(error)
        return grad.flatten()

    # Calcula gradiente con regularizacion L2
    def get_gradiente_reg(self, theta, lambd=0.0):
        theta = theta.reshape(-1, 1)
        m = self.__X.shape[0]
        h = self.__X.dot(theta)
        error = h - self.__y
        grad = (1/m) * self.__X.T.dot(error)
        grad[1:] += (lambd / m) * theta[1:]
        return grad.flatten()

    # Descenso de gradiente con opcion de regularizacion
    def descenso_de_gradiente(self, alpha, epsilon=1e-6, itera=None, lambd=0.0):
        js = []
        theta = self.__theta
        i = 0
        while True:
            js.append(self.get_j(theta))
            grad = self.get_gradiente_reg(theta, lambd)
            theta = theta - alpha * grad
            if abs(self.get_j(theta) - js[-1]) < epsilon:
                break
            if itera is not None and i >= itera:
                break
            i += 1
        print("Numero de iteraciones: ", i)
        print("Costo: ", js[-1])
        self.__theta = theta
        self.__history = np.array(js)
        print("Parametros: ", self.__theta)

    # MSE
    def get_ECM(self, x=None, y=None):
        if x is None or y is None:
            if hasattr(self, '_Regresion__X_test') and hasattr(self, '_Regresion__y_test'):
                x, y = self.__X_test, self.__y_test
            else:
                x, y = self.__X, self.__y
        y = y.reshape(-1, 1)
        y_pred = x.dot(self.__theta).reshape(-1, 1)
        mse = np.mean((y_pred - y) ** 2)
        return mse

    # RMSE
    def get_RECM(self, x=None, y=None):
        return np.sqrt(self.get_ECM(x, y))

    # R2
    def get_r2(self, x=None, y=None):
        if x is None or y is None:
            if self.__X_test is None or self.__y_test is None:
                x, y = self.__X, self.__y
            else:
                x, y = self.__X_test, self.__y_test
        y_pred = x.dot(self.__theta).reshape(-1, 1)
        y = y.reshape(-1, 1)
        ss_res = np.sum((y - y_pred) ** 2)
        ss_tot = np.sum((y - np.mean(y)) ** 2)
        r2 = 1 - (ss_res / ss_tot) if ss_tot != 0 else 0
        return r2

    # K-Fold cross validation
    def kfold_cross_validation(self, k=5, alpha=0.01, epsilon=1e-6, itera=1000, random_state=None):
        """
        Realiza validacion cruzada K-Fold.
        Para cada fold:
        - separa train y validacion
        - normaliza train y aplica normalizacion a validacion
        - entrena con descenso de gradiente
        - calcula MSE, RMSE, R2 en validacion
        Al final imprime promedios y desviaciones
        """
        if self.__X is None or self.__y is None:
            raise ValueError("Primero cargue los datos con fit()")
        if random_state is not None:
            np.random.seed(random_state)
            
        m = self.__X.shape[0]
        indices = np.arange(m)
        np.random.shuffle(indices)
        fold_size = m // k
        metrics = {'mse': np.zeros(k), 'rmse': np.zeros(k),'mae': np.zeros(k), 'r2': np.zeros(k)}

        indices_folds = np.array_split(indices, k)
        
        for i in range(k):
            print(f"\nProcesando fold {i+1}/{k}...")
            val_indices = indices_folds[i]
            train_indices = np.hstack([indices_folds[j] for j in range(k) if j != i])
            X_train, y_train = self.__X[train_indices].copy(), self.__y[train_indices].copy()
            X_val, y_val = self.__X[val_indices].copy(), self.__y[val_indices].copy()

            # Normalizar features (sin bias)
            self._mean = X_train[:,1:].mean(0)
            self._std = X_train[:,1:].std(0)
            self._std[self._std == 0] = 1
            X_train[:,1:] = (X_train[:,1:] - self._mean) / self._std
            X_val[:,1:] = (X_val[:,1:] - self._mean) / self._std

            # Inicializar theta y entrenar
            theta = np.zeros(X_train.shape[1])
            js = []
            for it in range(itera):
                h = X_train.dot(theta.reshape(-1,1))
                error = h - y_train.reshape(-1,1)
                grad = (1/X_train.shape[0]) * X_train.T.dot(error)
                theta = theta - alpha * grad.flatten()
                j = (1/(2*X_train.shape[0])) * np.sum(error**2)
                js.append(j)
                if it > 0 and abs(js[-1]-js[-2]) < epsilon:
                    break

            # Predecir en validation y calcular metricas
            y_pred = X_val.dot(theta.reshape(-1,1))
            y_val = y_val.reshape(-1,1)
            mse = np.mean((y_pred - y_val)**2)
            rmse = np.sqrt(mse)
            mae = np.mean(np.abs(y_pred - y_val))
            
            ss_res = np.sum((y_val - y_pred)**2)
            ss_tot = np.sum((y_val - np.mean(y_val))**2)
            r2 = 1 - ss_res/ss_tot if ss_tot != 0 else 0
            metrics['mse'][i] = mse
            metrics['rmse'][i] = rmse
            metrics['mae'][i] = mae
            metrics['r2'][i] = r2
            print(f"Fold {i+1} - MSE: {mse:.4f}, RMSE: {rmse:.4f}, MAE: {mae:.4f}, R2: {r2:.4f}")

        avg_metrics = {key: np.mean(values) for key, values in metrics.items()}
        std_metrics = {f"{key}_std": np.std(values) for key, values in metrics.items()}
        print("\n--- Resultados K-Fold Cross-Validation ---")
        print(f"MSE promedio: {avg_metrics['mse']:.4f} (+/- {std_metrics['mse_std']:.4f})")
        print(f"RMSE promedio: {avg_metrics['rmse']:.4f} (+/- {std_metrics['rmse_std']:.4f})")
        print(f"MAE promedio: {metrics['mae'].mean():.4f} (+/- {metrics['mae'].std():.4f})")
        print(f"R2 promedio: {avg_metrics['r2']:.4f} (+/- {std_metrics['r2_std']:.4f})")
        return {**avg_metrics, **std_metrics}

    # Grafica evolucion del costo
    def graficar_historial(self):
        fig1 = plt.figure()
        plt.plot(range(self.__history.size), self.__history)
        plt.grid()
        plt.xlabel("iteraciones")
        plt.ylabel("J(theta)")
        plt.title("Evolucion del costo en el descenso de gradiente")
        plt.show()

    # Imputa valores nulos y elimina columnas completamente vacias
    def manejar_nulos_seguro(self, estrategia="media"):
        X = self.__X[:, 1:]
        columnas_eliminar = []
        for i in range(X.shape[1]):
            col = X[:, i]
            mask = np.isnan(col)
            if np.all(mask):
                columnas_eliminar.append(i)
            elif np.any(mask):
                if estrategia == "media":
                    col[mask] = np.nanmean(col)
                elif estrategia == "mediana":
                    col[mask] = np.nanmedian(col)
                else:
                    raise ValueError("Estrategia no soportada")
                X[:, i] = col
        if columnas_eliminar:
            X = np.delete(X, columnas_eliminar, axis=1)
            self.__X = np.c_[np.ones(X.shape[0]), X]
        else:
            self.__X[:, 1:] = X
        print(f"Columnas eliminadas por NaN completo: {columnas_eliminar}")

    # Recorta outliers usando IQR
    def manejar_atipicos_seguro(self):
        X = self.__X[:, 1:]
        for i in range(X.shape[1]):
            q1, q3 = np.percentile(X[:, i], [25, 75])
            iqr = q3 - q1
            if iqr == 0:
                continue
            low = q1 - 1.5 * iqr
            high = q3 + 1.5 * iqr
            X[:, i] = np.clip(X[:, i], low, high)
        self.__X[:, 1:] = X

    # Pipeline de produccion
    def pipeline_produccion(self, alpha, itera, epsilon, lambd=0.0):
        """
        Ejecuta pipeline completo:
        - manejo de nulos
        - normalizacion
        - entrenamiento
        - chequeo simple de drift (si MSE test > 10% train)
        """
        self.manejar_nulos_seguro()
        self.normalizar_seguro()
        self.descenso_de_gradiente(alpha=alpha, itera=itera, epsilon=epsilon, lambd=lambd)
        mse_train = self.get_ECM(self.__X, self.__y)
        mse_test = self.get_ECM(self.__X_test, self.__y_test)
        if mse_test > mse_train * 1.10:
            print("Drift detectado: Retraining necesario")

    # Interpreta R2 en categorias simples
    def interpretar_r2(self):
        r2 = self.get_r2()
        if r2 >= 0.8:
            return "Excelente capacidad predictiva"
        elif r2 >= 0.6:
            return "Buen desempeño"
        else:
            return "Necesita mejora en features o modelo"
