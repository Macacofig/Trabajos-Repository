Probabilidad y estadística II
Gestión I/2022
Docente: Dr. Ariel Isaías Ayma Romay
Muestreo aleatorio estratificado
########################################################################################
Ver: https://www.youtube.com/watch?v=9ldbajzFjUI

Probando el paquete "sampling.book"
install.packages("samplingbook")#instala el paquete
library(samplingbook)#carga el paquete

Ejercicio #4

Un investigador piensa que puede exitir diferencias de la cantidad de 
horas que duermen las mujeres y los hombres en una fabrica y decide realizar un muestreo aleatorio
estratificado al azar. Para ello conoce que existen 1800 personas, 
del cual 300 son mujeres y 1500 son hombres.
¿Cuántas mujeres y cuántos hombres tendría que entrevistar para estimar
la media poblacional de cantidad de horas que duermen los empleados,
si quiere aplicar el mismo nivel
de confianza, y error, y suponiendo que la desviación es la misma para ambos estratos.

Solución:
Utilizaremos la siguiente función del paquete samplingbook

library(samplingbook)
stratasize(e, Nh, Sh, level = 0.95, type = 'prop')
Argumentos
e = error en la estimación del parámetro de la población en porcentaje
Nh = vector del tamaño de la población de cada estrato 
Sh	= vector de desviacion estandar de cada estrato
level = nivel de confianza en escala 0 a 1. ejemplo: 95/100
type = "prop" para tomar proporcional al tamaño de cada estrato, y type="opt" para optimo

estratos<-c(300,1500)# el tamaño de cada estrato
estratos
desviaciones<-c(2.75,2.75)# las desviaciones de cada estrato
desviaciones

stratasize(e= 1.23, Nh=estratos, Sh=desviaciones, level = 0.95, type = "prop")

stratasamp(n=20, Nh=estratos, Sh=desviaciones, type = "prop")#colocar el resultado de stratasize en "n"


Ver el siguiente video para el muestreo optimo: https://www.youtube.com/watch?v=9ldbajzFjUI

Ahora seleccionaremos al azar de cada uno de estos estratos:

mujeres<-seq(1:300)
mujeres
sample(mujeres, size= 3, replace= FALSE)
hombres<-seq (1:1500)
hombres
sample(hombres, size = 17, replace= FALSE)#

Literatura
###################################################
Vivanco,M. 2005. Muestreo estadístico, diseño y aplicaciones. Editorial Universitaria. Universidad de Chile. 
Santiago.

Fuentes complementarias:
https://rpubs.com/osmartola/658826

Tamaño muestral para proporciones:

https://www.youtube.com/watch?v=iXJfDZAt2qs

Tamaaño muestral para promedios:
https://www.youtube.com/watch?v=GWgFlJsPdFI