#Estimación de peso de gatos en Cochabamba (95% de confianza)

#El nivel de confianza es la probabilidad de que la media poblacional se encuentre
#dentro de unos límites alrededor de la media muestral.

#A mayor nivel de confianza menos precisión para estimar la media poblacional
pero menor es el error en la estimación de la media poblacional

peso<-c(2, 2.5, 3, 5, 1.5,1.8,4,5)
peso

#Estadisticos

s=sd(peso)
s
m= mean(peso)
m

#cuantil

z=qnorm(97.5/100, mean=0, sd=1)
z

#tamaño de muestra

n=length(peso)
n

#Limites de confianza

li<- m - (z * s/sqrt(n))

li
ls<- m + (z * s/sqrt(n))
ls


#Estimación de peso de gastos al 80% de nivel de confianza


#Estimación de peso de gatos

peso<-c(2, 2.5, 3, 5, 1.5,1.8,4,5)
peso
#Estadisticos

s=sd(peso)
s
m= mean(peso)
m

#cuantil

z=qnorm(90/100, mean=0, sd=1)
z

#tamaño de muestra

n=length(peso)
n

#Limites de confianza

li<- m - (z * s/sqrt(n))

li
ls<- m + (z * s/sqrt(n))
ls




