#=============================
# Mateo Figueroa
# Nataly Ramirez
# Josue Camacho
# Ostin Colque
#=============================
import numpy as np
import sqlite3
import pandas as pd
from sklearn.preprocessing import MinMaxScaler, PolynomialFeatures
from sklearn.utils import resample
from sklearn.metrics import confusion_matrix, classification_report
from scipy.stats import shapiro
import scipy.stats as stats
import statsmodels.api as sm
from statsmodels.stats.diagnostic import het_breuschpagan
from statsmodels.stats.outliers_influence import variance_inflation_factor
import matplotlib.pyplot as plt
from RegresionLineal import Regresion
from RegresionLogistica import LogisticRegressionOvR

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

scaler = MinMaxScaler(feature_range=(0, 100))
df_players[features_to_scale] = scaler.fit_transform(df_players[features_to_scale])

# ===============================
# 4. Atipicos
# ===============================

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
df_players["score_fisico"] = df_players[["acceleration", "sprint_speed", "stamina", "strength"]].mean(axis=1)
# ===============================
# SCORE TECNICO: ball_control, dribbling, short_passing
# ===============================
df_players["score_tecnico"] = df_players[["ball_control", "dribbling", "short_passing"]].mean(axis=1)
# ===============================
# SCORE MENTAL: positioning, vision, reactions
# ===============================
df_players["score_mental"] = df_players[["positioning", "vision", "reactions"]].mean(axis=1)


# ===============================
# EDAD
# ===============================
df_players["birthday"] = pd.to_datetime(df_players["birthday"])
df_players["edad"] = (
    (df_players["date"] - df_players["birthday"]).dt.days // 365
)

# ===============================
# Revisar dataset final
# ===============================
print(df_players.shape)
print(df_players.isnull().sum().sort_values(ascending=False).head(10))
df_players.head()

# ======================================================================================================================================
# ======================================================================================================================================
# ======================================================================================================================================


# ================================
# ===     REGRESION LINEAL     ===
# ================================

# ===============================
# SELECCION DE VARIABLES 
# ===============================

features = [
        "acceleration",
    "sprint_speed",
    "stamina",
    "strength",
    "ball_control",
    "dribbling",
    "short_passing",
    "reactions",
    "vision",
    "positioning",
    "interceptions",
    "marking",
    "standing_tackle",
    "height",
    "edad"
]
data = df_players[features + ["overall_rating"]].dropna()

X = data[features].values
y = data["overall_rating"].values  

#poly = PolynomialFeatures(degree=2, interaction_only=True, include_bias=False)
#X_poly = poly.fit_transform(X)

modelo = Regresion()
modelo.fit(X, y)
modelo.normalizar_seguro()
modelo.descenso_de_gradiente(alpha=0.01, itera=2000, epsilon=1e-6)

# ===============================
# Validación cruzada K-Fold
# ===============================

resultados = modelo.kfold_cross_validation(
    k=5,
    alpha=0.01,
    itera=2000,
    epsilon=1e-6,
    random_state=42
)

# ===============================
# VALIDACION RESIDUOS
# ===============================

X_design = modelo.get_X
theta = modelo.get_param()
y_real = modelo.get_y
y_pred = X_design.dot(theta).reshape(-1, 1)

residuos = y_real - y_pred

# ===============================
# ANALISIS DE MULTICOLINEALIDAD (VIF)
# ===============================

X_vif = df_players[features].copy()

vif = pd.DataFrame()
vif["Variable"] = X_vif.columns
vif["VIF"] = [variance_inflation_factor(X_vif.values, i) for i in range(X_vif.shape[1])]

print(vif.sort_values("VIF", ascending=False))




# REENTRENAMIENTO

features_reducidas = [
    "score_fisico",
    "score_tecnico",
    "score_mental",
    "height",
    "weight",
    "edad"
]

# Filtrar dataset para entrenamiento
data_modelo2 = df_players[features_reducidas + ["overall_rating"]].dropna()
X_re = data_modelo2[features_reducidas].values
y_re = data_modelo2["overall_rating"].values

#poly = PolynomialFeatures(degree=2, interaction_only=True, include_bias=False)
#X2_poly = poly.fit_transform(X_re)
modelo2 = Regresion()
modelo2.fit(X_re, y_re)
modelo2.normalizar_seguro()
modelo2.descenso_de_gradiente(alpha=0.01, itera=2000, epsilon=1e-6)

modelo2.kfold_cross_validation(
    k=5,
    alpha=0.01,
    itera=2000,
    epsilon=1e-6,
    random_state=42
)

# ======================================================================================================================================
# ======================================================================================================================================
# ======================================================================================================================================

# ================================
# ===   REGRESION LOGISTICO    ===
# ================================

# ===============================
# PREPARAR VARIABLE OBJETIVO
# ===============================

# ===============================
# Crear variable objetivo: posición
# ===============================

def asignar_posicion(row):
    if row[['gk_diving','gk_handling','gk_reflexes','gk_positioning']].mean() > 40:
        return 0  # Portero
    elif row[['marking','standing_tackle','interceptions']].mean() > 60:
        return 1  # Defensa
    elif row[['short_passing','vision','ball_control']].mean() > 60:
        return 2  # Medio
    else:
        return 3  # Atacante

# ====================================================
# Creamos columnas resumen de atributos por posición
# ====================================================
df_players['defending'] = df_players[['marking', 'standing_tackle', 'sliding_tackle', 'interceptions', 'strength']].mean(axis=1)
df_players['passing'] = df_players[['short_passing', 'long_passing', 'ball_control']].mean(axis=1)
df_players['dribbling'] = df_players[['dribbling', 'agility', 'reactions']].mean(axis=1)

df_players['position_label'] = df_players.apply(asignar_posicion, axis=1)

# ========================================================
# Balancear dataset si es necesario (oversampling simple) 
# ========================================================
dfs = []
for label in df_players['position_label'].unique():
    subset = df_players[df_players['position_label'] == label]
    dfs.append(resample(subset, replace=True, n_samples=500, random_state=42))

df_balanced = pd.concat(dfs)


features_cls = [
  'score_fisico',
  'score_tecnico',
  'score_mental',
  'height',
  'weight'
]

X_cls = df_balanced[features_cls].values
y_cls = df_balanced['position_label'].values
scaler_cls = MinMaxScaler()
X_cls = scaler_cls.fit_transform(X_cls)

# ===============================
# ENTRENAMIENTO LOGISTICA OvR
# ===============================

# Instanciar y entrenar
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(
    X_cls, y_cls, test_size=0.3, random_state=42, stratify=y_cls
)

logreg = LogisticRegressionOvR(
    learning_rate=0.001,
    n_iter=2000,
    lambda_reg=0.1,
    verbose=True
)

logreg.fit(X_train, y_train)


y_pred = logreg.predict(X_test)

print("=== Matriz de Confusion ===")
print(confusion_matrix(y_test, y_pred))

print("\n=== Reporte de Clasificacion ===")
print(classification_report(y_test, y_pred, digits=3))

# =============================
# Probabilidades por posición
# =============================

probs = np.zeros((X_test.shape[0], logreg.n_classes))
for c in range(logreg.n_classes):
    w = logreg.models[c]['w']
    b = logreg.models[c]['b']
    probs[:, c] = logreg.sigmoid(X_test.dot(w) + b)  

# ============================================================
# Jugadores híbridos: probabilidad > 0.3 en múltiples clases
# ============================================================
sorted_probs = np.sort(probs, axis=1)
hybrids = np.where((sorted_probs[:, -1] - sorted_probs[:, -2]) < 0.15)[0]
print(f"Jugadores hibridos detectados: {len(hybrids)}")
print(df_balanced.iloc[hybrids][['player_api_id', 'position_label']])


# ===========================================
# 1. VALIDACIÓN ESTADÍSTICA REGRESIÓN LINEAL
# ===========================================

X_design = modelo2.get_X
theta = modelo2.get_param()
y_real = modelo2.get_y

y_pred_rl = X_design.dot(theta).reshape(-1, 1)
residuos = y_real - y_pred_rl

# Normalidad
stat, p = shapiro(residuos[:5000])
print("Shapiro p-value:", p)

sm.qqplot(residuos, line="45")
plt.title("QQ-Plot de residuos")
plt.show()

# Homocedasticidad
X_sm = sm.add_constant(X_re)
bp = het_breuschpagan(residuos, X_sm)
print("Breusch-Pagan p-value:", bp[1])

# ====================
# 2. DASHBOARD BÁSICO
# ====================

plt.figure()
plt.hist(residuos, bins=50)
plt.title("Distribución de residuos")
plt.show()