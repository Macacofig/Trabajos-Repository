from RegresionM import Regresion
import numpy as np

if __name__ == "__main__":
    #  1. Cargar CSV 
    data = np.genfromtxt("inmueble_data.csv", delimiter=",", skip_header=1)

    #  2. Seleccionar columnas 
    # area_vivienda (columna 5) y precio (columna 2)
    X = data[:, 5].reshape(-1, 1)
    y = data[:, 2]

    #  3. Crear modelo 
    r = Regresion()
    r.fit(X, y)

    #  4. Dividir en train/test (80/20) 
    r.split_test_stratified(test_size=0.2, random_state=42)

    #  5. Normalizar datos 
    r.normalizar()

    #  6. Entrenar modelo con descenso de gradiente 
    print("\n ENTRENAMIENTO ")
    r.descenso_de_gradiente(alpha=0.01, epsilon=1e-6, itera=5000)

    #  7. Evaluar desempeño 
    print("\n EVALUACION ")
    mse = r.get_ECM()
    rmse = r.get_RECM()
    r2 = r.get_r2()

    print(f"MSE: {mse:.2f}")
    print(f"RMSE: {rmse:.2f}")
    print(f"R^2: {r2:.4f}")

    #  8. Graficar resultados 
    r.graficar_historial()
    r.graficar_data(model=True)