#Ejercicio

La profesora  Claudia quiere realizar un analisis sobre el metodo de Metacognicion 
aplicado a sus estudiantes

# m1
average_students_before <- c(60,70,65,80,75,70,75,65,60,73,55,60)
# m2
average_students_after <- c(70,75,65,80,85,75,85,65,72,81,68,76)

# Hipotesis cientifica
El metodo basado en la Metacognicion  influye significativamente en el 
rendimiento academico de los estudiantes

# Prediccion
Los estudiantes que utilicen el metodo Metacognitivo presentaran un promedio
mayor que el obtenido previamente con el metodo tradicional, estimandose
un incremento aproximado del 10%

## Hipotesis estadisticas

# Hipotesis NULA
El aplicar el metodo de Metacognificion  en los estudiantes de Claudia
no aumentara el promedio de los estudiantes frente al metodo Tradicional

mu0 = mu1
mu1 - mu0 = 0

# Hipotesis ALTERNATIVA
El aplicar el metodo de Metacognificion  en los estudiantes de Claudia
aumentara el promedio de los estudiantes frente al metodo Tradicional

## Resume de datos
summary(average_students_before)
summary(average_students_after)
boxplot(average_students_before,average_students_after)

# Comprueba de Varianzas
var.test(average_students_before, average_students_after)

# Nivel significania

alpha = 0.05

# Tipo de prueba
Unilateral o prueba de una cola a la derecha. Proponemos que la diferencia entre
el Metodo Tradicional y el Metodo de Metacognicion

# T critico
t_critico<- qt(0.05, df=(12-1), lower.tail=FALSE)
t_critico 

# T calculado y valor p
t.test(x=average_students_after, 
       y= average_students_before, 
       mu=0,
       alternative = "greater", 
       paired = TRUE, 
       var.equal = TRUE,
       conf.level = 0.95)

# Decision


Se rechaza H0 por el valor de t-calculado = 4.7419, ya que t-critico = 1.79

por lo tanto aceptamos Ha que menciona que el Metodo de Metacognicion aumenta
el promedio de los estudiantes frente al Metodo Tradicional
