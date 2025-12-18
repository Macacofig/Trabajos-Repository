#LECTURA DE LA BASE DE DATOS

base<-read.table("base_2024_recreo.txt", header=TRUE,   na.strings = "NA")
print(base)

# HISTOGRAMA

hist(base$edad,
     main = "Distribución de la Edad",
     xlab = "Edad",
     ylab = "Frecuencia",
     col = "skyblue",
     border = "white")


hist(base$presupuesto_diario,
     main = "Distribución del Presupuesto Diario",
     xlab = "Presupuesto Diario",
     ylab = "Frecuencia",
     col = "lightgreen",
     border = "white")