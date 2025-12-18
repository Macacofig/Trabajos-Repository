Manejo b�sico de R
#########################
#Primera clase 
1. R es una calculadora

#Primera explicaci�n

# Este simbolo sirve para comentar

1.1 Operaciones b�sicas

Par�ntesis: ( , )
Exponente: ^ o **

3**2
3^2

Divisi�n: /
Multiplicaci�n: *
Suma: +
Resta: -
sqrt(10)#raiz cuadrada

Ejemplo:

(5+3) *(10^2)
(5+3) *(10**2) #el 
3/100


1.2 Objetos


ariel<- 5
ariel

b<- -1
b

c= ariel+b
c

d<-5*9/5 #esta es una operacion
d

1.3 Vectores

x<- c(3,5,7,9,10.5,12,15,13,14,16,18,20,12,12,13,14,15, 20, 21) #"c" es concatenar
x

var(x)# calcula la varianza de la muestra
sd(x)#sd calcula la desviacion estandar de los datos, que es una distancia promedio de los datos respecto a la media

mean(x) #calcula la media aritmetica
summary(x)

help(seq)


cerezas <- seq(from = 4, to = 1520, by = 2)#secuencia de n�meros con intervalo de 2
cerezas

cerezas <- seq(by = 1,from = 0, to = 100)#secuencia de n�meros con intervalo de 2
cerezas

cerezas<-seq(0,100,5)
cerezas


millon <- seq(from = 0, to = 1000000, by = 5)#secuencia de n�meros con intervalo de 2
millon

1.4 Funciones

#R cuenta con millones de funciones para realizar calculo en matem�ticas

help(rnorm)
plantas<-rnorm(n =320, mean = 1000, sd = 500)# numero de plantas reforestadas por municipio en bolivia
plantas
hist(plantas)

mean(): Promedio aritmetico
sd(): Desviaci�n est�ndar
median: Mediana
var(): Varianza
min(): Valor m�nimo
min(): Valor m�nimo
max(): Valor m�ximo
range(): Rango de valores
quantile(): Cuantiles y percentiles
IQR(): Rango intercuart�lico

Ejemplo:

sum(millon) #suma
range(millon)#rango de valores
mean(millon) # media
median(millon)
var(millon) # varianza
sd(millon)# desviaci�n estandar
coef_var<- sd (millon)/mean(millon)# coeficiente de variaci�n
coef_var # esto es el objeto que calcula coeficiente de variaci�n

#Hasta esta parte los estudiantes deben hacer una tarea con una secuencia de datos (vector)
y deben presentarlo en un informe de maximo 1 pagina (anexos, script).

# R tiene su biblioteca de ayuda

help(mean)
help(sd)
help(seq)

seq(0, 1, length.out = 11)
seq(1, 6, by = 3)

hist(millon)

# R tiene paquetes de analisis

library(stats)#llama al paquete de an�lisis
citation("stats")
install.packages("car")# esto es un paquete de funciones estadisticas complementarias
citation("car")
library(car)

# Crea base de datos

d <- seq(from = 0, to = 10, by = 1)
e <- seq(from = -10, to = 0, by = 1)
d
e
matriz<-cbind(d,e)# la funci�n cbind combina vectores en una matriz de datos
matriz

f<- d*e
f
matriz2<-cbind(d,e,f)
matriz2


# R importa datos (conjunto de variables)


base<-read.table("datos_prueba.txt", header=TRUE,   na.strings = "NA")# Cargado de datos
base
attach(base)#sirve para llamar a las variables por su nombre
summary(Ingresos_mensuales)#resumen
mean(Ingresos_mensuales)# promedio
sd(Ingresos_mensuales)# error estandar
error<- sd(Ingresos_mensuales)/sqrt(length(Ingresos_mensuales))# length ayuda a contar numero de datos en el vector
error


#R puede importar datos desde Excel

install.packages("readxl")#paquete para cargar base de datos en excel
library(readxl) #Cargamos el paquete
citation("readxl")
base_2<- read_excel("datos_prueba.xlsx", sheet = 1)
base_2
attach(base_2)
mean(Ingresos_mensuales)
summary(base_2$Ingresos_mensuales)# El simbolo $ nos permite llamar a la variable de una tabla o matriz por su nombre

#R genera datos

help(rnorm)
rs<-rnorm(n=100, mean = 50, sd = 6)#genera datos aleatorios con distribuci�n normal
rs
hist(rs, col="green")

s<-rnorm(n=100, mean = 40, sd = 4)#el sd es la desviaci�n estandar
s

cuadro<-data.frame(rs,s)
cuadro

#R genera figuras 

boxplot(cuadro)
boxplot(cuadro$r, main= "r",col ="yellow")
boxplot (cuadro$s,main = "s", col = "gray")

hist(cuadro$rs, col= "green")
hist(cuadro$s, col = "blue")

stem(cuadro$r)#grafico de tallos y hojas
stem(cuadro$r)

##Agrupar gr�ficos

par(mfrow=c(3,2))# el 2,2 indica dos filas y 2 columnas de gr�ficos

# R puedes exportar datos 

write.table(cuadro, file="clipboard")# para copiar datos a otra base de datos, p. ej. Excel

# R exportar figuras

pdf("fig.pdf")
boxplot(cuadro)
dev.off()


png(filename="fig.png")
boxplot(cuadro)
dev.off()

# R contiene datos

data()

women
attach(women)  
women$height
weight

#Tarea grupal

1. Con una base de datos cualquier de R elegir dos variables y realizar
estadistica descriptiva en R (media, mediana, moda, rango, valor minimo, valor maximo,
1er, 2do, 3er, 4to cuartil.
2. Hacer un boxplot para ambas variables
3. Hacer un histograma para ambas variables
4. Interpretar resultados
5. Presentar el Script en R la proxima clase.


#Literatura sugerida:

https://osoramirez.github.io/R_Para_Biologos/distribucion-normal-estandar.html

https://bookdown.org/jboscomendoza/r-principiantes4/funciones-introduccion-basica.html

