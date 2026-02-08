import numpy as np
import matplotlib.pyplot as plt
from datetime import datetime

# ============================
# INTEGRADOR RK4
# ============================
def get_euler(t0, tf, presente, direccion, intervalo, *args):
    pasos = int(np.ceil((tf - t0) / intervalo) + 1)
    futuros = []
    tiempos = []
    
    for i in range(0, pasos):
        futuros.append(presente)
        tiempos.append(t0)
        if t0 + intervalo > tf:
            intervalo = tf - t0
        f1 = direccion(t0, presente, *args)
        f2 = direccion(t0 + intervalo/2, presente + intervalo/2 * f1, *args)
        f3 = direccion(t0 + intervalo/2, presente + intervalo/2 * f2, *args)
        f4 = direccion(t0 + intervalo, presente + intervalo * f3, *args)
        presente = presente + (intervalo/6) * (f1 + 2*f2 + 2*f3 + f4)
        t0 = t0 + intervalo
    return np.array(futuros), np.array(tiempos)

# ============================
# MODELO SEIR
# ============================
def SEIR(t, Y, beta, sigma, gamma, N):
    S, E, I, R = Y
    dS = -beta * S * I / N
    dE = beta * S * I / N - sigma * E
    dI = sigma * E - gamma * I
    dR = gamma * I
    return np.array([dS, dE, dI, dR])

# ============================
# DATOS REALES APROXIMADOS BOLIVIA 2020
# ============================
def get_real_bolivia_data(days):
    real_cases = np.zeros(days+1)
    monthly_data = {
        0: 100,     # marzo acumulado
        30: 1000,   # abril
        60: 5000,   # mayo
        90: 20000,  # junio
        133: 45000, # julio (pico)
        163: 80000, # agosto
        277: 160000 # diciembre
    }
    keys = sorted(monthly_data.keys())
    for i in range(len(keys)-1):
        start, end = keys[i], keys[i+1]
        real_cases[start:end+1] = np.linspace(monthly_data[start], monthly_data[end], end-start+1)
    real_daily = np.diff(real_cases, prepend=0)
    return real_daily


# Población total Bolivia
N = 11_600_000

# Condiciones iniciales
I0, E0, R0 = 10, 20, 0
S0 = N - I0 - E0 - R0
Y0 = np.array([S0, E0, I0, R0])

# Parámetros (ajustables)
beta = 0.25    # tasa de transmisión
sigma = 1/5.2  # periodo incubación ~5 días
gamma = 1/10   # periodo infeccioso ~10 días

# Tiempo de simulación
t0 = 0
tf = (datetime(2020,12,14) - datetime(2020,3,12)).days
intervalo = 1.0

# Ejecutar integración SEIR
resultados, tiempos = get_euler(t0, tf, Y0, SEIR, intervalo, beta, sigma, gamma, N)
S, E, I, R = resultados.T

# Casos diarios aproximados del modelo = nuevas infecciones = sigma*E
modeled_daily = sigma * E

# Datos reales
real_daily = get_real_bolivia_data(int(tf))

# ---- Gráfica
plt.figure(figsize=(12,6))
plt.plot(real_daily, 'k-', linewidth=2, label="Datos Reales (aprox.)")
plt.plot(modeled_daily, 'r--', linewidth=2, label="Modelo SEIR")
plt.title("COVID-19 Bolivia 2020: Datos vs Modelo SEIR")
plt.xlabel("Días desde 12 marzo 2020")
plt.ylabel("Casos diarios")
plt.legend()
plt.grid(alpha=0.3)
plt.show()

plt.plot(S, label='Susceptibles')
plt.plot(E, label='Expuestos')
plt.plot(I, label='Infectados')
plt.plot(R, label='Recuperados')
plt.title("Dinámica de la Enfermedad - Modelo SEIR")
plt.xlabel("Días desde 12 marzo 2020")
plt.ylabel("Población")
plt.legend()
plt.grid(alpha=0.3)
plt.show()

# ---- Métricas
real_peak_day = np.argmax(real_daily)
real_peak_cases = np.max(real_daily)
model_peak_day = np.argmax(modeled_daily)
model_peak_cases = np.max(modeled_daily)

print("="*70)
print("COMPARACIÓN MÉTRICAS - COVID-19 BOLIVIA 2020")
print("="*70)
print(f"Fecha pico real (día {real_peak_day}): {real_peak_cases:.0f} casos")
print(f"Fecha pico modelo (día {model_peak_day}): {model_peak_cases:.0f} casos")
print(f"Error en fecha del pico: {abs(real_peak_day - model_peak_day)} días")
print(f"Error en magnitud del pico: {abs(real_peak_cases - model_peak_cases):.0f} casos")
print("="*70)

