# Tiempo de atención en un banco
# EJEMPLO 2 : Tiempo de atención en un banco (minutos)
# media: 15 min, Desviación estándar: 3 min

# 1. Simulamos datos con distribución normal
set.seed(456)  
tiempos <- rnorm(n = 1000, mean = 15, sd = 3)
tiempos

# 2. Histograma con densidad
hist(tiempos, breaks = 30, probability = TRUE, col = "lightgray",
     main = "Tiempo de atención en un banco",
     xlab = "Tiempo (minutos)", ylab = "Densidad")

----------------------------------------------------------------------

# 3. Curva de densidad teórica
x <- seq(min(tiempos), max(tiempos), length = 100)
lines(x, dnorm(x, mean = 15, sd = 3), col = "blue", lwd = 2)

----------------------------------------------------------------------

# 4. Cálculo de probabilidades
# a) Probabilidad de que un cliente tarde MÁS de 20 minutos
prob_mayor_20 <- pnorm(20, mean = 15, sd = 3, lower.tail = FALSE)

# b) Probabilidad de que un cliente tarde MENOS de 10 minutos
prob_menor_10 <- pnorm(10, mean = 15, sd = 3, lower.tail = TRUE)

# c) Probabilidad de que el tiempo esté ENTRE 13 y 17 minutos
prob_entre_13_17 <- pnorm(17, mean = 15, sd = 3) - pnorm(13, mean = 15, sd = 3)

# Mostramos resultados
prob_mayor_20
prob_menor_10
prob_entre_13_17

----------------------------------------------------------------------

# Sombrear áreas en el gráfico para explicar
# a) Más de 20 min (rojo)
x1 <- seq(20, max(x), length = 100)
polygon(c(x1, rev(x1)), c(dnorm(x1, 15, 3), rep(0, length(x1))), col = rgb(1,0,0,0.3))

# b) Menos de 10 min (verde)
x2 <- seq(min(x), 10, length = 100)
polygon(c(x2, rev(x2)), c(dnorm(x2, 15, 3), rep(0, length(x2))), col = rgb(0,1,0,0.3))

# c) Entre 13 y 17 min (azul)
x3 <- seq(13, 17, length = 100)
polygon(c(x3, rev(x3)), c(dnorm(x3, 15, 3), rep(0, length(x3))), col = rgb(0,0,1,0.3))
