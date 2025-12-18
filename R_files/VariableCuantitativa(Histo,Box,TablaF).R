#Una variable cuantitativa continua es aquella que puede tomar cualquier valor dentro de un rango,incluidos números decimales.

# Definimos la variable "altura" en centímetros

set.seed(123) # para reproducibilidad
altura <- rnorm(100, mean = 170, sd = 10) 

print(altura)

# Histograma
hist(altura,
     main = "Histograma de Alturas",
     xlab = "Altura (cm)",
     col = "skyblue",
     border = "black")

# Boxplot
boxplot(altura,
        main = "Boxplot de Alturas",
        ylab = "Altura (cm)",
        col = "lightgreen",
        border = "darkgreen")	

# Definir intervalos
intervalos <- seq(floor(min(altura)), ceiling(max(altura)), by = 5)

print(intervalos)

# Tabla de frecuencia absoluta
frec_abs <- table(cut(altura, breaks = intervalos))

print(frec_abs)


