import numpy as np
import pandas as pd
from Logistico import *   
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

def main():
    # 1) Cargar datos desde CSV
    df = pd.read_csv("inmueble_data.csv")

    # 1a) Crear clusters de zona usando latitud y longitud
    lat_long = df[['lat', 'long']].copy()
    n_clusters = 5
    kmeans = KMeans(n_clusters=n_clusters, random_state=42)
    df['zona'] = kmeans.fit_predict(lat_long)  # asigna cada inmueble a un cluster

    # quitar lat y long originales
    df = df.drop(columns=['lat', 'long'])

    # 1b) Transformar precio con logaritmo para estabilizar escala
    df['precio_log'] = np.log1p(df['precio'])

    # 1c) Crear nuevas features
    df['total_area'] = df['area_arriba'] + df['area_base']  # area total de la casa
    df['picina'] = df['picina'].apply(lambda x: 1 if x else 0)  # convertir a binario
    df['area_lote_log'] = np.log1p(df['area_lote'])  # normalizar con log

    # 2) Seleccion de features a usar en el modelo
    features = ['habitaciones', 'banos', 'area_vivienda', 'pisos', 
                'vista', 'grado', 'total_area', 'area_lote_log', 'picina']

    X = df[features].values  # matriz de caracteristicas
    y = df['precio_log'].values  # vector objetivo

    # 3) Crear modelo de regresion
    modelo = Regresion()
    modelo.fit(X, y)  # carga X y y al modelo

    # 4) Division estratificada en train y test
    modelo.split_test_stratified(test_size=0.2, bins=5, random_state=42)

    # 5) Preprocesamiento: nulos, outliers y normalizacion
    modelo.manejar_nulos_seguro()
    modelo.manejar_atipicos_seguro()
    modelo.normalizar_seguro()

    # 6) Inicializar parametros theta en ceros
    modelo._Regresion__theta = np.zeros(modelo.get_X.shape[1])

    # 7) Entrenar modelo con descenso de gradiente
    modelo.descenso_de_gradiente(
        alpha=0.007,
        epsilon=1e-6,
        itera=5000,
        lambd=0.05
    )

    # 8) Mostrar metricas finales
    print("\n--- metricas finales ---")
    print("MSE Train:", modelo.get_ECM(modelo.get_X, modelo.get_y))
    print("MSE Test:", modelo.get_ECM(modelo.get_X_test, modelo.get_y_test))
    print("RMSE Test:", modelo.get_RECM(modelo.get_X_test, modelo.get_y_test))
    print("R2 Test :", modelo.get_r2(modelo.get_X_test, modelo.get_y_test))
    print("Interpretacion:", modelo.interpretar_r2())

    # 9) Graficar historial de costo del descenso de gradiente
    modelo.graficar_historial()

    # 10) Validacion cruzada K-Fold
    print("\n--- K-Fold cross validation ---")
    modelo.kfold_cross_validation(k=5, alpha=0.007, epsilon=1e-6, itera=5000, random_state=42)

    # 11) Pipeline de produccion
    print("\n--- Pipeline de produccion ---")
    modelo.pipeline_produccion(alpha=0.007, itera=5000, epsilon=1e-6, lambd=0.05)

    # 12) Visualizar clusters geograficos
    plt.scatter(lat_long['long'], lat_long['lat'], c=df['zona'], cmap='tab10')
    plt.xlabel("Longitud")
    plt.ylabel("Latitud")
    plt.title("Clusters de zonas geografica")
    plt.show()

if __name__ == "__main__":
    main()
