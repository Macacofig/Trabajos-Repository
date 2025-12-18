luthier <- read.csv("Datos.csv", header = TRUE, sep = ",")

# Convertir columnas a numérico
luthier$Distancia <- as.numeric(gsub(",", ".", luthier$Distancia))
luthier$Tiempo <- as.numeric(gsub(",", ".", luthier$Tiempo))
luthier$Frecuencia <- as.numeric(luthier$Frecuencia)

# Factores de emisión
factor_auto <- c(
  ocupacion25 = 0.20,
  ocupacion50 = 0.10,
  ocupacion75 = 0.07,
  ocupacion100 = 0.05
)

factor_otro <- c(
  trufi = 0.1158,
  micro = 0.0686
)

luthier$CO2 <- NA

for (i in 1:nrow(luthier)) {
  
  t <- tolower(luthier$Transporte[i])
  
  # Normalizar combustible
  comb <- tolower(luthier$Combustible[i])
  
  freq <- luthier$Frecuencia[i]
  dist <- luthier$Distancia[i]
  
  if (t %in% c("auto", "taxi")) 
  {
    rd <- sample(c(25, 50),1, prob = c(0.85, 0.15))
    ocup_str <- paste0("ocupacion", rd)
    
    co2_pasajero_km <- factor_auto[ocup_str]
    
    luthier$CO2[i] <- co2_pasajero_km * dist * freq
  }
    # --- Trufi ---
  else if (t == "trufi") 
  {
    rdt <- sample(c(0.9, 1, 1.1),1, prob = c(0.4, 0.4, 0.2))
    luthier$CO2[i] <- factor_otro["trufi"] * dist * freq * rdt
  }

  # --- Micro o Microbus ---
  else if (t %in% c("micro", "microbus")) 
  {
    rdm <- sample(c(0.9, 1, 1.1),1, prob = c(0.4, 0.4, 0.2))
    luthier$CO2[i] <- factor_otro["micro"] * dist * freq * rdm
  }

  # --- Motocicleta ---
  else if (t %in% c("moto", "motocicleta")) 
  {
    # Asignar tu factor de moto (lo puedes ajustar)
    luthier$CO2[i] <- 0.075 * dist * freq
  }

  # --- Transporte sin combustible ---
  else if (t %in% c("bicicleta", "otro", "ninguno", "pie")) 
  {
    print(i)
    print("entro nada")
    luthier$CO2[i] <- 0
  }
}

# Quitar NA antes de Shapiro 
luthier$CO2

CO2_validos <- luthier$CO2[!is.na(luthier$CO2)]
hist(luthier$CO2)
luthier$CO2

shapiro.test(CO2_validos)


CO2_plot <- luthier[!is.na(luthier$CO2), ]

par(mfrow = c(1,2))  # dos gráficos lado a lado

hist(CO2_plot$CO2[CO2_plot$Tipo == "Publico"],
     breaks = 20,
     col = rgb(0,0,1,0.5),
     main = "CO2 - Transporte Público",
     xlab = "CO2",
     xlim = c(0, max(CO2_plot$CO2)))

hist(CO2_plot$CO2[CO2_plot$Tipo == "Privado"],
     breaks = 20,
     col = rgb(1,0,0,0.5),
     main = "CO2 - Transporte Privado",
     xlab = "CO2",
     xlim = c(0, max(CO2_plot$CO2)))

tapply(luthier$CO2, luthier$Tipo, mean)
