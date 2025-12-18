# 1. Seed
set.seed(123)
# 2. Generar datos normales

# media = 50, sd = 10
aprobados <- rnorm(n = 1000, mean = 50, sd = 10)

# 3. Histograma

hist(aprobados, breaks = 30, proba = TRUE,
	main = "ALUMNOS APROBADOS",
	col = "gray")

# 4. Densidad (dnorm)

x <- seq(min(aprobados),max(aprobados), length = 100)
lines(x,dnorm(x,mean = 50,sd = 10), col = "blue", lwd = 2 )

# 5. Zonas de probabilidad (pnorm)

menor_30 <- pnorm(30,mean = 50,sd=10)
mayor_70 <- pnorm(70,mean=50,sd=10,lower.tail = FALSE)
entre_40_70 <- pnorm(70,mean = 50,sd=10) - pnorm(40,mean = 50,sd=10)

# P(X<=30)
menor_30
# P(X>70)
mayor_70
# P(40<=X<=70)
entre_40_70


# 6. Dato que % de datos estan <= que

q1 <- qnorm(0.2, mean = 50, sd = 10)
q2 <- qnorm(0.7, mean = 50, sd = 10, lower.tail= FALSE)

# Del dato hay 20% de los demas datos <=
q1
# Del dato hay 30% de los demas datos >
q2


# GRAFICAS

# G.1 Pnorm

x1<- seq(min(x),30, length= 100)
polygon(c(x1,rev(x1)),c(dnorm(x1,50,10), rep(0,length(x1))), col = "red")


x2<- seq(70,max(x), length= 100)
polygon(c(x2,rev(x2)),c(dnorm(x2,50,10), rep(0,length(x2))), col = "green")


# Sombrear área P(40 <= X <= 70)
x3 <- seq(40,70, length = 100)
polygon(c(x3,rev(x3)), c(dnorm(x3,50,10), rep(0,length(x3))), col = "yellow")

# G.2 Qnorm

# Agregar líneas verticales en percentiles
abline(v = c(q1, q2), col = c("purple", "cyan"),
       lty = 2, lwd = 2)
