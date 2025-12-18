# ---- 1. DATOS INICIALES ----
Z <- 1.96          # 95% de confianza
E <- 2             # Error permitido en kg CO2
sigma <- 6.93      # Desviación estándar
N <- 4000          # Población total (estudiantes)
promedio <- 12.54  # Promedio estimado de emisión CO2 (kg/persona-día)

# ---- 2. CÁLCULO DEL TAMAÑO DE MUESTRA ----
# Fórmula 1: n0 = (Z^2 * sigma^2) / E^2
n0 <- (Z^2 * sigma^2) / (E^2)

# Fórmula 2 (corrección por población finita)
n <- (N * n0) / (N + n0 - 1)

# Formula 3 (livanco)
n1 <- sigma^2/((E^2/Z^2)+(sigma^2/(N-1)))

cat("Tamaño de muestra preliminar (n0):", n0, "\n")
cat("Tamaño de muestra ajustado (n):", n, "\n")
cat("Tamaño de muestra 2 (n1):", n1, "\n")

# ---- 3. LECTURA DE DATOS CSV ----
datos <- read.csv("Datos.csv", sep = ",", header = TRUE)

print("Vista previa de los datos:")
print(datos)

# ---- 4. TABLAS DE FRECUENCIAS ----
print("Tabla de frecuencias por carrera:")
print(table(datos$Carrera))
print("Tabla de frecuencias por transporte:")
print(table(datos$Transporte))
print("Tabla de frecuencias por tipo transporte (privado,publico):")
print(table(datos$Tipo))
print("Tabla de frecuencias por combustible:")
print(table(datos$Combustible))

# ---- 5. GRÁFICOS ----
# Histograma del tiempo de viaje
hist(as.numeric(datos$Tiempo),
     main = "Histograma del Tiempo de viaje",
     xlab = "Tiempo (minutos)",
     col = "lightblue", border = "black")

# Gráfico de barras por tipo de transporte
barplot(table(datos$Transporte),
        main = "Frecuencia por tipo de transporte",
        ylab = "Frecuencia", col = "lightgreen")

# Convertir variables numéricas
datos$Tiempo <- as.numeric(datos$Tiempo)
datos$Distancia <- as.numeric(gsub(",", ".", datos$Distancia))  # cambia coma por punto

# ---- 7. ASIGNACIÓN DE EMISIÓN AJUSTADA POR DISTANCIA Y COMBUSTIBLE ----
# Consumo promedio por km según transporte (gal/km)
consumo_km <- list(
  auto = 0.04,
  motocicleta = 0.02,
  trufi = 0.08,
  microbus = 0.15,
  taxi = 0.05,
  pie = 0,
  ninguno = 0,
  otro = 0.00
)

# Factor de emisión por combustible (kg CO2/gal)
factor_emision <- list(
  gasolina = 8.887,
  diesel = 10.180,
  ninguno = 0
)

datos$Emision_CO2 <- NA

for (i in 1:nrow(datos)) {
  transporte <- tolower(datos$Transporte[i])
  combustible <- datos$Combustible[i]
  distancia <- datos$Distancia[i]
  frecuencia <- datos$Frecuencia[i]
  
  consumo <- ifelse(!is.null(consumo_km[[transporte]]), consumo_km[[transporte]], 0)
  factor <- ifelse(!is.null(factor_emision[[combustible]]), factor_emision[[combustible]], 0)
  
  # Emisión diaria ajustada
  datos$Emision_CO2[i] <- distancia * frecuencia * consumo * factor
}

# ---- 8. ESTADÍSTICOS DESCRIPTIVOS GENERALES ----
cat("\n--- ESTADÍSTICOS GENERALES ---\n")
media_general <- mean(datos$Emision_CO2, na.rm = TRUE)
desv_general <- sd(datos$Emision_CO2, na.rm = TRUE)
var_general <- var(datos$Emision_CO2, na.rm = TRUE)
cat("Promedio general de emisión:", round(media_general, 2), "kg/persona-día\n")
cat("Desviación estándar:", round(desv_general, 2), "\n")
cat("Varianza:", round(var_general, 2), "\n")

# ---- 9. GRÁFICOS DE EMISIÓN ----
hist(datos$Emision_CO2,
     main = "Distribución de Emisiones de CO2 Ajustadas",
     xlab = "Kg CO2/persona-día",
     col = "lightblue", border = "black")

barplot(tapply(datos$Emision_CO2, datos$Transporte, mean, na.rm = TRUE),
        main = "Emisión promedio ajustada por tipo de transporte",
        ylab = "Kg CO2/persona-día", col = "lightcoral")

# ---- 10. INTERVALO DE CONFIANZA GENERAL (95%) ----
n_muestra <- length(na.omit(datos$Emision_CO2))
error <- Z * (desv_general / sqrt(n_muestra))
IC_inf <- media_general - error
IC_sup <- media_general + error
cat("\nIntervalo de confianza al 95% (general): [",
    round(IC_inf, 2), ",", round(IC_sup, 2), "] kg/persona-día\n")

# ---- 11. ESTIMACIÓN POR ESTRATOS (TIPO DE TRANSPORTE) ----
cat("\n--- ESTIMACIÓN POR ESTRATOS (95%) ---\n")
transportes <- unique(datos$Transporte)
cat(sprintf("%-12s %-10s %-10s %-10s %-10s\n",
            "Transporte", "Media", "Desv", "n", "IC95%"))

for (t in transportes) {
  sub <- datos[datos$Transporte == t, ]
  if (nrow(sub) > 1 && sum(!is.na(sub$Emision_CO2)) > 1) {
    m <- mean(sub$Emision_CO2, na.rm = TRUE)
    s <- sd(sub$Emision_CO2, na.rm = TRUE)
    n_i <- nrow(sub)
    e_i <- Z * (s / sqrt(n_i))
    cat(sprintf("%-12s %-10.2f %-10.2f %-10d [%.2f, %.2f]\n",
                t, m, s, n_i, m - e_i, m + e_i))
  }
}

# Histograma de todas las emisiones
hist(datos$Emision_CO2,
     main = "Distribución de Emisiones de CO2 por Estudiante",
     xlab = "Kg CO2/persona·día",
     ylab = "Número de estudiantes",
     col = "lightblue",
     border = "black")

# ---- 12. DEMOSTRACIÓN DEL TEOREMA DEL LÍMITE CENTRAL (TLC) ----

set.seed(123)  # Para reproducibilidad

# Eliminamos valores NA de Emision_CO2
valores <- na.omit(datos$Emision_CO2)

# Parámetros
n_muestra_tlc <- 30        # tamaño de cada muestra
num_muestras_tlc <- 1000   # cantidad de medias muestrales a generar

# Simulación: medias de muchas muestras aleatorias
medias_muestrales <- replicate(num_muestras_tlc, mean(sample(valores, n_muestra_tlc, replace = TRUE)))

# Gráfico comparativo
par(mfrow = c(1, 2))

# 1️Distribución original de emisiones
hist(valores,
     main = "Distribución original de Emisiones CO2",
     xlab = "Kg CO2/persona-día",
     col = "lightcoral", border = "black")

# 2️Distribución de las medias muestrales
hist(medias_muestrales,
     main = "Distribución de las Medias (TLC)",
     xlab = "Media muestral de Emisión CO2",
     col = "lightblue", border = "black")

# Línea vertical en la media
abline(v = mean(medias_muestrales), col = "red", lwd = 2, lty = 2)

# Restaurar formato de gráficos
par(mfrow = c(1, 1))

cat("\n--- DEMOSTRACIÓN DEL TEOREMA DEL LÍMITE CENTRAL ---\n")
cat("Tamaño de muestra por simulación:", n_muestra_tlc, "\n")
cat("Cantidad de muestras generadas:", num_muestras_tlc, "\n")
cat("Media de las medias simuladas:", round(mean(medias_muestrales), 2), "\n")
cat("Desviación estándar de las medias simuladas:", round(sd(medias_muestrales), 2), "\n")
