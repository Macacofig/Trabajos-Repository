Probabilidad y estadística II
Universidad Cat�lica Boliviana 
Curso de Invierno 2022
#######################################

#1. Introducción de R project para estudiantes

#R es una calculadora poderosa
2+1
3*5
4-2
3/3

#R asigna valores a objetos

c=5
b<-5
c+b

ayma=42
ayma+10

# R tiene funciones que abrevian calculos

v_1<- c(1,5,4,6,7,8,9,10,12, 14,13,12,20,14,15, 16, 17, 20, 50,10,20,21)#c es una función para concatenar valores
v_1

summary(v_1)#resume parámetros estadísticos
boxplot(v_1)#Realiza una caja de bigotes
hist(v_1)#Realiza un histograma
stem(v_1)# Realiza un grafico de tallos y hojas

help(stem)

suma<-sum(v_1)
suma
rango<-range(v_1)#rango
rango
media<-mean(v_1)#media aritmética
media
varianza<-var(v_1)#varianza de la muestra
varianza
desviacion<-sd(v_1)#desviación estandar de la muestra
desviacion

coef_var<-desviacion/media #Coeficiente de variación
coef_var

#Practíque

Realice la misma operación con las alturas de sus compañeros de curso

Alturas:
1.59, 1.82, 1.65, 1.58, 1.69, 1.83, 1.86, 1.84, 1.65, 1.82, 1.81, 1.60, 1.58, 1.81

