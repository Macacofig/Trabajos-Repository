import numpy as np
import matplotlib.pyplot as plt

# Parámetros

c = 1.0
Nx = 40
x = np.linspace(0, 2, Nx)
dx = x[1] - x[0]
dt = 0.02
Nt = 50
λ = c * dt / dx   # número de Courant

# Condición inicial
def onda_cuadrada(x):
    return np.where((x >= 0.5) & (x <= 1.0), 2, 1)

u = onda_cuadrada(x)
resultados_lambda = [(0, u.copy())]

# Evolución temporal
for n in range(1, Nt+1):
    u_new = u.copy()
    u_new[0] = u[0]  # frontera izquierda
    for i in range(1, Nx):
        u_new[i] = u[i] - λ * (u[i] - u[i-1])
    u = u_new
    resultados_lambda.append((n*dt, u.copy()))

# Graficar TODAS las curvas
plt.figure()
for t, u in resultados_lambda:   # sin slicing
    plt.plot(x, u, label=f"t={t:.2f}")

plt.xlabel("x")
plt.ylabel("u(x,t)")
plt.legend()
plt.title("Advección 1D lineal (usando λ)")
plt.grid()
plt.show()