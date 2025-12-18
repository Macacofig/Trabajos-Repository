# MATEO GAEL FIGUEROA CHAVEZ

# EJEMPLO 1 : Velocidad de autos en una autopista (km/h)
# media = 100 km/h , Desviación estándar = 18 km/h

# 1. Generamos datos simulados con distribución normal
set.seed(123)  
datos <- rnorm(n = 1000, mean = 100, sd = 18)

# 2. Histograma con densidad
hist(datos, breaks = 30, probability = TRUE, col = "lightgray",
     main = "Velocidad de autos en una autopista",
     xlab = "Velocidad (km/h)", ylab = "Densidad")

# 3. Curva de densidad teórica
x <- seq(min(datos), max(datos), length = 100)
lines(x, dnorm(x, mean = 100, sd = 18), col = "blue", lwd = 2)

# 4. Cálculo de probabilidades con pnorm
# a) Probabilidad de que un auto vaya MÁS RÁPIDO que 130 km/h
prob_mayor_130 <- pnorm(130, mean = 100, sd = 18, lower.tail = FALSE)

# b) Probabilidad de que un auto vaya MÁS LENTO que 80 km/h
prob_menor_80 <- pnorm(80, mean = 100, sd = 18, lower.tail = TRUE)

# c) Probabilidad de que la velocidad esté ENTRE 90 y 110 km/h
prob_entre_90_110 <- pnorm(110, mean = 100, sd = 18) - pnorm(90, mean = 100, sd = 18)

# Mostramos resultados
prob_mayor_130
prob_menor_80
prob_entre_90_110

# Sombrear áreas en el gráfico para explicar
# a) Más rápido que 130 (rojo)
x1 <- seq(130, max(x), length = 100)
polygon(c(x1, rev(x1)), c(dnorm(x1, 100, 18), rep(0, length(x1))), col = rgb(1,0,0,0.3))

# b) Más lento que 80 (verde)
x2 <- seq(min(x), 80, length = 100)
polygon(c(x2, rev(x2)), c(dnorm(x2, 100, 18), rep(0, length(x2))), col = rgb(0,1,0,0.3))

# c) Entre 90 y 110 (azul)
x3 <- seq(90, 110, length = 100)
polygon(c(x3, rev(x3)), c(dnorm(x3, 100, 18), rep(0, length(x3))), col = rgb(0,0,1,0.3))
