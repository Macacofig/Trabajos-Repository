
set.seed(123)

datos <- rnorm(100,5,1)

hist(datos)

shapiro.test(datos)

H0: datos tiene dis norm
Ha: datos no tiene dis norm

La Ho en shapiro genera una dis norm teorica -> Shapiro compara teorica vs real
si no hay diferencia, los datos son dis norm

p > 0.05 para aceptar normalidad

Cuando usar parametrico y no parametrico = depende de la normalidad de los datos


help(wilcox.test)

EJER

peso_oso <- c(45,40,50,44,75,90,90,86,90,92,54,100)
print(mean(peso_oso))
hist(peso_oso)

shapiro.test(peso_oso)

wilcox.test(x=peso_oso,y=NULL,
		alternative= "less",
		mu=80,conf.level=0.95)


v = V calculado
p-value = p> 0.05 para aceptar Ho

EJERCICIO DE CHAT
help(runif)

Un laboratorio cosmético quiere evaluar si dos shampoos diferentes 
afectan el grosor del cabello.
Se toman dos grupos independientes de mechones de cabello:
Shampoo A: Formula hidratación estándar
Shampoo B: Fórmula nutritiva fortalecedora
Se mide el grosor en micrometros

Hc = La formula utilizada para los shampoos afecta en el grosor del cabello
de las personas

H0 = El shampoo de formula nutritiva y fortalecedora no tiene ningun efecto
en el grosor del cabello de las personas

Ha = El shampoo de formula nutritiva y fortalecedor presenta un efecto respecto
al grosor del cabello de las personas

install.packages("modeest")
library(modeest)

set.seed(45)
datos2 <- runif(55,55,70)
datos3 <- runif(55,60,80)

print(mean(datos2))
print(median(datos2))
print(mlv(datos2))
print(mean(datos3))
print(median(datos3))
print(mlv(datos3))

hist(datos2)
hist(datos3)

#p<0.05 los datos no siguen una distribucion normal
shapiro.test(datos2)
shapiro.test(datos3)

#p<0.05 se rechaza la H0
wilcox.test(x=datos2,y=datos3,
		alternative= "two.sided",
		mu=0,conf.level=0.95)



