# Importacion de datos

datos <- read.csv("encuesta.csv", header = TRUE, sep = ",")

# Ver datos obtenidos
datos


# DATOS PRINCIPALES

# Densidades empiricas
EmpirTerraza <- density(datos$terraza)
EmpirBiblioteca <- density(datos$biblioteca)
EmpirLlegada <- density(datos$llegada)
# Densidades teoricas
# Parametros
TerMean <- mean(datos$terraza)
TerSD <- sd(datos$terraza)
BilMean <- mean(datos$biblioteca)
BilSD <- sd(datos$biblioteca)
LleMean <- mean(datos$llegada)
LleSD <- sd(datos$llegada)
# Secuencias
xter <- seq(min(datos$terraza), max(datos$terraza), length=100)
xbil <- seq(min(datos$biblioteca), max(datos$biblioteca), length=100)
xlle <- seq(min(datos$llegada), max(datos$llegada), length=100)

# ESTADISTICA DESCRIPTIVA 

summary(datos)

# Media, mediana, varianza y desviación estandar

# Numero de veces de visita a la terraza
mean(datos$terraza); median(datos$terraza); var(datos$terraza); sd(datos$terraza)
# Tiempo en horas de estar en la biblioteca
mean(datos$biblioteca); median(datos$biblioteca); var(datos$biblioteca); sd(datos$biblioteca)
# Tiempo en minutos en llegar a la universidad
mean(datos$llegada); median(datos$llegada); var(datos$llegada); sd(datos$llegada)


# Tabla de frecuencias absolutas
tabla_terraza <- table(datos$terraza)
tabla_terraza

# Porcentajes
prop.table(tabla_terraza) * 100

# Frecuencia acumulada
cumsum(tabla_terraza)

intervalos_biblio <- seq(0, ceiling(max(datos$biblioteca)), by = 1)
freq_biblio <- table(cut(datos$biblioteca, breaks = intervalos_biblio, right = FALSE))
freq_biblio
prop.table(freq_biblio) * 100
cumsum(freq_biblio)

intervalos_lleg <- seq(0, ceiling(max(datos$llegada)/5)*5 + 10, by = 5)
freq_lleg <- table(cut(datos$llegada, breaks = intervalos_lleg, right = FALSE))
freq_lleg
prop.table(freq_lleg) * 100
cumsum(freq_lleg)

# HISTOGRAMAS

windows()
par(mfrow=c(3,1))

# Histograma con funcion de densidad empirica y teorica

# Terraza
hist(datos$terraza, main="Histograma: Visitas a la terraza",prob = TRUE, col="gray", xlab="Veces por semana")
lines(density(datos$terraza), col="red", lwd=2)

lines(xter , dnorm(xter , mean=TerMean , sd=TerSD ), col="blue", lwd=2, lty=2)  
legend("topright", legend=c("Empírica", "Normal teórica"), col=c("red","blue"), lwd=2, lty=c(1,2))

# Biblioteca
hist(datos$biblioteca, main="Histograma: Horas en biblioteca",prob = TRUE, col="gray", xlab="Horas")
lines(density(datos$biblioteca),col="orange", lwd=2)

lines(xbil , dnorm(xbil , mean=BilMean , sd=BilSD ), col="blue", lwd=2, lty=2)  
legend("topright", legend=c("Empírica", "Normal teórica"), col=c("orange","blue"), lwd=2, lty=c(1,2))


# Llegada
hist(datos$llegada, main="Histograma: Tiempo de llegada",prob = TRUE, col="gray", xlab="Minutos")
lines(density(datos$llegada), col="green", lwd=2)

lines(xlle, dnorm(xlle, mean=LleMean , sd=LleSD ), col="blue", lwd=2, lty=2) 
legend("topright", legend=c("Empírica", "Normal teórica"), col=c("green","blue"), lwd=2, lty=c(1,2))

par(mfrow=c(1,1))

# BOXPLOTS

windows()
par(mfrow=c(1,3))

boxplot(datos$terraza, main="Boxplot terraza", col="skyblue")
boxplot(datos$biblioteca, main="Boxplot biblioteca", col="orange")
boxplot(datos$llegada, main="Boxplot tiempo universidad", col="lightgreen")

par(mfrow=c(1,1))

# GRAFICO QQ (normalidad)

windows()
qqnorm(datos$terraza,main = "Visitas terraza", ); qqline(datos$terraza, col="red")
windows()
qqnorm(datos$biblioteca, main = "Horas en la biblioteca"); qqline(datos$biblioteca, col="red")
windows()
qqnorm(datos$llegada, main = "Minutos para llegar U"); qqline(datos$llegada, col="red")




# EJERCICIOS ESTADISTICOS
 



# Terraza

# EJERCICIOS QNORM

# 90% de los datos bajo que numero estan
q90 <- qnorm(0.9, mean=TerMean, sd=TerSD)

q90_emp <- quantile(datos$terraza, probs = 0.9)


# 50% de los datos bajo que numero estan
q50 <- qnorm(0.5, mean=TerMean, sd=TerSD)

q50_emp <- quantile(datos$terraza, probs = 0.5)


# 30% de los datos bajo que numero estan
q30 <- qnorm(0.3, mean=TerMean, sd=TerSD)

q30_emp <- quantile(datos$terraza, probs = 0.3)


# EMPIRICO
windows()
par(mfrow=c(1,2)) 
hist(datos$terraza, main="Empirica",prob = TRUE, col="gray", xlab="Veces por semana")
lines(density(datos$terraza), col="red", lwd=2)

abline(v=q90_emp, col="blue", lwd=2, lty=2)
abline(v=q30_emp, col="blue", lwd=2, lty=2)
abline(v=q50_emp, col="blue", lwd=2, lty=2)

legend("topright", 
       legend = c(
         sprintf("30 porc = %.3f", q30_emp),
         sprintf("50 porc = %.3f", q50_emp),
         sprintf("90 porc = %.3f", q90_emp)
       ),
       cex = 0.8,   # tamaño del texto   
       bty = "o",   # tipo de borde ("o" es el default, "n" sin borde)          
       inset = 0.02)# separa un poco la leyenda del borde del gráfico 

# TEORICO
hist(datos$terraza, main="Teorica",prob = TRUE, col="gray", xlab="Veces por semana")
lines(xter , dnorm(xter , mean=TerMean , sd=TerSD ), col="blue", lwd=2, lty=2)  

abline(v=q90, col="red", lwd=2, lty=2)
abline(v=q30, col="red", lwd=2, lty=2)
abline(v=q50, col="red", lwd=2, lty=2)

legend("topright", 
       legend = c(
         sprintf("30 porc = %.3f", q30),
         sprintf("50 porc = %.3f", q50),
         sprintf("90 porc = %.3f", q90)
       ),
       cex = 0.8,   # tamaño del texto   
       bty = "o",   # tipo de borde ("o" es el default, "n" sin borde)          
       inset = 0.02)# separa un poco la leyenda del borde del gráfico 




# Biblioteca

# EJERCICIOS PNORM

# probabilidad de pasar <= 1 horas en biblioteca
prob_1h <- pnorm(1, mean=BilMean, sd=BilSD)

dx <- diff(EmpirBiblioteca$x[1:2])      # ancho de paso aproximado
prob_emp <- sum(EmpirBiblioteca$y[EmpirBiblioteca$x >= 0 & EmpirBiblioteca$x <= 1] * dx)


# probabilidad de pasar > 4 horas en la biblioteca
prob_4h <- pnorm(4, mean=BilMean, sd=BilSD,lower.tail = FALSE)

dx <- diff(EmpirBiblioteca$x[1:2])      # ancho de paso aproximado
prob_emp4 <- sum(EmpirBiblioteca$y[EmpirBiblioteca$x > 4 & EmpirBiblioteca$x <= 5] * dx)


# probabilidad de pasar ende 2 y 3 horas en la biblioteca
prob_23h <- pnorm(3, mean=BilMean, sd=BilSD)- pnorm(2, mean=BilMean, sd=BilSD)

dx <- diff(EmpirBiblioteca$x[1:2])      # ancho de paso aproximado
prob_emp23 <- sum(EmpirBiblioteca$y[EmpirBiblioteca$x >= 2 & EmpirBiblioteca$x <= 3] * dx)


# EMPIRICO
windows()
par(mfrow=c(1,2)) 
hist(datos$biblioteca, main="Empirico",prob = TRUE, col="gray", xlab="Horas")
lines(density(datos$biblioteca,from=0),col="orange", lwd=2)

x_shade <- EmpirBiblioteca$x[EmpirBiblioteca$x >= 0 & EmpirBiblioteca$x <= 1] 
y_shade <- EmpirBiblioteca$y[EmpirBiblioteca$x >= 0 & EmpirBiblioteca$x <= 1] 
polygon(c(x_shade, rev(x_shade)), c(y_shade, rep(0,length(y_shade))), col="red")

x_shade4 <- EmpirBiblioteca$x[EmpirBiblioteca$x > 4 & EmpirBiblioteca$x <= 5] 
y_shade4 <- EmpirBiblioteca$y[EmpirBiblioteca$x > 4 & EmpirBiblioteca$x <= 5] 
polygon(c(x_shade4 , rev(x_shade4 )), c(y_shade4 , rep(0,length(y_shade4 ))), col="yellow")

x_shade23 <- EmpirBiblioteca$x[EmpirBiblioteca$x >= 2 & EmpirBiblioteca$x <= 3] 
y_shade23 <- EmpirBiblioteca$y[EmpirBiblioteca$x >= 2 & EmpirBiblioteca$x <= 3] 
polygon(c(x_shade23 , rev(x_shade23 )), c(y_shade23 , rep(0,length(y_shade23 ))), col="brown")

legend("topright", 
       legend = c(
         sprintf("P(X <= 1) = %.3f", prob_emp),
         sprintf("P(X > 4) = %.3f", prob_emp4),
         sprintf("P(2 <= X <= 3) = %.3f", prob_emp23)
       ),
       cex = 0.8,   # tamaño del texto   
       bty = "o",   # tipo de borde ("o" es el default, "n" sin borde)          
       inset = 0.02)# separa un poco la leyenda del borde del gráfico 

# TEORICO
hist(datos$biblioteca, main="Teorico",prob = TRUE, col="gray", xlab="Horas")
lines(xbil , dnorm(xbil , mean=BilMean , sd=BilSD ), col="blue", lwd=2, lty=2)  

xbil2<- seq(min(xbil),1, length= 100)
polygon(c(xbil2,rev(xbil2)),c(dnorm(xbil2,BilMean,BilSD), rep(0,length(xbil2))), col = "green")

xbil3<- seq(4,max(xbil), length= 100)
polygon(c(xbil3,rev(xbil3)),c(dnorm(xbil3,BilMean,BilSD), rep(0,length(xbil3))), col = "cyan")

xbil4<- seq(2,3, length= 100)
polygon(c(xbil4,rev(xbil4)),c(dnorm(xbil4,BilMean,BilSD), rep(0,length(xbil4))), col = "darkgreen")
legend("topright", 
       legend = c(
         sprintf("P(X <= 1) = %.3f", prob_1h),
         sprintf("P(X > 4) = %.3f", prob_4h),
         sprintf("P(2 <= X <= 3) = %.3f", prob_23h)
       ),
       cex = 0.8,   # tamaño del texto   
       bty = "o",   # tipo de borde ("o" es el default, "n" sin borde)          
       inset = 0.02)# separa un poco la leyenda del borde del gráfico 





# Llegada

# EJERCICIOS CON DNORM

#Altura en el dato 30
y_emp1 <- approx(EmpirLlegada$x, EmpirLlegada$y, xout = 30)$y
y_teo1 <- dnorm(30, mean=LleMean, sd=LleSD)

#Altura en el dato 10
y_emp2 <- approx(EmpirLlegada$x, EmpirLlegada$y, xout = 10)$y
y_teo2 <- dnorm(10, mean=LleMean, sd=LleSD)
#Altura en el dato 20
y_emp3 <- approx(EmpirLlegada$x, EmpirLlegada$y, xout = 20)$y
y_teo3 <- dnorm(20, mean=LleMean, sd=LleSD)
windows()
par(mfrow=c(1,2))
hist(datos$llegada, main="Empirico",prob = TRUE, col="gray", xlab="Minutos")
lines(density(datos$llegada), col="green", lwd=2)
points(30, y_emp1, col="red", pch=19)
points(10, y_emp2, col="red", pch=19)
points(20, y_emp3, col="red", pch=19)
legend("topright", 
       legend = c(
         sprintf("Altura de 10 = %.3f", y_emp1),
         sprintf("Altura de 20 = %.3f", y_emp2),
         sprintf("Altura de 30 = %.3f", y_emp3)
       ),
       cex = 0.8,   # tamaño del texto   
       bty = "o",   # tipo de borde ("o" es el default, "n" sin borde)          
       inset = 0.02)# separa un poco la leyenda del borde del gráfico 

hist(datos$llegada, main="Teorico",prob = TRUE, col="gray", xlab="Minutos")
lines(xlle, dnorm(xlle, mean=LleMean , sd=LleSD ), col="blue", lwd=2, lty=2) 
points(30, y_teo1, col="red", pch=19)  
points(10, y_teo2, col="red", pch=19)
points(20, y_teo3, col="red", pch=19)
legend("topright", 
       legend = c(
         sprintf("Altura de 10 = %.3f", y_teo1),
         sprintf("Altura de 20 = %.3f", y_teo2),
         sprintf("Altura de 30 = %.3f", y_teo3)
       ),
       cex = 0.8,   # tamaño del texto   
       bty = "o",   # tipo de borde ("o" es el default, "n" sin borde)          
       inset = 0.02)# separa un poco la leyenda del borde del gráfico




# TLC ( TEORIA DEL LIMITE CENTRAL )

set.seed(123)  # para reproducibilidad

# Número de simulaciones y tamaño de muestra
B <- 1000    # cantidad de muestras
n <- 10      # tamaño de cada muestra

# TERRAZA

windows()
# Guardamos las medias muestrales
medias_terraza <- replicate(B, mean(sample(datos$terraza, n, replace = TRUE)))

# Graficamos
hist(medias_terraza, probability = TRUE, col = "lightblue",
     main = "Distribución de las medias muestrales (Terraza)",
     xlab = "Medias muestrales")

# Superponemos densidad empírica de las medias
lines(density(medias_terraza), col="red", lwd=2)

# Superponemos la normal teórica según TLC
mu <- mean(datos$terraza)
sigma <- sd(datos$terraza) / sqrt(n)
curve(dnorm(x, mean=mu, sd=sigma), add=TRUE, col="blue", lwd=2, lty=2)

legend("topright", legend=c("Densidad empírica", "Normal teórica"),
       col=c("red","blue"), lwd=2, lty=c(1,2)) 

# BIBLIOTECA

windows()
# Guardamos las medias muestrales
medias_biblioteca<- replicate(B, mean(sample(datos$biblioteca, n, replace = TRUE)))

# Graficamos
hist(medias_biblioteca, probability = TRUE, col = "lightblue",
     main = "Distribución de las medias muestrales (Biblioteca)",
     xlab = "Medias muestrales")

# Superponemos densidad empírica de las medias
lines(density(medias_biblioteca), col="red", lwd=2)

# Superponemos la normal teórica según TLC
mu <- mean(datos$biblioteca)
sigma <- sd(datos$biblioteca) / sqrt(n)
curve(dnorm(x, mean=mu, sd=sigma), add=TRUE, col="blue", lwd=2, lty=2)

legend("topright", legend=c("Densidad empírica", "Normal teórica"),
       col=c("red","blue"), lwd=2, lty=c(1,2))

# LLEGADA

windows()
# Guardamos las medias muestrales
medias_llegada<- replicate(B, mean(sample(datos$llegada, n, replace = TRUE)))

# Graficamos
hist(medias_llegada, probability = TRUE, col = "lightblue",
     main = "Distribución de las medias muestrales (Llegada)",
     xlab = "Medias muestrales")

# Superponemos densidad empírica de las medias
lines(density(medias_llegada), col="red", lwd=2)

# Superponemos la normal teórica según TLC
mu <- mean(datos$llegada)
sigma <- sd(datos$llegada) / sqrt(n)
curve(dnorm(x, mean=mu, sd=sigma), add=TRUE, col="blue", lwd=2, lty=2)

legend("topright", legend=c("Densidad empírica", "Normal teórica"),
       col=c("red","blue"), lwd=2, lty=c(1,2))
