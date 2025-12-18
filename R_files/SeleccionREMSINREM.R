########################################################

# 1. Crear un vector de 60 objetos (ejemplo: animales)
animales <- c(
  "Perro", "Gato", "Caballo", "Vaca", "Oveja", "Cerdo", "Conejo",
  "Tigre", "León", "Elefante", "Mono", "Loro", "Pato", "Gallo", 
  "Gallina", "Tortuga", "Serpiente", "Cocodrilo", "Jirafa", "Cebra",
  "Rinoceronte", "Hipopótamo", "Koala", "Panda", "Oso", "Zorro",
  "Lobo", "Canguro", "Delfín", "Ballena",
  "Perro", "Perro", "Gato", "Caballo", "Caballo", "Caballo", "Vaca",
  "Oveja", "Oveja", "Cerdo", "Conejo", "Tigre", "León", "León",
  "Elefante", "Mono", "Mono", "Loro", "Pato", "Gallo", "Gallina",
  "Tortuga", "Cocodrilo", "Jirafa", "Cebra", "Rinoceronte", "Koala",
  "Panda", "Oso", "Zorro"
)

# Mostrar la población
cat("Población (60 animales):\n")
print(animales)
cat("\nFrecuencia de cada animal:\n")
frecuencias <- table(animales)
print(frecuencias)
########################################################
# 2. Selección aleatoria sin reemplazo
muestra_sin <- sample(animales, size = 5, replace = FALSE)
cat("\nMuestra aleatoria SIN reemplazo (todos distintos):\n")
print(muestra_sin)

########################################################
# 3. Selección aleatoria con reemplazo
muestra_con <- sample(animales, size = 5, replace = TRUE)
cat("\nMuestra aleatoria CON reemplazo (puede haber repetidos):\n")
print(muestra_con)