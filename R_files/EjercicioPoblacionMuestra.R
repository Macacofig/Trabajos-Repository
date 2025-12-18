,,
# Generamos la poblacion, con distribucion normal (Personas, analisis de pesos)

set.seed(123)

poblacion<- rnorm(n=1000000, mean= 60, sd = 10)

poblacion

mean(poblacion)

# Sacamos una muestra aleatoria

muestra<- sample(x=poblacion, size = 30) 
# saca una muestra de (donde guardamos = donde sacamos datos, tam muestra)
muestra

mean(muestra)

hist(poblacion)

mean(c(61.82,60.19,64,60.37,57.91,57.21,60.0,63.61,62.16))