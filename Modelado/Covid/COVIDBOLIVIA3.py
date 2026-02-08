# Importación de librerías necesarias
import pandas as pd  # Para manipulación y análisis de datos
import numpy as np  # Para operaciones matemáticas y arrays
import matplotlib.pyplot as plt  # Para visualización gráfica
from datetime import datetime, timedelta  # Para manejo de fechas y tiempos
from scipy.interpolate import CubicSpline  # Para interpolación de curvas suaves
from scipy.optimize import curve_fit  # Para ajuste de curvas a datos

# ============================
# FUNCIONES GENERALES PARA MODELOS EPIDEMIOLÓGICOS
# ============================

def logistic_growth(t, K, r, t0):
    """
    Función de crecimiento logístico general
    t: tiempo (array de días)
    K: capacidad de carga (máximo de casos posibles)
    r: tasa de crecimiento (qué tan rápido crece la epidemia)
    t0: punto de inflexión (día donde ocurre el crecimiento máximo)
    """
    # Fórmula estándar del crecimiento logístico
    return K / (1 + np.exp(-r * (t - t0)))

def double_logistic_growth(t, K1, r1, t01, K2, r2, t02):
    """
    Función de doble crecimiento logístico para modelar múltiples olas
    Combina dos curvas logísticas para representar dos picos epidémicos
    """
    # Suma de dos curvas logísticas con parámetros diferentes
    return logistic_growth(t, K1, r1, t01) + logistic_growth(t, K2, r2, t02)

def gompertz_curve(t, a, b, c):
    """
    Curva de Gompertz, alternativa al modelo logístico
    a: asíntota superior (valor máximo que puede alcanzar la curva)
    b: desplazamiento en el eje x (controla la posición de la curva)
    c: tasa de crecimiento (qué tan rápido crece la epidemia)
    """
    # Fórmula de la curva de Gompertz
    return a * np.exp(-b * np.exp(-c * t))

def seir_model(beta, gamma, sigma, N, I0, E0, R0, days):
    """
    Modelo SEIR básico (Susceptible-Expuesto-Infectado-Recuperado)
    beta: tasa de transmisión (probabilidad de contagio)
    gamma: tasa de recuperación (inverso del tiempo de recuperación)
    sigma: tasa de incubación (inverso del período de incubación)
    N: población total
    I0: infectados iniciales
    E0: expuestos iniciales (infectados pero no aún contagiosos)
    R0: recuperados iniciales
    days: días a simular
    """
    # Inicialización de arrays para cada compartimento
    S = np.zeros(days)  # Susceptibles
    E = np.zeros(days)  # Expuestos
    I = np.zeros(days)  # Infectados
    R = np.zeros(days)  # Recuperados
    
    # Condiciones iniciales
    S[0] = N - I0 - E0 - R0  # Susceptibles iniciales
    E[0] = E0  # Expuestos iniciales
    I[0] = I0  # Infectados iniciales
    R[0] = R0  # Recuperados iniciales
    
    # Simulación día por día
    for t in range(0, days-1):
        # Susceptibles que se infectan (proporcional a infectados)
        S[t+1] = S[t] - (beta * S[t] * I[t]) / N
        # Expuestos: nuevos infectados menos los que desarrollan síntomas
        E[t+1] = E[t] + (beta * S[t] * I[t]) / N - sigma * E[t]
        # Infectados: nuevos sintomáticos menos los que se recuperan
        I[t+1] = I[t] + sigma * E[t] - gamma * I[t]
        # Recuperados: infectados que se recuperan
        R[t+1] = R[t] + gamma * I[t]
    
    return I  # Devolvemos solo los infectados activos (casos diarios)

def fit_epidemiological_curve(days, real_data, model_type='logistic'):
    """
    Ajusta una curva epidemiológica a datos reales usando optimización
    days: array de días
    real_data: datos reales de casos
    model_type: tipo de modelo a ajustar ('logistic' o 'gompertz')
    """
    if model_type == 'logistic':
        # Estimaciones iniciales para parámetros logísticos
        K_guess = np.max(real_data) * 1.2  # Capacidad de carga (máximo de casos)
        r_guess = 0.1  # Tasa de crecimiento inicial
        t0_guess = np.argmax(real_data)  # Día del pico
        
        try:
            # Ajuste de curva usando mínimos cuadrados
            params, _ = curve_fit(logistic_growth, days, real_data, 
                                 p0=[K_guess, r_guess, t0_guess],
                                 bounds=([0, 0, 0], [K_guess*2, 1, len(days)]))
            # Generar curva ajustada
            fitted_curve = logistic_growth(days, *params)
            return fitted_curve, params
        except:
            # Si falla el ajuste, retornar None
            return None, None
    
    elif model_type == 'gompertz':
        # Estimaciones iniciales para parámetros de Gompertz
        a_guess = np.max(real_data) * 1.2  # Asíntota superior
        b_guess = 5  # Parámetro de desplazamiento
        c_guess = 0.1  # Tasa de crecimiento
        
        try:
            # Ajuste de curva Gompertz
            params, _ = curve_fit(gompertz_curve, days, real_data, 
                                 p0=[a_guess, b_guess, c_guess],
                                 bounds=([0, 0, 0], [a_guess*2, 10, 1]))
            fitted_curve = gompertz_curve(days, *params)
            return fitted_curve, params
        except:
            return None, None
    
    return None, None

def calculate_epidemiological_metrics(cases_curve, population):
    """
    Calcula métricas epidemiológicas a partir de una curva de casos
    cases_curve: array de casos diarios
    population: población total
    """
    # Encuentra el pico (valor máximo de casos)
    peak_value = float(np.max(cases_curve))
    # Día donde ocurre el pico (convertir a int nativo de Python)
    peak_day = int(np.argmax(cases_curve))
    
    # Calcula el área bajo la curva (suma de casos diarios = casos totales aproximados)
    total_cases_approx = float(np.sum(cases_curve))
    
    # Calcula la tasa de ataque (porcentaje de población infectada)
    attack_rate = float(total_cases_approx / population * 100)
    
    return {
        'peak_value': peak_value,
        'peak_day': peak_day,
        'total_cases_approx': total_cases_approx,
        'attack_rate': attack_rate
    }

# ============================
# APLICACIÓN ESPECÍFICA PARA BOLIVIA 2020
# ============================

def get_bolivia_parameters():
    """
    Parámetros específicos para Bolivia 2020 basados en datos reales
    """
    # Población de Bolivia en 2020 (aproximadamente)
    population = 11600000
    
    # Parámetros basados en reportes oficiales y estudios
    params = {
        'population': population,
        'first_case_day': datetime(2020, 3, 10),  # Primer caso reportado
        'lockdown_start': datetime(2020, 3, 22),  # Inicio de cuarentena
        'peak_date': datetime(2020, 7, 25),  # Día del pico máximo
        'lockdown_eased': datetime(2020, 8, 1),  # Flexibilización de medidas
        'second_wave_start': datetime(2020, 11, 1),  # Inicio de segunda ola
        'total_cases_2020': 160000,  # Casos acumulados en 2020
        'peak_daily_cases': 1702,  # Máximo de casos diarios
        'fatality_rate': 6.2,  # Tasa de letalidad (%)
        'r0_initial': 2.5,  # Número básico de reproducción inicial
        'r0_post_intervention': 1.2  # R0 después de intervenciones
    }
    
    return params

def generate_bolivia_real_data(days):
    """
    Genera datos reales aproximados para Bolivia 2020 usando interpolación
    Basado en puntos clave reportados por el Ministerio de Salud
    days: array de días desde el primer caso
    """
    # Puntos clave basados en reportes oficiales (día: casos)
    key_points = {
        0: 2,       # 10-Mar: Primeros casos
        12: 15,     # 22-Mar: Inicio cuarentena
        52: 50,     # 01-May: Fin fase inicial
        82: 200,    # 31-May: Crecimiento moderado
        112: 800,   # 30-Jun: Aceleración
        137: 1702,  # 25-Jul: Pico máximo
        167: 1200,  # 24-Ago: Descenso inicial
        197: 600,   # 23-Sep: Meseta baja
        227: 400,   # 23-Oct: Descenso continuo
        257: 300,   # 22-Nov: Reactivación inicial
        287: 250,   # 22-Dic: Estabilización
        297: 200    # 01-Ene: Fin de año
    }
    
    # Interpolación cúbica para crear una curva suave entre puntos
    x_points = list(key_points.keys())  # Días de los puntos clave
    y_points = list(key_points.values())  # Casos en los puntos clave
    
    # Crear spline cúbico para interpolación suave
    cs = CubicSpline(x_points, y_points)
    # Evaluar el spline en todos los días
    real_cases = cs(days)
    
    # Asegurar valores positivos (la pandemia no puede tener casos negativos)
    real_cases = np.maximum(real_cases, 0)
    
    return real_cases

def simulate_bolivia_2020_general():
    """
    Simula la pandemia en Bolivia 2020 usando funciones generales
    Retorna un diccionario con todos los resultados y parámetros
    """
    # Obtener parámetros específicos de Bolivia
    params = get_bolivia_parameters()
    
    # Crear línea de tiempo (desde primer caso hasta fin de año)
    start_date = params['first_case_day']
    end_date = datetime(2021, 1, 1)  # Fin del año 2020
    days_count = (end_date - start_date).days  # Total de días a simular
    day_array = np.arange(days_count)  # Array de días [0, 1, 2, ..., days_count-1]
    
    # Generar datos reales aproximados mediante interpolación
    real_cases = generate_bolivia_real_data(day_array)
    
    # Ajustar modelo logístico a los datos reales
    fitted_logistic, logistic_params = fit_epidemiological_curve(
        day_array, real_cases, model_type='logistic')
    
    # Ajustar modelo Gompertz a los datos reales
    fitted_gompertz, gompertz_params = fit_epidemiological_curve(
        day_array, real_cases, model_type='gompertz')
    
    # Calcular métricas epidemiológicas a partir de los datos reales
    metrics = calculate_epidemiological_metrics(real_cases, params['population'])
    
    # Retornar todos los resultados en un diccionario
    return {
        'days': day_array,
        'real_cases': real_cases,
        'fitted_logistic': fitted_logistic,
        'fitted_gompertz': fitted_gompertz,
        'logistic_params': logistic_params,
        'gompertz_params': gompertz_params,
        'metrics': metrics,
        'params': params
    }

# ============================
# VISUALIZACIÓN Y ANÁLISIS
# ============================

def plot_model_comparison(results):
    """
    Compara diferentes modelos con los datos reales en una gráfica
    results: diccionario con resultados de la simulación
    """
    # Extraer datos del diccionario de resultados
    days = results['days']
    real_cases = results['real_cases']
    fitted_logistic = results['fitted_logistic']
    fitted_gompertz = results['fitted_gompertz']
    params = results['params']
    
    # Crear figura de tamaño adecuado para visualización
    plt.figure(figsize=(16, 10))
    
    # Graficar datos reales (línea negra sólida)
    plt.plot(days, real_cases, 'k-', linewidth=3, label='Datos Reales (Aproximados)')
    
    # Graficar modelos ajustados si están disponibles
    if fitted_logistic is not None:
        plt.plot(days, fitted_logistic, 'b--', linewidth=2, 
                label=f'Modelo Logístico (K={results["logistic_params"][0]:.0f}, r={results["logistic_params"][1]:.3f})')
    
    if fitted_gompertz is not None:
        plt.plot(days, fitted_gompertz, 'r--', linewidth=2, 
                label=f'Modelo Gompertz (a={results["gompertz_params"][0]:.0f}, c={results["gompertz_params"][2]:.3f})')
    
    # Definir hitos importantes y calcular sus días correspondientes
    milestones = {
        'Cuarentena': (params['lockdown_start'] - params['first_case_day']).days,
        'Pico Real': (params['peak_date'] - params['first_case_day']).days,
        'Flexibilización': (params['lockdown_eased'] - params['first_case_day']).days,
        '2da Ola': (params['second_wave_start'] - params['first_case_day']).days
    }
    
    # Colores para las líneas verticales de hitos
    colors = ['red', 'green', 'orange', 'purple']
    # Dibujar líneas verticales para cada hito
    for i, (event, day) in enumerate(milestones.items()):
        plt.axvline(x=day, color=colors[i], linestyle='--', alpha=0.8, label=event)
    
    # Configuración de ejes y título
    plt.xlabel('Días desde el primer caso (10 Marzo 2020)', fontsize=12)
    plt.ylabel('Casos diarios', fontsize=12)
    plt.title('Comparación de Modelos Epidemiológicos - COVID-19 Bolivia 2020', fontsize=14)
    plt.grid(True, alpha=0.3)  # Grid suave para mejor visualización
    plt.legend(loc='upper right', fontsize=11)  # Leyenda en esquina superior derecha
    
    # Crear segundo eje X superior con fechas calendarizadas
    ax2 = plt.gca().twiny()  # Crear eje twin (comparte eje Y)
    ax2.set_xlim(plt.gca().get_xlim())  # Mismos límites que eje X principal
    # Fechas importantes para marcar en el eje superior
    important_dates = [
        (0, 'Mar 10'), (30, 'Abr 9'), (60, 'May 9'),
        (90, 'Jun 8'), (120, 'Jul 8'), (150, 'Ago 7'),
        (180, 'Sep 6'), (210, 'Oct 6'), (240, 'Nov 5'),
        (270, 'Dic 5'), (297, 'Ene 1')
    ]
    # Configurar ticks y labels del eje superior
    ax2.set_xticks([x for x, _ in important_dates])
    ax2.set_xticklabels([label for _, label in important_dates])
    ax2.set_xlabel('Fecha', fontsize=11)
    
    # Ajustar layout y mostrar gráfica
    plt.tight_layout()
    plt.show()

def plot_residuals(results):
    """
    Grafica los residuales (diferencias) entre datos reales y modelos ajustados
    results: diccionario con resultados de la simulación
    """
    # Extraer datos necesarios
    days = results['days']
    real_cases = results['real_cases']
    fitted_logistic = results['fitted_logistic']
    fitted_gompertz = results['fitted_gompertz']
    
    # Crear figura para residuales
    plt.figure(figsize=(16, 6))
    
    # Calcular y graficar residuales del modelo logístico si está disponible
    if fitted_logistic is not None:
        residuals_logistic = real_cases - fitted_logistic
        plt.plot(days, residuals_logistic, 'b-', alpha=0.7, label='Residuales Modelo Logístico')
        plt.axhline(y=0, color='k', linestyle='-', alpha=0.3)  # Línea de referencia en cero
    
    # Calcular y graficar residuales del modelo Gompertz si está disponible
    if fitted_gompertz is not None:
        residuals_gompertz = real_cases - fitted_gompertz
        plt.plot(days, residuals_gompertz, 'r-', alpha=0.7, label='Residuales Modelo Gompertz')
        plt.axhline(y=0, color='k', linestyle='-', alpha=0.3)  # Línea de referencia en cero
    
    # Configuración de la gráfica de residuales
    plt.xlabel('Días desde el primer caso', fontsize=12)
    plt.ylabel('Residuales (Real - Modelo)', fontsize=12)
    plt.title('Análisis de Residuales - Modelos Epidemiológicos', fontsize=14)
    plt.grid(True, alpha=0.3)
    plt.legend(loc='upper right', fontsize=11)
    
    # Ajustar layout y mostrar
    plt.tight_layout()
    plt.show()

def print_model_analysis(results):
    """
    Imprime análisis detallado de los modelos ajustados
    results: diccionario con resultados de la simulación
    """
    # Extraer parámetros y métricas
    params = results['params']
    metrics = results['metrics']
    logistic_params = results['logistic_params']
    gompertz_params = results['gompertz_params']
    
    # Encabezado del análisis
    print("="*70)
    print("ANALISIS DE MODELOS EPIDEMIOLOGICOS - BOLIVIA 2020")
    print("="*70)
    
    # Mostrar métricas de los datos reales
    print("\nDATOS REALES (APROXIMADOS):")
    print(f"Pico de casos: {metrics['peak_value']:.0f} casos")
    
    # Convertir a tipo nativo y calcular fecha del pico
    peak_day = int(metrics['peak_day'])
    peak_date = params['first_case_day'] + timedelta(days=peak_day)
    print(f"Dia del pico: {peak_day} ({peak_date.strftime('%d-%b')})")
    
    print(f"Casos totales aproximados: {metrics['total_cases_approx']:.0f}")
    print(f"Tasa de ataque: {metrics['attack_rate']:.2f}%")
    
    # Análisis del modelo logístico si está disponible
    if logistic_params is not None:
        print("\nMODELO LOGISTICO:")
        print(f"Capacidad de carga (K): {logistic_params[0]:.0f} casos")
        print(f"Tasa de crecimiento (r): {logistic_params[1]:.4f}")
        print(f"Punto de inflexion (t0): {logistic_params[2]:.0f} dias")
        
        # Calcular R² (coeficiente de determinación) para evaluar bondad de ajuste
        ss_res = np.sum((results['real_cases'] - results['fitted_logistic'])**2)  # Suma de cuadrados residual
        ss_tot = np.sum((results['real_cases'] - np.mean(results['real_cases']))**2)  # Suma de cuadrados total
        r_squared = 1 - (ss_res / ss_tot)  # Fórmula de R²
        print(f"R^2: {r_squared:.4f}")  # Mientras más cercano a 1, mejor el ajuste
    
    # Análisis del modelo Gompertz si está disponible
    if gompertz_params is not None:
        print("\nMODELO GOMPERTZ:")
        print(f"Asintota superior (a): {gompertz_params[0]:.0f} casos")
        print(f"Parametro de desplazamiento (b): {gompertz_params[1]:.4f}")
        print(f"Tasa de crecimiento (c): {gompertz_params[2]:.4f}")
        
        # Calcular R² para modelo Gompertz
        ss_res = np.sum((results['real_cases'] - results['fitted_gompertz'])**2)
        ss_tot = np.sum((results['real_cases'] - np.mean(results['real_cases']))**2)
        r_squared = 1 - (ss_res / ss_tot)
        print(f"R^2: {r_squared:.4f}")
    
    # Observaciones generales sobre los resultados
    print("\nOBSERVACIONES:")
    print("Ambos modelos capturan la forma general de la curva epidemica")
    print("El modelo logistico es mas adecuado para epidemias con simetria")
    print("El modelo Gompertz tiene un crecimiento mas rapido y descenso mas lento")
    print("Los residuales muestran donde los modelos no capturan variaciones especificas")

# ============================
# FUNCIÓN PRINCIPAL
# ============================

def main():
    """
    Función principal que orquesta toda la simulación y análisis
    """
    # Encabezado del programa
    print("="*70)
    print("MODELO EPIDEMIOLOGICO COVID-19 BOLIVIA 2020")
    print("USANDO FUNCIONES GENERALES")
    print("="*70)
    
    # Simular la pandemia usando funciones generales
    results = simulate_bolivia_2020_general()
    
    # Imprimir análisis detallado de los modelos
    print_model_analysis(results)
    
    # Generar visualizaciones
    plot_model_comparison(results)  # Gráfica comparativa de modelos
    plot_residuals(results)  # Gráfica de residuales

# Punto de entrada del programa
if __name__ == "__main__":
    main()