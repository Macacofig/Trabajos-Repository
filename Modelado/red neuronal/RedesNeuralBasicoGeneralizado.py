import numpy as np
import h5py


# Función sigmoide
# Toda numero que entra se vuelve un valor entre 0 y 1
def sigmoide(z):
    return 1 / (1 + np.exp(-z))


# Forward generalizado
# aplicacion de la red neuronal hacia adelante
# entran los datos y los pesos, salen las activaciones de cada capa
# capa 1 = entrada
# capa 2 = oculta -> calculo con peso theta1
# capa 3 = salida -> calculo con peso theta2
def forward_general(X, Thetas):
    m = X.shape[0]
    a = np.concatenate([np.ones((m,1)), X], axis=1)
    a_capas = [a]

    for i, Theta in enumerate(Thetas): # adaptacion para n thetas
        z = a @ Theta.T
        a = sigmoide(z)
        if i != len(Thetas)-1:
            a = np.concatenate([np.ones((m,1)), a], axis=1)
        a_capas.append(a)

    return a_capas


# Error generalizado (backprop)
# cálculo del error en cada capa

def backprop_error(a_capas, y_vec, Thetas):
    L = len(Thetas)
    S = []

    S_L = a_capas[-1] - y_vec # error en la capa de salida, y_vec es la etiqueta
    S.append(S_L)

    for l in range(L-1, 0, -1):
        a_l = a_capas[l]
        Theta_l = Thetas[l]
        S_next = S[-1]

        S_l = (S_next @ Theta_l) * (a_l * (1 - a_l))
        S_l = S_l[:,1:]
        S.append(S_l)

    S.reverse()
    return S


# Acumulación de deltas
# cálculo de los deltas para cada capa
def compute_deltas(a_capas, S):
    Deltas = []
    for l in range(len(S)):
        Delta_l = S[l].T @ a_capas[l]
        Deltas.append(Delta_l)
    return Deltas


# Gradientes
# cálculo de los gradientes con regularización
def gradientes_general(Deltas, Thetas, m, lambda_):
    Grads = []
    for Delta, Theta in zip(Deltas, Thetas):
        reg = (lambda_/m) * np.concatenate(
            [np.zeros((Theta.shape[0],1)), Theta[:,1:]], axis=1
        )
        Grad = (1/m) * Delta + reg
        Grads.append(Grad)
    return Grads


# Costo 
# cálculo del costo con regularización
def costo(a_final, y_vec, Thetas, lambda_):
    m = y_vec.shape[0]
    costo_base = (-1/m) * np.sum(y_vec*np.log(a_final) + (1-y_vec)*np.log(1-a_final))
    reg = (lambda_/(2*m)) * sum(np.sum(Theta[:,1:]**2) for Theta in Thetas)
    return costo_base + reg


if __name__ == "__main__":
    with h5py.File("theta_digitos.h5", "r") as param, \
         h5py.File("C:\\Users\\omkrf\\Desktop\\Nuev py\\Modelado\\MachineLearning\\digitos.h5", "r") as digitos:

        X = digitos["X"][:]
        y = digitos["y"][:]
        y_vec = np.eye(10)[y]

        Theta1 = param["Theta1"][:]
        Theta2 = param["Theta2"][:]
        Thetas = [Theta1, Theta2]

        lambda_ = 1

        a_capas = forward_general(X, Thetas)
        S = backprop_error(a_capas, y_vec, Thetas)
        Deltas = compute_deltas(a_capas, S)
        Grads = gradientes_general(Deltas, Thetas, X.shape[0], lambda_)
        J = costo(a_capas[-1], y_vec, Thetas, lambda_)

        # ==========================================================
        #             IMPRESIÓN FINAL (LO QUE PEDISTE)
        # ==========================================================
        print("\nRESULTADOS ")
        print(f"Costo J(theta): {J}\n")
        print("Gradiente Theta1 (shape):", Grads[0].shape)
        print("Gradiente Theta2 (shape):", Grads[1].shape)

