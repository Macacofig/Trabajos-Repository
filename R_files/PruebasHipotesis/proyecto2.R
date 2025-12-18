# 1. CARGA DE DATOS

luthier <- read.csv("Datos.csv", header = TRUE, sep = ",")

# 2. LIMPIEZA Y CONVERSIÓN

luthier$Distancia  <- as.numeric(gsub(",", ".", luthier$Distancia))
luthier$Tiempo     <- as.numeric(gsub(",", ".", luthier$Tiempo))
luthier$Frecuencia <- as.numeric(luthier$Frecuencia)

luthier$Transporte  <- tolower(luthier$Transporte)
luthier$Combustible <- tolower(luthier$Combustible)

luthier$Tipo <- factor(luthier$Tipo,
                       levels = c("Privado", "Publico"))

# 3. FACTORES DE EMISIÓN

factor_auto <- c(
  ocupacion25  = 0.15,
  ocupacion50  = 0.10
)

factor_otro <- c(
  trufi = 0.17,
  micro = 0.06
)

# 4. CÁLCULO DE CO2 DIARIO

set.seed(123)

luthier$CO2 <- NA

for (i in 1:nrow(luthier)) {

  t    <- luthier$Transporte[i]
  dist <- luthier$Distancia[i]
  freq <- luthier$Frecuencia[i]

  # Taxi 
  if (t %in% c("taxi")) {
    luthier$CO2[i] <- 0.12 * dist * freq
  }
  # Auto
  if (t %in% c("auto")) {

    rd <- sample(c(25, 50), 1, prob = c(0.90, 0.10))
    ocup_str <- paste0("ocupacion", rd)

    co2_pasajero_km <- factor_auto[ocup_str]
    luthier$CO2[i] <- co2_pasajero_km * dist * freq
  }

  # Trufi
  else if (t == "trufi") {

    rdt <- sample(c(0.9, 1, 1.1), 1, prob = c(0.4, 0.4, 0.2))
    luthier$CO2[i] <- factor_otro["trufi"] * dist * freq * rdt
  }

  # Micro / Microbus
  else if (t %in% c("micro", "microbus")) {

    rdm <- sample(c(0.9, 1, 1.1), 1, prob = c(0.4, 0.4, 0.2))
    luthier$CO2[i] <- factor_otro["micro"] * dist * freq * rdm
  }

  # Motocicleta
  else if (t %in% c("moto", "motocicleta")) {

    luthier$CO2[i] <- 0.045 * dist * freq
  }

  # Transporte sin emisiones
  else if (t %in% c("bicicleta", "pie", "otro", "ninguno")) {

    luthier$CO2[i] <- 0
  }
}

luthier$CO2


# 5. DESCRIPTIVOS POR TIPO

tapply(luthier$CO2, luthier$Tipo, summary)
tapply(luthier$CO2, luthier$Tipo, mean)
tapply(luthier$CO2, luthier$Tipo, sd)

# 6. NORMALIDAD

CO2_priv <- luthier$CO2[luthier$Tipo == "Privado" & luthier$CO2 > 0]
CO2_pub  <- luthier$CO2[luthier$Tipo == "Publico" & luthier$CO2 > 0]

shapiro.test(CO2_priv)
shapiro.test(CO2_pub)

# 7. VISUALIZACIÓN

par(mfrow = c(1,2))

hist(CO2_pub,
     breaks = 20,
     col = rgb(0,0,1,0.5),
     main = "CO2 Diario - Transporte Público",
     xlab = "CO2")

hist(CO2_priv,
     breaks = 20,
     col = rgb(1,0,0,0.5),
     main = "CO2 Diario - Transporte Privado",
     xlab = "CO2")

par(mfrow = c(1,1))

# 8. PRUEBA DE HIPÓTESIS

wilcox.test(CO2_pub,
            CO2_priv,
            alternative = "greater",
            exact = FALSE)


# EXTRAS
barplot(table(luthier$Transporte))
barplot(table(luthier$Tipo))
