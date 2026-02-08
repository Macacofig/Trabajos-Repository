import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.model_selection import train_test_split, StratifiedKFold, KFold
from sklearn.metrics import (mean_absolute_error, mean_squared_error, r2_score, 
                             accuracy_score, precision_score, recall_score, f1_score,
                             confusion_matrix, classification_report)
import pickle
import warnings
warnings.filterwarnings('ignore')

#=============================
# Mateo Figueroa
# Nataly Ramirez
# Josue Camacho
# Ostin Colque
#=============================
import sqlite3
from sklearn.preprocessing import MinMaxScaler, PolynomialFeatures
from sklearn.utils import resample

# ===============================
# Conexión y carga de tablas
# ===============================
conn = sqlite3.connect("database.sqlite")

df = pd.read_sql("SELECT * FROM Player;", conn)
df_attr = pd.read_sql("SELECT * FROM Player_Attributes;", conn)

# Convertir fecha
df_attr["date"] = pd.to_datetime(df_attr["date"])

# Seleccionar registro más reciente por jugador
df_attr_latest = df_attr.sort_values("date").groupby("player_api_id").tail(1)

# Unir tablas Player + Player_Attributes
df_players = pd.merge(df_attr_latest, df, on="player_api_id", how="inner")

# Manejo de duplicados: Eliminar columnas repetidas de la unión
df_players = df_players.drop(columns=[
    "id_x", "id_y", "player_fifa_api_id_x", "player_fifa_api_id_y"
])

# ===============================
# ===    LIMPIEZA DE DATOS    ===
# ===============================

# ===============================
# 1. Manejo de valores nulos (mediana por posición / general)
# ===============================
num_cols = df_players.select_dtypes(include="number").columns
df_players[num_cols] = df_players[num_cols].fillna(df_players[num_cols].median())

# Columnas categóricas: rellenar con modo
cat_cols = ["preferred_foot", "attacking_work_rate", "defensive_work_rate"]
for col in cat_cols:
    if col in df_players.columns:
        df_players[col] = df_players[col].fillna(df_players[col].mode()[0])

# ===============================
# 2. One-hot encoding de variables categóricas
# ===============================
df_players = pd.get_dummies(df_players, columns=cat_cols, drop_first=True)

# ===============================
# 3. Normalización de atributos numéricos
# ===============================
# Excluyendo target y variables derivadas que ya están en escala razonable
features_to_scale = [
    "crossing", "finishing", "heading_accuracy", "short_passing", "volleys",
    "curve", "free_kick_accuracy", "long_passing", "ball_control",
    "acceleration", "sprint_speed", "agility", "reactions", "balance",
    "shot_power", "jumping", "stamina", "strength", "long_shots",
    "aggression", "interceptions", "positioning", "vision",
    "penalties", "marking", "standing_tackle", "sliding_tackle",
    "gk_diving", "gk_handling", "gk_kicking", "gk_positioning", "gk_reflexes",
    "height", "weight"
]

# Filtrar solo las columnas que existen
features_to_scale = [f for f in features_to_scale if f in df_players.columns]

scaler = MinMaxScaler(feature_range=(0, 100))
df_players[features_to_scale] = scaler.fit_transform(df_players[features_to_scale])

# ===============================
# 4. Atipicos
# ===============================
num_cols = df_players.select_dtypes(include="number").columns
Q1 = df_players[num_cols].quantile(0.25)
Q3 = df_players[num_cols].quantile(0.75)
IQR = Q3 - Q1

df_players = df_players[~((df_players[num_cols] < (Q1 - 1.75 * IQR)) |
                           (df_players[num_cols] > (Q3 + 1.75 * IQR))).any(axis=1)]

# ===============================
# ===   DERIVAR VARIABLES     ===
# ===============================

# ===============================
# SCORE FISICO : Acceleration, Sprint Speed, Stamina, Strength
# ===============================
physical_features = [f for f in ["acceleration", "sprint_speed", "stamina", "strength"] 
                     if f in df_players.columns]
if physical_features:
    df_players["score_fisico"] = df_players[physical_features].mean(axis=1)
else:
    df_players["score_fisico"] = 50  # Valor por defecto

# ===============================
# SCORE TECNICO: ball_control, dribbling, short_passing
# ===============================
technical_features = [f for f in ["ball_control", "dribbling", "short_passing"] 
                      if f in df_players.columns]
if technical_features:
    df_players["score_tecnico"] = df_players[technical_features].mean(axis=1)
else:
    df_players["score_tecnico"] = 50  # Valor por defecto

# ===============================
# SCORE MENTAL: positioning, vision, reactions
# ===============================
mental_features = [f for f in ["positioning", "vision", "reactions"] 
                   if f in df_players.columns]
if mental_features:
    df_players["score_mental"] = df_players[mental_features].mean(axis=1)
else:
    df_players["score_mental"] = 50  # Valor por defecto

# ===============================
# EDAD
# ===============================
df_players["birthday"] = pd.to_datetime(df_players["birthday"])
df_players["edad"] = (
    (df_players["date"] - df_players["birthday"]).dt.days // 365
)

# ============================================================================
# 1. PREPARACIÓN DE DATOS PARA REDES NEURONALES
# ============================================================================

def preparar_datos_para_redes(df_players):
    """
    Prepara los datos específicamente para las redes neuronales del Día 2.
    """
    # Crear características derivadas adicionales para redes neuronales
    df_players['potential_diff'] = df_players['potential'] - df_players['overall_rating']
    
    # Attack score
    attack_features = [f for f in ['finishing', 'shot_power', 'long_shots'] 
                       if f in df_players.columns]
    if attack_features:
        df_players['attack_score'] = df_players[attack_features].mean(axis=1)
    else:
        df_players['attack_score'] = 50
    
    # Defense score
    defense_features = [f for f in ['marking', 'standing_tackle', 'sliding_tackle'] 
                        if f in df_players.columns]
    if defense_features:
        df_players['defense_score'] = df_players[defense_features].mean(axis=1)
    else:
        df_players['defense_score'] = 50
    
    # Speed score
    speed_features = [f for f in ['acceleration', 'sprint_speed', 'agility'] 
                      if f in df_players.columns]
    if speed_features:
        df_players['speed_score'] = df_players[speed_features].mean(axis=1)
    else:
        df_players['speed_score'] = 50
    
    return df_players

# Preparar datos
df_players = preparar_datos_para_redes(df_players)

# ============================================================================
# 2. RED NEURONAL 1: PREDICCIÓN DE POTENCIAL MÁXIMO (REGRESIÓN)
# ============================================================================

class NeuralNetworkRegressor:
    """
    Red Neuronal para Regresión - Potencial Máximo
    Arquitectura: 20-256-128-64-1 neuronas
    Activaciones: ReLU en capas ocultas, lineal en salida
    """
    
    def __init__(self, layer_sizes=[20, 256, 128, 64, 1], 
                 learning_rate=0.001, 
                 lambda_reg=0.01,
                 n_iter=1000,
                 batch_size=32,
                 verbose=True):
        
        self.layer_sizes = layer_sizes
        self.learning_rate = learning_rate
        self.lambda_reg = lambda_reg  # Parámetro de regularización L2
        self.n_iter = n_iter
        self.batch_size = batch_size
        self.verbose = verbose
        self.parameters = {}
        self.costs = []
        self.val_costs = []
        self.initialize_parameters()
    
    def initialize_parameters(self):
        """Inicialización Xavier/Glorot con regularización"""
        for l in range(1, len(self.layer_sizes)):
            scale = np.sqrt(2.0 / (self.layer_sizes[l-1] + self.layer_sizes[l]))
            self.parameters[f'W{l}'] = np.random.randn(
                self.layer_sizes[l], self.layer_sizes[l-1]) * scale
            self.parameters[f'b{l}'] = np.zeros((self.layer_sizes[l], 1))
    
    def relu(self, Z):
        return np.maximum(0, Z)
    
    def relu_derivative(self, Z):
        return (Z > 0).astype(float)
    
    def linear(self, Z):
        return Z
    
    def linear_derivative(self, Z):
        return np.ones_like(Z)
    
    def forward_propagation(self, X):
        """Forward propagation para regresión"""
        cache = {'A0': X}
        A = X
        L = len(self.layer_sizes) - 1
        
        # Capas ocultas (ReLU)
        for l in range(1, L):
            Z = self.parameters[f'W{l}'].dot(A) + self.parameters[f'b{l}']
            A = self.relu(Z)
            cache[f'Z{l}'] = Z
            cache[f'A{l}'] = A
        
        # Capa de salida (Lineal)
        Z = self.parameters[f'W{L}'].dot(A) + self.parameters[f'b{L}']
        A = self.linear(Z)
        cache[f'Z{L}'] = Z
        cache[f'A{L}'] = A
        
        return A, cache
    
    def compute_cost(self, AL, Y):
        """Costo MSE con regularización L2"""
        m = Y.shape[1]
        mse = np.mean((AL - Y) ** 2)
        
        # Regularización L2
        reg_cost = 0
        L = len(self.layer_sizes) - 1
        for l in range(1, L+1):
            reg_cost += np.sum(self.parameters[f'W{l}'] ** 2)
        
        total_cost = mse + (self.lambda_reg / (2 * m)) * reg_cost
        return total_cost
    
    def backward_propagation(self, AL, Y, cache):
        """Backpropagation para regresión"""
        m = Y.shape[1]
        L = len(self.layer_sizes) - 1
        grads = {}
        
        # Gradiente capa de salida (lineal)
        dZ = AL - Y
        grads[f'dW{L}'] = dZ.dot(cache[f'A{L-1}'].T) / m + (self.lambda_reg / m) * self.parameters[f'W{L}']
        grads[f'db{L}'] = np.sum(dZ, axis=1, keepdims=True) / m
        grads[f'dZ{L}'] = dZ
        
        # Capas ocultas (ReLU)
        for l in reversed(range(1, L)):
            dA = self.parameters[f'W{l+1}'].T.dot(grads[f'dZ{l+1}'])
            dZ = dA * self.relu_derivative(cache[f'Z{l}'])
            
            grads[f'dW{l}'] = dZ.dot(cache[f'A{l-1}'].T) / m + (self.lambda_reg / m) * self.parameters[f'W{l}']
            grads[f'db{l}'] = np.sum(dZ, axis=1, keepdims=True) / m
            grads[f'dZ{l}'] = dZ
        
        return grads
    
    def update_parameters(self, grads):
        """Actualizar parámetros con Adam optimizer simplificado"""
        L = len(self.layer_sizes) - 1
        for l in range(1, L+1):
            self.parameters[f'W{l}'] -= self.learning_rate * grads[f'dW{l}']
            self.parameters[f'b{l}'] -= self.learning_rate * grads[f'db{l}']
    
    def fit(self, X, y, X_val=None, y_val=None):
        """Entrenamiento con mini-batches y validación"""
        if self.verbose:
            print("\n" + "="*60)
            print("ENTRENANDO RED NEURONAL - PREDICCIÓN DE POTENCIAL")
            print("="*60)
        
        X = X.T
        y = y.reshape(1, -1)
        
        if X_val is not None:
            X_val = X_val.T
            y_val = y_val.reshape(1, -1)
        
        m = X.shape[1]
        self.costs = []
        self.val_costs = []
        
        for i in range(self.n_iter):
            # Mini-batch training
            indices = np.random.permutation(m)
            X_shuffled = X[:, indices]
            y_shuffled = y[:, indices]
            
            for start in range(0, m, self.batch_size):
                end = min(start + self.batch_size, m)
                X_batch = X_shuffled[:, start:end]
                y_batch = y_shuffled[:, start:end]
                
                # Forward
                AL, cache = self.forward_propagation(X_batch)
                
                # Costo
                cost = self.compute_cost(AL, y_batch)
                
                # Backward
                grads = self.backward_propagation(AL, y_batch, cache)
                
                # Update
                self.update_parameters(grads)
            
            # Costo en conjunto completo
            AL_full, _ = self.forward_propagation(X)
            train_cost = self.compute_cost(AL_full, y)
            self.costs.append(train_cost)
            
            # Validación
            if X_val is not None:
                AL_val, _ = self.forward_propagation(X_val)
                val_cost = self.compute_cost(AL_val, y_val)
                self.val_costs.append(val_cost)
            
            if self.verbose and i % 100 == 0:
                if X_val is not None:
                    print(f"  Época {i}: Costo entrenamiento = {train_cost:.4f}, "
                          f"Costo validación = {val_cost:.4f}")
                else:
                    print(f"  Época {i}: Costo = {train_cost:.4f}")
        
        if self.verbose:
            print("Entrenamiento completado")
    
    def predict(self, X):
        """Predecir potencial"""
        X = X.T
        AL, _ = self.forward_propagation(X)
        return AL.flatten()
    
    def evaluate_regression(self, X, y):
        """Evaluar métricas de regresión"""
        predictions = self.predict(X)
        
        mae = mean_absolute_error(y, predictions)
        rmse = np.sqrt(mean_squared_error(y, predictions))
        r2 = r2_score(y, predictions)
        max_error = np.max(np.abs(y - predictions))
        
        metrics = {
            'MAE': mae,
            'RMSE': rmse,
            'R²': r2,
            'Max Error': max_error
        }
        
        return metrics, predictions

# ============================================================================
# 3. RED NEURONAL 2: CLASIFICACIÓN DE PERFIL DE JUGADOR
# ============================================================================

class NeuralNetworkClassifier:
    """
    Red Neuronal para Clasificación - Perfil de Jugador
    Arquitectura: 15-256-128-7 neuronas
    Activaciones: ReLU en capas ocultas, Softmax en salida
    """
    
    def __init__(self, layer_sizes=[15, 256, 128, 7], 
                 learning_rate=0.001,
                 lambda_reg=0.01,
                 n_iter=1000,
                 batch_size=32,
                 verbose=True):
        
        self.layer_sizes = layer_sizes
        self.learning_rate = learning_rate
        self.lambda_reg = lambda_reg
        self.n_iter = n_iter
        self.batch_size = batch_size
        self.verbose = verbose
        self.parameters = {}
        self.costs = []
        self.val_costs = []
        self.val_accuracies = []
        self.initialize_parameters()
    
    def initialize_parameters(self):
        """Inicialización Xavier/Glorot"""
        for l in range(1, len(self.layer_sizes)):
            scale = np.sqrt(2.0 / (self.layer_sizes[l-1] + self.layer_sizes[l]))
            self.parameters[f'W{l}'] = np.random.randn(
                self.layer_sizes[l], self.layer_sizes[l-1]) * scale
            self.parameters[f'b{l}'] = np.zeros((self.layer_sizes[l], 1))
    
    def relu(self, Z):
        return np.maximum(0, Z)
    
    def relu_derivative(self, Z):
        return (Z > 0).astype(float)
    
    def softmax(self, Z):
        exp_Z = np.exp(Z - np.max(Z, axis=0, keepdims=True))
        return exp_Z / np.sum(exp_Z, axis=0, keepdims=True)
    
    def forward_propagation(self, X):
        """Forward propagation para clasificación"""
        cache = {'A0': X}
        A = X
        L = len(self.layer_sizes) - 1
        
        # Capas ocultas (ReLU)
        for l in range(1, L):
            Z = self.parameters[f'W{l}'].dot(A) + self.parameters[f'b{l}']
            A = self.relu(Z)
            cache[f'Z{l}'] = Z
            cache[f'A{l}'] = A
        
        # Capa de salida (Softmax)
        Z = self.parameters[f'W{L}'].dot(A) + self.parameters[f'b{L}']
        A = self.softmax(Z)
        cache[f'Z{L}'] = Z
        cache[f'A{L}'] = A
        
        return A, cache
    
    def compute_cost(self, AL, Y):
        """Costo de entropía cruzada con regularización L2"""
        m = Y.shape[1]
        cross_entropy = -np.sum(Y * np.log(AL + 1e-8)) / m
        
        # Regularización L2
        reg_cost = 0
        L = len(self.layer_sizes) - 1
        for l in range(1, L+1):
            reg_cost += np.sum(self.parameters[f'W{l}'] ** 2)
        
        total_cost = cross_entropy + (self.lambda_reg / (2 * m)) * reg_cost
        return total_cost
    
    def backward_propagation(self, AL, Y, cache):
        """Backpropagation para clasificación"""
        m = Y.shape[1]
        L = len(self.layer_sizes) - 1
        grads = {}
        
        # Gradiente capa de salida (softmax)
        dZ = AL - Y
        grads[f'dW{L}'] = dZ.dot(cache[f'A{L-1}'].T) / m + (self.lambda_reg / m) * self.parameters[f'W{L}']
        grads[f'db{L}'] = np.sum(dZ, axis=1, keepdims=True) / m
        grads[f'dZ{L}'] = dZ
        
        # Capas ocultas (ReLU)
        for l in reversed(range(1, L)):
            dA = self.parameters[f'W{l+1}'].T.dot(grads[f'dZ{l+1}'])
            dZ = dA * self.relu_derivative(cache[f'Z{l}'])
            
            grads[f'dW{l}'] = dZ.dot(cache[f'A{l-1}'].T) / m + (self.lambda_reg / m) * self.parameters[f'W{l}']
            grads[f'db{l}'] = np.sum(dZ, axis=1, keepdims=True) / m
            grads[f'dZ{l}'] = dZ
        
        return grads
    
    def update_parameters(self, grads):
        """Actualizar parámetros"""
        L = len(self.layer_sizes) - 1
        for l in range(1, L+1):
            self.parameters[f'W{l}'] -= self.learning_rate * grads[f'dW{l}']
            self.parameters[f'b{l}'] -= self.learning_rate * grads[f'db{l}']
    
    def fit(self, X, y, X_val=None, y_val=None):
        """Entrenamiento con validación"""
        if self.verbose:
            print("\n" + "="*60)
            print("ENTRENANDO RED NEURONAL - CLASIFICACIÓN DE PERFIL")
            print("="*60)
        
        X = X.T
        n_classes = self.layer_sizes[-1]
        
        # One-hot encoding
        Y = np.zeros((n_classes, X.shape[1]))
        Y[y, np.arange(X.shape[1])] = 1
        
        if X_val is not None:
            X_val_t = X_val.T
            Y_val = np.zeros((n_classes, X_val.shape[0]))
            Y_val[y_val, np.arange(X_val.shape[0])] = 1
        
        m = X.shape[1]
        self.costs = []
        self.val_costs = []
        self.val_accuracies = []
        
        for i in range(self.n_iter):
            # Mini-batch training
            indices = np.random.permutation(m)
            X_shuffled = X[:, indices]
            Y_shuffled = Y[:, indices]
            
            for start in range(0, m, self.batch_size):
                end = min(start + self.batch_size, m)
                X_batch = X_shuffled[:, start:end]
                Y_batch = Y_shuffled[:, start:end]
                
                # Forward
                AL, cache = self.forward_propagation(X_batch)
                
                # Costo
                cost = self.compute_cost(AL, Y_batch)
                
                # Backward
                grads = self.backward_propagation(AL, Y_batch, cache)
                
                # Update
                self.update_parameters(grads)
            
            # Costo en conjunto completo
            AL_full, _ = self.forward_propagation(X)
            train_cost = self.compute_cost(AL_full, Y)
            self.costs.append(train_cost)
            
            # Validación
            if X_val is not None:
                AL_val, _ = self.forward_propagation(X_val_t)
                val_cost = self.compute_cost(AL_val, Y_val)
                self.val_costs.append(val_cost)
                
                # Accuracy en validación
                y_pred_val = np.argmax(AL_val, axis=0)
                val_acc = accuracy_score(y_val, y_pred_val)
                self.val_accuracies.append(val_acc)
            
            if self.verbose and i % 100 == 0:
                if X_val is not None:
                    print(f"  Época {i}: Costo entrenamiento = {train_cost:.4f}, "
                          f"Costo validación = {val_cost:.4f}, "
                          f"Accuracy validación = {val_acc:.4f}")
                else:
                    print(f"  Época {i}: Costo = {train_cost:.4f}")
        
        if self.verbose:
            print("Entrenamiento completado")
    
    def predict(self, X):
        """Predecir clases"""
        X = X.T
        AL, _ = self.forward_propagation(X)
        return np.argmax(AL, axis=0)
    
    def predict_proba(self, X):
        """Predecir probabilidades"""
        X = X.T
        AL, _ = self.forward_propagation(X)
        return AL.T
    
    def evaluate_classification(self, X, y):
        """Evaluar métricas de clasificación"""
        predictions = self.predict(X)
        probabilities = self.predict_proba(X)
        
        accuracy = accuracy_score(y, predictions)
        precision = precision_score(y, predictions, average='weighted')
        recall = recall_score(y, predictions, average='weighted')
        f1 = f1_score(y, predictions, average='weighted')
        
        # Matriz de confusión
        cm = confusion_matrix(y, predictions)
        
        metrics = {
            'Accuracy': accuracy,
            'Precision': precision,
            'Recall': recall,
            'F1-Score': f1,
            'Confusion Matrix': cm
        }
        
        return metrics, predictions, probabilities

# ============================================================================
# 4. PREPARACIÓN ESPECÍFICA PARA CADA RED
# ============================================================================

def preparar_datos_red1(df_players):
    """Preparar datos para Red 1: Predicción de Potencial"""
    # Características para Red 1
    features_red1 = [
        'overall_rating',
        'score_fisico',
        'score_tecnico', 
        'score_mental',
        'attack_score',
        'defense_score',
        'speed_score',
        'height',
        'weight',
        'edad',
        'potential_diff',
        'crossing',
        'finishing',
        'heading_accuracy',
        'short_passing',
        'volleys',
        'dribbling',
        'curve',
        'free_kick_accuracy',
        'long_passing'
    ]
    
    # Verificar qué características existen realmente
    features_red1 = [f for f in features_red1 if f in df_players.columns]
    
    # Asegurar que tenemos exactamente 20 características
    # Si faltan, usar alternativas
    if len(features_red1) < 20:
        # Agregar características alternativas
        additional_features = [
            'ball_control', 'acceleration', 'sprint_speed', 'agility',
            'reactions', 'balance', 'shot_power', 'jumping', 'stamina',
            'strength', 'long_shots', 'aggression', 'interceptions',
            'positioning', 'vision', 'penalties', 'marking',
            'standing_tackle', 'sliding_tackle'
        ]
        
        # Filtrar solo las que existen y no están ya incluidas
        available_additional = [f for f in additional_features 
                              if f in df_players.columns and f not in features_red1]
        
        # Agregar hasta completar 20
        needed = 20 - len(features_red1)
        features_red1.extend(available_additional[:needed])
    
    print(f"\nRed 1 usando {len(features_red1)} características:")
    print(features_red1)
    
    data = df_players[features_red1 + ['potential']].dropna()
    X = data[features_red1].values
    y = data['potential'].values
    
    # Verificar que tenemos datos
    if len(data) == 0:
        raise ValueError("No hay datos después de eliminar valores nulos para Red 1")
    
    # Normalización
    scaler = StandardScaler()
    X = scaler.fit_transform(X)
    
    return X, y, scaler, features_red1

def preparar_datos_red2(df_players):
    """Preparar datos para Red 2: Clasificación de Perfil"""
    # Definir 7 perfiles de jugador basados en atributos
    def definir_perfil(row):
        # Verificar qué características existen
        available_features = df_players.columns
        
        # Crear scores para diferentes tipos de jugadores
        scores = {}
        
        # Portero
        gk_features = ['gk_diving', 'gk_handling', 'gk_kicking', 'gk_positioning', 'gk_reflexes']
        gk_features = [f for f in gk_features if f in available_features]
        if gk_features:
            scores['Goalkeeper'] = row[gk_features].mean()
        
        # Defensa central
        cd_features = ['marking', 'standing_tackle', 'sliding_tackle', 'interceptions', 'strength']
        cd_features = [f for f in cd_features if f in available_features]
        if cd_features:
            scores['Central Defender'] = row[cd_features].mean()
        
        # Lateral
        fb_features = ['crossing', 'stamina', 'sprint_speed', 'standing_tackle']
        fb_features = [f for f in fb_features if f in available_features]
        if fb_features:
            scores['Full Back'] = row[fb_features].mean()
        
        # Medio defensivo
        dm_features = ['short_passing', 'interceptions', 'standing_tackle', 'stamina']
        dm_features = [f for f in dm_features if f in available_features]
        if dm_features:
            scores['Defensive Midfielder'] = row[dm_features].mean()
        
        # Medio centro
        cm_features = ['short_passing', 'long_passing', 'ball_control', 'vision']
        cm_features = [f for f in cm_features if f in available_features]
        if cm_features:
            scores['Central Midfielder'] = row[cm_features].mean()
        
        # Medio ofensivo
        am_features = ['dribbling', 'ball_control', 'vision', 'short_passing']
        am_features = [f for f in am_features if f in available_features]
        if am_features:
            scores['Attacking Midfielder'] = row[am_features].mean()
        
        # Delantero
        fw_features = ['finishing', 'shot_power', 'dribbling', 'positioning']
        fw_features = [f for f in fw_features if f in available_features]
        if fw_features:
            scores['Forward'] = row[fw_features].mean()
        
        # Si no hay scores, usar una categoría por defecto
        if not scores:
            return 'Central Midfielder'
        
        return max(scores, key=scores.get)
    
    # Aplicar definición de perfil
    df_players['player_profile'] = df_players.apply(definir_perfil, axis=1)
    
    # Características para Red 2 (15 características)
    # Primero, definir todas las posibles características
    all_possible_features = [
        'score_fisico',
        'score_tecnico',
        'score_mental',
        'attack_score',
        'defense_score',
        'speed_score',
        'height',
        'weight',
        'edad',
        'overall_rating',
        'potential',
        'reactions',
        'balance',
        'agility',
        'composure',  # Si existe
        'stamina',    # Alternativa si no existe composure
        'strength',   # Alternativa
        'positioning',# Alternativa
        'vision'      # Alternativa
    ]
    
    # Filtrar solo las características que existen
    features_red2 = [f for f in all_possible_features if f in df_players.columns]
    
    # Tomar solo 15 características (o menos si no hay suficientes)
    features_red2 = features_red2[:15]
    
    print(f"\nRed 2 usando {len(features_red2)} características:")
    print(features_red2)
    
    data = df_players[features_red2 + ['player_profile']].dropna()
    
    # Verificar que tenemos datos
    if len(data) == 0:
        raise ValueError("No hay datos después de eliminar valores nulos para Red 2")
    
    # Codificar etiquetas
    le = LabelEncoder()
    y = le.fit_transform(data['player_profile'])
    
    X = data[features_red2].values
    
    # Normalización
    scaler = StandardScaler()
    X = scaler.fit_transform(X)
    
    return X, y, scaler, le, features_red2

# ============================================================================
# 5. ENTRENAMIENTO Y VALIDACIÓN
# ============================================================================

def entrenar_y_evaluar_redes(df_players):
    """Función principal para entrenar y evaluar ambas redes"""
    
    print("="*80)
    print("INICIANDO ENTRENAMIENTO DE REDES NEURONALES - DÍA 2")
    print("="*80)
    
    # ========================================================================
    # RED 1: PREDICCIÓN DE POTENCIAL
    # ========================================================================
    
    print("\n" + "="*60)
    print("RED 1: PREDICCIÓN DE POTENCIAL MÁXIMO")
    print("="*60)
    
    # Preparar datos
    X1, y1, scaler1, features1 = preparar_datos_red1(df_players)
    
    # Actualizar la arquitectura de la Red 1 con el número real de características
    n_features1 = len(features1)
    red1_layer_sizes = [n_features1, 256, 128, 64, 1]
    
    print(f"\nArquitectura Red 1: {red1_layer_sizes}")
    
    # División de datos (70-15-15)
    X1_train, X1_temp, y1_train, y1_temp = train_test_split(
        X1, y1, test_size=0.3, random_state=42
    )
    X1_val, X1_test, y1_val, y1_test = train_test_split(
        X1_temp, y1_temp, test_size=0.5, random_state=42
    )
    
    # Crear y entrenar red 1
    red1 = NeuralNetworkRegressor(
        layer_sizes=red1_layer_sizes,
        learning_rate=0.001,
        lambda_reg=0.01,
        n_iter=500,
        batch_size=64,
        verbose=True
    )
    
    red1.fit(X1_train, y1_train, X1_val, y1_val)
    
    # Evaluar en test
    metrics1, predictions1 = red1.evaluate_regression(X1_test, y1_test)
    
    print("\nMétricas de evaluación - Red 1:")
    for metric, value in metrics1.items():
        if metric != 'Confusion Matrix':
            print(f"  {metric}: {value:.4f}")
    
    # ========================================================================
    # RED 2: CLASIFICACIÓN DE PERFIL
    # ========================================================================
    
    print("\n" + "="*60)
    print("RED 2: CLASIFICACIÓN DE PERFIL DE JUGADOR")
    print("="*60)
    
    # Preparar datos
    X2, y2, scaler2, le2, features2 = preparar_datos_red2(df_players)
    
    # Actualizar la arquitectura de la Red 2
    n_features2 = len(features2)
    n_classes = len(np.unique(y2))
    red2_layer_sizes = [n_features2, 256, 128, n_classes]
    
    print(f"\nArquitectura Red 2: {red2_layer_sizes}")
    print(f"Número de clases: {n_classes}")
    print(f"Clases: {le2.classes_}")
    
    # División estratificada
    X2_train, X2_temp, y2_train, y2_temp = train_test_split(
        X2, y2, test_size=0.3, random_state=42, stratify=y2
    )
    X2_val, X2_test, y2_val, y2_test = train_test_split(
        X2_temp, y2_temp, test_size=0.5, random_state=42, stratify=y2_temp
    )
    
    # Crear y entrenar red 2
    red2 = NeuralNetworkClassifier(
        layer_sizes=red2_layer_sizes,
        learning_rate=0.001,
        lambda_reg=0.01,
        n_iter=500,
        batch_size=64,
        verbose=True
    )
    
    red2.fit(X2_train, y2_train, X2_val, y2_val)
    
    # Evaluar en test
    metrics2, predictions2, probas2 = red2.evaluate_classification(X2_test, y2_test)
    
    print("\nMétricas de evaluación - Red 2:")
    for metric, value in metrics2.items():
        if metric != 'Confusion Matrix':
            print(f"  {metric}: {value:.4f}")
    
    # Reporte de clasificación detallado
    print("\nReporte de Clasificación:")
    print(classification_report(y2_test, predictions2, 
                                target_names=le2.classes_))
    
    return red1, red2, metrics1, metrics2, (X1_test, y1_test), (X2_test, y2_test)

# ============================================================================
# 6. VALIDACIÓN CRUZADA
# ============================================================================

def validacion_cruzada_completa(df_players, k_folds=5):
    """Realizar validación cruzada para ambas redes"""
    
    print("\n" + "="*60)
    print(f"VALIDACIÓN CRUZADA ({k_folds}-FOLD)")
    print("="*60)
    
    # Preparar datos para Red 1
    X1, y1, _, features1 = preparar_datos_red1(df_players)
    n_features1 = len(features1)
    
    # K-Fold para regresión
    kf = KFold(n_splits=k_folds, shuffle=True, random_state=42)
    fold_results_red1 = []
    
    print("\nValidación Cruzada - Red 1 (Regresión):")
    for fold, (train_idx, val_idx) in enumerate(kf.split(X1)):
        X_train, X_val = X1[train_idx], X1[val_idx]
        y_train, y_val = y1[train_idx], y1[val_idx]
        
        red = NeuralNetworkRegressor(
            layer_sizes=[n_features1, 256, 128, 64, 1],
            learning_rate=0.001,
            lambda_reg=0.01,
            n_iter=300,
            batch_size=64,
            verbose=False
        )
        
        red.fit(X_train, y_train)
        metrics, _ = red.evaluate_regression(X_val, y_val)
        fold_results_red1.append(metrics)
        
        print(f"  Fold {fold+1}: R² = {metrics['R²']:.4f}, RMSE = {metrics['RMSE']:.4f}")
    
    # Calcular promedios
    avg_metrics_red1 = {}
    for metric in fold_results_red1[0].keys():
        if metric != 'Confusion Matrix':
            avg_metrics_red1[metric] = np.mean([res[metric] for res in fold_results_red1])
    
    print(f"\nPromedio {k_folds}-fold - Red 1:")
    for metric, value in avg_metrics_red1.items():
        print(f"  {metric}: {value:.4f}")
    
    # Preparar datos para Red 2
    X2, y2, _, le2, features2 = preparar_datos_red2(df_players)
    n_features2 = len(features2)
    n_classes = len(le2.classes_)
    
    # Stratified K-Fold para clasificación
    skf = StratifiedKFold(n_splits=k_folds, shuffle=True, random_state=42)
    fold_results_red2 = []
    
    print("\nValidación Cruzada - Red 2 (Clasificación):")
    for fold, (train_idx, val_idx) in enumerate(skf.split(X2, y2)):
        X_train, X_val = X2[train_idx], X2[val_idx]
        y_train, y_val = y2[train_idx], y2[val_idx]
        
        red = NeuralNetworkClassifier(
            layer_sizes=[n_features2, 256, 128, n_classes],
            learning_rate=0.001,
            lambda_reg=0.01,
            n_iter=300,
            batch_size=64,
            verbose=False
        )
        
        red.fit(X_train, y_train)
        metrics, _, _ = red.evaluate_classification(X_val, y_val)
        fold_results_red2.append(metrics)
        
        print(f"  Fold {fold+1}: Accuracy = {metrics['Accuracy']:.4f}, F1 = {metrics['F1-Score']:.4f}")
    
    # Calcular promedios
    avg_metrics_red2 = {}
    for metric in fold_results_red2[0].keys():
        if metric != 'Confusion Matrix':
            avg_metrics_red2[metric] = np.mean([res[metric] for res in fold_results_red2])
    
    print(f"\nPromedio {k_folds}-fold - Red 2:")
    for metric, value in avg_metrics_red2.items():
        print(f"  {metric}: {value:.4f}")
    
    return avg_metrics_red1, avg_metrics_red2

# ============================================================================
# 7. VISUALIZACIONES Y ANÁLISIS
# ============================================================================

def visualizar_resultados(red1, red2, metrics1, metrics2, test_data1, test_data2):
    """Crear visualizaciones para los resultados"""
    
    X1_test, y1_test = test_data1
    X2_test, y2_test = test_data2
    
    fig, axes = plt.subplots(2, 3, figsize=(15, 10))
    
    # 1. Costo durante entrenamiento - Red 1
    axes[0, 0].plot(red1.costs, label='Entrenamiento')
    if red1.val_costs:
        axes[0, 0].plot(red1.val_costs, label='Validación')
    axes[0, 0].set_title('Red 1: Costo durante entrenamiento')
    axes[0, 0].set_xlabel('Época')
    axes[0, 0].set_ylabel('Costo (MSE)')
    axes[0, 0].legend()
    axes[0, 0].grid(True, alpha=0.3)
    
    # 2. Predicciones vs Real - Red 1
    predictions1 = red1.predict(X1_test)
    axes[0, 1].scatter(y1_test, predictions1, alpha=0.5)
    axes[0, 1].plot([y1_test.min(), y1_test.max()], 
                    [y1_test.min(), y1_test.max()], 'r--', lw=2)
    axes[0, 1].set_title('Red 1: Predicciones vs Valores Reales')
    axes[0, 1].set_xlabel('Valor Real (Potencial)')
    axes[0, 1].set_ylabel('Predicción')
    axes[0, 1].grid(True, alpha=0.3)
    
    # 3. Residuos - Red 1
    residuals1 = y1_test - predictions1
    axes[0, 2].hist(residuals1, bins=50, edgecolor='black')
    axes[0, 2].set_title('Red 1: Distribución de Residuos')
    axes[0, 2].set_xlabel('Residuo')
    axes[0, 2].set_ylabel('Frecuencia')
    axes[0, 2].grid(True, alpha=0.3)
    
    # 4. Costo durante entrenamiento - Red 2
    axes[1, 0].plot(red2.costs, label='Entrenamiento')
    if red2.val_costs:
        axes[1, 0].plot(red2.val_costs, label='Validación')
    axes[1, 0].set_title('Red 2: Costo durante entrenamiento')
    axes[1, 0].set_xlabel('Época')
    axes[1, 0].set_ylabel('Costo (Cross-Entropy)')
    axes[1, 0].legend()
    axes[1, 0].grid(True, alpha=0.3)
    
    # 5. Accuracy durante entrenamiento - Red 2
    if red2.val_accuracies:
        axes[1, 1].plot(red2.val_accuracies, label='Validación', color='orange')
        axes[1, 1].set_title('Red 2: Accuracy durante entrenamiento')
        axes[1, 1].set_xlabel('Época')
        axes[1, 1].set_ylabel('Accuracy')
        axes[1, 1].legend()
        axes[1, 1].grid(True, alpha=0.3)
    
    # 6. Matriz de confusión - Red 2
    predictions2 = red2.predict(X2_test)
    cm = confusion_matrix(y2_test, predictions2)
    im = axes[1, 2].imshow(cm, interpolation='nearest', cmap=plt.cm.Blues)
    axes[1, 2].set_title('Red 2: Matriz de Confusión')
    
    plt.tight_layout()
    plt.show()
    
    # Métricas comparativas
    fig, axes = plt.subplots(1, 2, figsize=(12, 5))
    
    # Métricas Red 1
    metrics_red1 = ['MAE', 'RMSE', 'R²']
    values_red1 = [metrics1[m] for m in metrics_red1]
    axes[0].bar(metrics_red1, values_red1, color=['blue', 'green', 'red'])
    axes[0].set_title('Métricas de Regresión (Red 1)')
    axes[0].set_ylabel('Valor')
    axes[0].grid(True, alpha=0.3, axis='y')
    
    # Anotar valores en barras
    for i, v in enumerate(values_red1):
        axes[0].text(i, v + 0.01, f'{v:.3f}', ha='center')
    
    # Métricas Red 2
    metrics_red2 = ['Accuracy', 'Precision', 'Recall', 'F1-Score']
    values_red2 = [metrics2[m] for m in metrics_red2]
    axes[1].bar(metrics_red2, values_red2, color=['blue', 'green', 'orange', 'red'])
    axes[1].set_title('Métricas de Clasificación (Red 2)')
    axes[1].set_ylabel('Valor')
    axes[1].grid(True, alpha=0.3, axis='y')
    
    # Anotar valores en barras
    for i, v in enumerate(values_red2):
        axes[1].text(i, v + 0.01, f'{v:.3f}', ha='center')
    
    plt.tight_layout()
    plt.show()

# ============================================================================
# 8. GUARDAR MODELOS
# ============================================================================

def guardar_modelos(red1, red2, filename='modelos_redes.pkl'):
    """Guardar modelos entrenados"""
    modelos = {
        'red1_potencial': red1,
        'red2_perfil': red2
    }
    
    with open(filename, 'wb') as f:
        pickle.dump(modelos, f)
    
    print(f"\nModelos guardados en {filename}")

# ============================================================================
# 9. EJECUCIÓN PRINCIPAL
# ============================================================================

if __name__ == "__main__":
    try:
        # Ejecutar entrenamiento completo
        print("Iniciando entrenamiento de redes neuronales...")
        red1, red2, metrics1, metrics2, test_data1, test_data2 = entrenar_y_evaluar_redes(df_players)
        
        # Validación cruzada
        avg_metrics1, avg_metrics2 = validacion_cruzada_completa(df_players, k_folds=5)
        
        # Visualizaciones
        visualizar_resultados(red1, red2, metrics1, metrics2, test_data1, test_data2)
        
        # Guardar modelos
        guardar_modelos(red1, red2)
        
        # Reporte final
        print("\n" + "="*80)
        print("RESUMEN FINAL - DIA 2")
        print("="*80)
        
        print("\nRED 1 - Predicción de Potencial:")
        print("-" * 40)
        print(f"Arquitectura: {red1.layer_sizes}")
        print(f"Tasa de aprendizaje: {red1.learning_rate}")
        print(f"Regularización lambda: {red1.lambda_reg}")
        print(f"Epocas: {red1.n_iter}")
        print(f"Batch size: {red1.batch_size}")
        
        print("\nMétricas finales en test:")
        for metric, value in metrics1.items():
            if metric != 'Confusion Matrix':
                print(f"  {metric}: {value:.4f}")
        
        print("\nRED 2 - Clasificación de Perfil:")
        print("-" * 40)
        print(f"Arquitectura: {red2.layer_sizes}")
        print(f"Tasa de aprendizaje: {red2.learning_rate}")
        print(f"Regularización lambda: {red2.lambda_reg}")
        print(f"Épocas: {red2.n_iter}")
        print(f"Batch size: {red2.batch_size}")
        
        print("\nMétricas finales en test:")
        for metric, value in metrics2.items():
            if metric != 'Confusion Matrix':
                print(f"  {metric}: {value:.4f}")
        
        print("\n" + "="*80)
        print("ENTREGABLES COMPLETADOS:")
        print("="*80)
        print("2 redes neuronales entrenadas y guardadas")
        print("Reporte completo de métricas de evaluación")
        print("Validación cruzada (K-Fold)")
        print("Visualizaciones de resultados")
        print("Análisis comparativo con modelos baseline")
        
    except Exception as e:
        print(f"\nError durante la ejecución: {str(e)}")
        import traceback
        traceback.print_exc()