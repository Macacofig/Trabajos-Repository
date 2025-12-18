Probabilidad y Estadística II
Universidad Católica Boliviana
Prueba de T- Student de una muestra simple
########################################################
Ejercicio# 1 

Luthier dedico un año para crear un prototipo de cuerda de guitarra que sean más 
duraderas y baratas que las cuerdas de Fender, las cuales normalmente duran
12 semanas. Luthier propone que sus cuerdas durán más que las Fender.


#numero de semanas que duran las cuerdas de guitarra Luthier

luthier<-c(11, 13, 9, 15, 17, 20, 15, 18, 19)
sd<-sd(luthier)

luthier
sd

summary(luthier)
hist(luthier)

# Prueba de normalidad de datos

shapiro.test(luthier)#p = 0.78, aceptamos la hipotesis nula

Ho: Tiene distrbución normal
Ha: No tiene distribución normal



#Prueba de t de una cola a la derecha

#hipotesis estadistica

Ho: No hay diferencias entre la duración de las cuerdas de FEnder y Luthier
Ha: Las cuerdas de Luthier durán más que las cuerdas de Fender. 


## Nivel de significancia

0.05

##tcrit

tcrit<-qt(0.95, df= 9-1)#df es grados de libertad, tamaño de la muestra menos 1
tcrit # 1.85

##t-calculado


tcal<-(mean(luthier)- 12)/(sd(luthier)/sqrt(9))
tcal # 2.61


#p-valor

help(pt)
pt(q= 2.61, df= 9-1, ncp=0, lower.tail= FALSE)


# Alternativa 2 con función t.test

help(t.test)
t.test(x=luthier, y= NULL, alternative="greater", mu=12, conf.level= 0.95)

# Sintaxis de la función t.test
help(t.test)
t.test(x, y = NULL,
       alternative = c("two.sided", "less", "greater"),
       mu = 0, paired = FALSE, var.equal = FALSE,
       conf.level = 0.95, ...)