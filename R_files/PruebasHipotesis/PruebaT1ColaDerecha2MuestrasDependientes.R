Prueba de t-student para dos muestras dependientes

Probabilidad y Estad�stica II
Docente: Dr. Ariel Ayma Romay
Universidad Católica Boliviana
===========================================

Conceptos:

Una prueba de t student se utiliza cuando tenemos pocos datos (menos que 30)
y desconocemos la desviacion típica de las poblaciones. 

Además, asumimos que los datos de la población tienen distribución normal.

En caso de comparar las medias de dos poblaciones a partir de una muestra aleatoria
de cada una, estas deben tener varianzas similares.

Son muestras dependientes cuando los sujetos o elementos de una muestra,
también son parte de la segunda muestra.


# Ejercicio # 1. Ganancia de peso de cerdos.


#1. Un agricultor Pancho, quiere probar una dieta nueva basada en desechos de agricultura
#orgánica para la crianza de cerdos comparada con la dieta normal. El agricultor tiene 10 cerdos para 
#experimentar. Pancho le da durante 45 dias la dieta normal y obtiene las siguientes ganancias de peso:

peso_dieta_normal<- c(10, 12, 10, 12, 15, 9, 8, 10, 11,10.5)

#Luego prueba la dieta orgánica durante otros 45 dias y obtiene las segundas
#ganancias de peso.

peso_dieta_organica<- c(12, 14, 15, 18, 17, 19, 14, 13, 12,15)

#2. Hipotesis cientifica

#Dietas naturales incrementan el peso de los cerdos.

#3. Predicción:
Entonces la dieta de restos de agricultura orgánica incrementa
el peso de los cerdos.

#4. Hipotesis estadísticas:

Ho: La ganancia de peso de los cerdos con dieta orgánica y dieta normal es la misma.
Ha: La ganancia de peso de los cerdos con dieta orgánica es mayor que la de dieta normal.

ó

Ho: mu (0) (dieta normal) = mu (1)(dieta orgánica)
Ha: mu (1) (dieta orgánica) > mu (0)(dieta normal)

ó

Ho: mu (0) (dieta normal) - mu (1)(dieta orgánica)= 0 
Ha: mu (1) (dieta orgánica - mu (0)(dieta normal) > 0

#5. Descripción de datos:

summary(peso_dieta_organica)
summary(peso_dieta_normal)
boxplot(peso_dieta_normal, peso_dieta_organica)

#6. Nivel de significancia

Usaremos un nivel de significancia de 0.05

#7. Tipo de prueba

Unilateral o prueba de una cola a la derecha. Proponemos que la diferencia entre la ganancia
de peso de cerdos con dieta orgánica y la dieta normal es mayor que cero.

#8. Valor de T-critico

t_critico<- qt(0.05, df=(10-1), lower.tail=FALSE)#Los grados de libertad son el tamaño de la muestra menos 1. En este caso 10 cerdos menos 1.
t_critico # Sale 1.83


#9. T-calculado y p valor

t.test(x=peso_dieta_organica, 
       y= peso_dieta_normal, 
       mu=0,
       alternative = "greater", 
       paired = TRUE, 
       var.equal = TRUE,
       conf.level = 0.95)


El valor de t calculado sale 4.8, y este es mayor que el t critico,
Adempas, la probabilidad de que la hipotesis nula sea cierta es de p = 0.00048.

#10 Toma de decisión

El valor de t calculado se fue al extremo derecho de la distribución de t-student a 
4.8 desviaciones respecto a la media del modelo nulo (mu=0)
El área de probabilidad acumulada desde el valor de 4.8 a la derecha es de
0.00048. Un área mucho menor al nivel de significancia de 0.05. Entonces 
la probabilidad de que la hipotesis nula sea cierta es muy iverosimil (casi improbable)
por lo que se rechaza dando paso para tomar como válida la hipótesis alternativa, la cual
propone que los cerdos incrementan peso con la dieta orgánica.

#11. Detalle de la función t.test

x = el vector de la primera muestra (dieta orgánica)
y = el vector de la segunda muestra (dieta normal)
mu = 0 Se coloca cero porque esperamos que la diferencia de las medias poblaciones
a las cuales pertenecen ambas muestras sea cero. Ese es el modelo nulo


alternative:

Aqui se coloca si queremos realizar una prueba de una cola (unilateral) o de dos colas (bilateral)
En este caso colocamos "greater" porque esperamos que las diferencias de peso
entre la dieta orgánica y la dieta normal sean mayores que cero (a la derecha del modelo nulo.

paired: 

En paired colocamos "TRUE" porque las muestras son dependientes.
Las mediciones vienen de los mismos cerdos. Y si fueran muestras independientes
se coloca "FALSE" si fueran independientes

var.equal: 

Aqui debemos precisar si ambas muestras tienen varianzas similares,
dicho de otra manera si tienen la misma dispersión de los datos respecto 
a sus medias muestrales.
Para definir si las muestras tienen varianza similar o diferente debemos
realizar una prueba auxiliar denominada prueba de F:

var.test(peso_dieta_organica, peso_dieta_normal)#Test de F para análisis de homogeneidad de varianza

Es una prueba para contrastar las siguientes hipotesis:

Ho= La varianza entre muestras son iguales
Ha= La varianza entre muestras son diferentes

En este caso el valor de p sale 0.51. Entonces eso significa que tienen
varianzas iguales. Asi que debemos colocar TRUE en el argumento de 


conf.level:
Colocamos 0.95. El inverso del nivel de significancia de 0.05.






