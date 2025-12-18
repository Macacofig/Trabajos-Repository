t student para dos muestras independientes
Universidad Católica Boliviana
Docente: Ing. Ariel Isaias Ayma Romay

Ejecicio: Caso aplicación de fertilizante
######################################################################

#Un investigador quiere conocer si la aplicación de un fertilizante incrementa
#el crecimiento de arboles de molle. Este investigador midio el crecimiento
#en altura de 30 plantas con el fertilizante (GrupoA) y 30 plantas sin fertilizante (Grupo B)
#durante un año.
#Explique si el fertilizante A fue util para mejorar el crecimiento.

#generando datos de dos muestras con varianza similar

set.seed(123)
Crecimiento_grupoA <- rnorm(n=30, mean=20, sd=3.4)
Crecimiento_grupoB <- rnorm(n=30, mean=15, sd=3.5)
Crecimiento_grupoA
Crecimiento_grupoB


# Problema

deficit de crecimiento en las plantas

#. Hipotesis cientifica

Los fertilizantes mejoran el crecimiento de las plantas

#Predicción

La aplicación de fertlizant mejora el crecimiento de plantines de árboles de molle

#Hipotesis estadística

Ho: mu (crecimiento de plantas con fertilizante) = mu (crecimiento de plantas sin fertilizante) 
Ha: mu (crecimiento de plantas con fertilizante) > mu (crecimiento de plantas sin fertilizante) 

#Tipo de prueba

Prueba de t de una cola a la derecha (unilateral)

# variable

el crecimiento es una variable cuantitativa contínua

#nivel de significancia

alfa=0.05

#t critico

qt(0.95, df= (30-1)+(30-1), lower.tail=TRUE)# n1 +n2 - 2
#el valor de t -critico es de 1.67

#Prueba de homegeneidad de varianzas

var.test(Crecimiento_grupoA, Crecimiento_grupoB)#Test de F para análisis de homogeneidad de varianza

Ho= La varianza entre muestras son iguales
Ha= La varianza entre muestras son diferentes

Se acepta la hipotesis nula, y se acepta que las varianzas son similares 
entre ambas muestras

#t-calculado

p<-t.test(Crecimiento_grupoA, Crecimiento_grupoB,
       alternative = "greater",
       mu = 0, paired = FALSE, var.equal = TRUE,
       conf.level = 0.95)

p

El valor de p es menor a 0.05


#Decisión

Rechazamos la hipotesis nula, la posibilidad de que la Ho sea cierta
es muy pequeña. Asi aceptamos la hipotesis alternativa de que el crecimiento
de plantines de molle mejora incrementando fertilizante.
