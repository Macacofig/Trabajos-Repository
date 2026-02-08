import numpy as np
import matplotlib.pyplot as plt

# Parámetros corregidos
Nx = 100
x = np.linspace(0, 2, Nx)
dx = x[1] - x[0]

# Condición inicial
def onda_cuadrada(x):
    return np.where((x >= 0.5) & (x <= 1.0), 2.0, 1.0)

u0 = onda_cuadrada(x)

# Calcular dt basado en la condición CFL para Burgers
u_max = np.max(np.abs(u0))  # Velocidad máxima inicial
CFL = 0.5  # Número de Courant más conservador para no lineal
dt = CFL * dx / u_max

print(f"dx = {dx:.4f}, u_max = {u_max:.2f}, dt = {dt:.6f}")

Nt = 200
resultados_burgers = [(0, u0.copy())]
u = u0.copy()

# Evolución temporal estable
for n in range(1, Nt + 1):
    u_new = u.copy()
    
    # Esquema upwind condicional para Burgers
    for i in range(1, Nx - 1):
        if u[i] >= 0:
            # Flujo hacia la derecha
            u_new[i] = u[i] - (dt/dx) * u[i] * (u[i] - u[i-1])
        else:
            # Flujo hacia la izquierda
            u_new[i] = u[i] - (dt/dx) * u[i] * (u[i+1] - u[i])
    
    # Condiciones de frontera
    u_new[0] = u[0]    # Frontera izquierda fija
    u_new[-1] = u[-1]  # Frontera derecha fija
    
    u = u_new
    
    if n % 20 == 0:
        resultados_burgers.append((n*dt, u.copy()))

# Graficar
plt.figure(figsize=(12, 8))
colors = plt.cm.viridis(np.linspace(0, 1, len(resultados_burgers)))

for idx, (tiempo, solucion) in enumerate(resultados_burgers):
    plt.plot(x, solucion, color=colors[idx], label=f"t={tiempo:.3f}")

plt.xlabel("x")
plt.ylabel("u(x,t)")
plt.title("Ecuación de Burgers (estable)")
plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.show()