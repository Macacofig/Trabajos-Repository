import numpy as np
import matplotlib.pyplot as plt


nx=41 # numero de divisiones en la grilla x
L=2.0 # tamanio total del espacio
dx= L/(nx-1) # salto en x
nt=25 # numero de pasos en el tiempo
dt=0.02 # salto en el tiempo
c=1.0 # velocidad de conveccion

x = np.linspace(0.0,L,num=nx)

u0 = np.ones(nx)
mask = np.where(np.logical_and(x>= 0.5, x<=1.0))
mask

u0[mask] = 2.0
print(u0)

u = u0.copy()
for n in range(1,nt):
    un = u.copy()
    for i in range(1,nx):
        u[i] = un[i] - c * dt/dx * (un[i] - un[i-1])


plt.figure(figsize=(4.0,4.0))
plt.xlabel('x')
plt.ylabel('u')
plt.plot(x,u0,label='Initial',color='C0', linestyle = '--', linewidth=2)
plt.plot(x,u,label='nt={}'.format(nt),color='C1',linestyle='-',linewidth=2)
plt.legend()
plt.xlim(0.0, L)
plt.ylim(0.0,2.5)

plt.show()



# Parámetros
c = 1.0              # velocidad 
x = np.linspace(0, 2, 100)   # 100 puntos espaciales (ejemplo)
t_vals = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]  # tiempos a simular

# Condición 
def onda_cuadrada(x):
    return np.where((x >= 0.5) & (x <= 1.0), 2, 1)

# Solución analítica discreta
def solucion(x, t, c):
    return onda_cuadrada(x - c*t)

# Simulación en varios tiempos
for t in t_vals:
    u = solucion(x, t, c)
    print(f"(t={t:.1f}, {u.tolist()})")
    plt.plot(x,u)
    
plt.grid()
plt.show()  

# # La deformacion inicia con valores menores a 100 usando solo c






