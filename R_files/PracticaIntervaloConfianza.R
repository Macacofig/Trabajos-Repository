# Basado en la teorema de limite central estimar:

# Cantidad de horas que duermen los estudiantes (indicador horas que durmio anoche)
# realizando muestreo aleatorio

# Calcule los intervalos de confianza al 95% de nivel de confianza

# Estime el porcentaje de estudiantes que duermen menos de 4 horas y mas de 9 horas


#DATOS

#50 muestras
HorasUCB <- read.csv("BaseHoras.csv", header = TRUE)
HorasUCB

#Procedimiento
#media
media <- mean(HorasUCB$Horas)
#desviacion estandar
desv <- sd(HorasUCB$Horas)
#Tamanio muestra
tam <- length(HorasUCB$Horas)

#cuantil para 95% confianza
z=qnorm(97.5/100, mean=0, sd=1)

#Limites de confianza

limf<- media - (z * desv/sqrt(tam))
lsup<- media + (z * desv/sqrt(tam))

# Mostrar resultados
cat("n =", tam, "\n")
cat("media =", media, "\n")
cat("sd =", desv, "\n")
cat("IC 95% media: [", limf, ",", lsup, "]\n\n")


# Estimacion

# Porcentajes muestrales

p_menos4 <- sum(HorasUCB < 4) / tam # % que duerme menos de 4 horas
p_mas9   <- sum(HorasUCB > 9) / tam # % que duerme mas de 9 horas 

# Menos de 4 horas -> IC
se_menos4 <- sqrt(p_menos4 * (1 - p_menos4) / tam) # Error estandar
linf_menos4 <- p_menos4 - z * se_menos4
lsup_menos4 <- p_menos4 + z * se_menos4

# Más de 9 horas -> IC
se_mas9 <- sqrt(p_mas9 * (1 - p_mas9) / tam) # Error estandar
linf_mas9 <- p_mas9 - z * se_mas9
lsup_mas9 <- p_mas9 + z * se_mas9

linf_menos4 <- max(0, linf_menos4); lsup_menos4 <- min(1, lsup_menos4)
linf_mas9 <- max(0, linf_mas9); lsup_mas9 <- min(1, lsup_mas9)

cat("Porcentaje < 4 =", p_menos4, "\n")
cat("Porcentaje > 9 =", p_mas9, "\n")
cat("IC 95% media: [", linf_menos4, ",", lsup_menos4, "]\n\n")
cat("IC 95% media: [", linf_mas9, ",", lsup_mas9, "]\n\n")





