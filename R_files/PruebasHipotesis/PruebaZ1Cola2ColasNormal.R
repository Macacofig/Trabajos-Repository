Pruebas de hipotesis de z para muestras simples
(distribuci�n normal) de una y dos colas

Dr. Ariel Isa�as Ayma Romay 
#Prueba de una cola a la derecha

Las pruebas de una cola son aquellas en las que el investigador esta interesado-
en conocer si su media muestral "es mayor que" o "menor que" de la media 
poblacional.

Ejemplo: Un investigador tiene la hipotesis que ha incrementado 
el nivel de colesterol en las personas adultas Cochabambinas respecto a lo normal.
El tiene la predicci�n que las personas de Cochabamba tienen m�s que lo normal
250 ml/decilitro (con 41 ml/dl como desviaci�n t�pica). 


poblacion<-rnorm(1000, mean=250, sd= 41)#modelo nulo
poblacion
hist(poblacion, col="lightgreen", main= "Modelo nulo")

z<-(poblacion-250)/41 #estandarizacion
z
hist(z, col="lightblue")


Prueba de hip�tesis de una cola
##############################################

�l investigador plantea las siguientes hip�tesis estad�sticas:

Ho: El colesterol en la poblaci�n de Cochabamba no ha incrementado
Ha: El colesterol en la poblaci�n de Cochabamba es mayor que lo 
recomendado (250 ml/dl).

Ho: mu(1) = mu (0)  ####  mu(1) = 250 ml/dl
Ha: mu (1) > mu (0) ##### mu (1) > 250 ml/dl #Prueba de una cola a la derecha

El tomo una muestra aleatoria simple de 60 personas adultas y encontro una media
de 290 ml/dl.

Ahora el se da cuenta que su media muestral es mayor a la media poblacional,
pero no sabe si esta diferencia es significativa al 95% de nivel de confianza


El estandariza la media muestral respecto a la media poblacional 
para conocer a cuantas desviaciones de la media poblacional
se encuentra su media. Se da cuenta que su media muestral esta a 0.975 desviaciones a la derecha
de la media poblacional.

z= (290-250)/(41/sqrt(60))
z # 0.9756

Luego el establece un valor de p de 0.05 para rechazar la hip�tesis nula

help (pnorm)
pnorm(q= 7.557041, mean= 0, sd= 1, lower.tail = FALSE)#estandarizando

significado de esa p -> probabilidad para aceptar h0

#q es el valor de la media muestral, o el valor de Z

El investigador encuentra que la probabilidad de que el colesterol de los cochabambinos 
supere los 290 mg/dl es de  2.06171e-14 (p < 0.05).

Entonces rechaza la hipotesis nula. Tambien esta declaraci�n podr�a estar cometiendo error
tipo I. La prob de cometer error tipo I es de  2.06171e-14

#Prueba de dos colas

Ahora el investigador tiene la hipotesis que el colesterol de los cochabambinos
no es 250 mg/dl pero el no esta seguro si es menor o mayor que ese valor.
Entonces propone una prueba de z de dos colas

Realiza el muestreo y encuentra una media de 290 pero como el planteo una prueba de dos colas
el debe sumar las �reas de probabilidad que se encuentran a la izquierda y 
a la derecha de la media muestral

z =(290-250)/(41/sqrt(60))
z

p<-pnorm(q= 7.557041, mean= 0, sd= 1, lower.tail = FALSE)+
pnorm(q= -7.557041, mean= 0, sd= 1, lower.tail = TRUE)

p


pnorm(-0.6242,0,1, lower.tail = TRUE)