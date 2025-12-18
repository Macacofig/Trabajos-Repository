# Número de clientes que llegan a una tienda por hora
# Media = 40 clientes/hora , Desviacion Estandar = 6.32 clientes/hora .

# 1) Simulación con distribución normal
set.seed(789)
clientes <- rnorm(n = 1000, mean = 40, sd = 6.32)

# 2) Histograma con densidad
hist(clientes, breaks = 30, probability = TRUE, col = "lightgray",
     main = "Clientes que llegan por hora (aprox. Normal)",
     xlab = "Clientes por hora", ylab = "Densidad")

----------------------------------------------------------------------

# 3) Curva de densidad teórica
x <- seq(min(clientes), max(clientes), length = 100)
lines(x, dnorm(x, mean = 40, sd = 6.32), col = "blue", lwd = 2)

----------------------------------------------------------------------

# 4) Probabilidades con pnorm
# a) Probabilidad de MÁS de 50 clientes en una hora
prob_mayor_50 <- pnorm(50, mean = 40, sd = 6.32, lower.tail = FALSE)

# b) Probabilidad de MENOS de 30 clientes en una hora
prob_menor_30 <- pnorm(30, mean = 40, sd = 6.32, lower.tail = TRUE)

# c) Probabilidad de estar ENTRE 35 y 45 clientes
prob_entre_35_45 <- pnorm(45, mean = 40, sd = 6.32) - pnorm(35, mean = 40, sd = 6.32)

# Mostrar resultados
prob_mayor_50
prob_menor_30
prob_entre_35_45

----------------------------------------------------------------------

# Sombrear áreas en el gráfico para explicar
# a) > 50 (rojo)
x1 <- seq(50, max(x), length = 100)
polygon(c(x1, rev(x1)), c(dnorm(x1, 40, 6.32), rep(0, length(x1))), col = rgb(1, 0, 0, 0.3))

# b) < 30 (verde)
x2 <- seq(min(x), 30, length = 100)
polygon(c(x2, rev(x2)), c(dnorm(x2, 40, 6.32), rep(0, length(x2))), col = rgb(0,1,0,0.3))

# c) 35 a 45 (azul)
x3 <- seq(35, 45, length = 100)
polygon(c(x3, rev(x3)), c(dnorm(x3, 40, 6.32), rep(0, length(x3))), col = rgb(0,0,1,0.3))
