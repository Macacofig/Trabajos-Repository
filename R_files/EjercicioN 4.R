# 1. Simulación reproducible
set.seed(42)
tomates <- rnorm(1000, mean = 150, sd = 20)

# 2. Histograma con densidad teórica
hist(tomates, breaks = 30, probability = TRUE,
     main = "Distribución de pesos de tomates",
     xlab = "Peso (g)", col = "gray", border = "white")

# Curva teórica
x <- seq(min(tomates), max(tomates), length = 200)
lines(x, dnorm(x, mean = 150, sd = 20), col = "red", lwd = 2)

# 3. Probabilidades con pnorm
prob_menor_120 <- pnorm(120, mean = 150, sd = 20)
prob_entre <- pnorm(170, mean = 150, sd = 20, lower.tail = TRUE) - pnorm(120, mean = 150, sd = 20, lower.tail = TRUE)

# P(X <= 120) Zona de datos que son..
prob_menor_120
# P(120 <= X <= 170) Zona de datos que son..
prob_entre

# 4. Percentiles con qnorm

# Percentil 10, 50 y 90
p10 <- qnorm(0.10, mean = 150, sd = 20)
p50 <- qnorm(0.50, mean = 150, sd = 20) 
p90 <- qnorm(0.90, mean = 150, sd = 20)

# Valor tal que 10% de los datos son <= que...
p10
# Valor tal que 50% de los datos son <= que... 
p50
# Valor tal que 90% de los datos son <= que...
p90

# 5. Gráficas ilustrativas

# Sombrear área P(X <= 120)
x1 <- seq(min(x),120, length = 100)
polygon(c(x1,rev(x1)), c(dnorm(x1,150,20), rep(0,length(x1))), col = rgb(1,0,0,0.3))

# Sombrear área P(120 <= X <= 170)
x2 <- seq(120,170, length = 100)
polygon(c(x2,rev(x2)), c(dnorm(x2,150,20), rep(0,length(x2))), col = rgb(0,1,0,0.3))


# Agregar líneas verticales en percentiles
abline(v = c(p10, p50, p90), col = c("purple", "blue", "darkgreen"),
       lty = 2, lwd = 2)

# Cuadro de caracteristicas

legend(x = 178, y = 0.02,
       legend = c("P(X<=120) tomates", "P(120<=X<=170) tomates", "10%" , "50%", "90%"),
       fill = c(
         rgb(255, 0, 0, maxColorValue=255),      # red
         rgb(0, 128, 0, maxColorValue=255),      # green
         rgb(128, 0, 128, maxColorValue=255),    # purple
         rgb(0, 0, 255, maxColorValue=255),      # blue
         rgb(0, 100, 0, maxColorValue=255)       # darkgreen
       ),
       border = NA,xpd = TRUE)

# Cantidad de datos a 1 desviacion a cada lado son 68%
# Cantidad de datos a 2 desviaciones a cada lado son 95.5%
# Cantidad de datos a 3 desviaciones a cada lado son 99.7%