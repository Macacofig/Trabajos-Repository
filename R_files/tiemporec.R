tiempo_recup <- rnorm(n-500,mena=50,sd=10)
tiempo_recup

#HISTOGRAMA

hist(tiempo_recup)
hist(tiempo_recup, prob = TRUE)
hist(tiempo_recup, prob = TRUE, main= "Histograma con curva normal", ylab = "F(x) Probabilidades", xlab = "Tiempo de recuperacion en dias")
x <- seq(min(TIempo_recup),max(tiempo_recup), length = 40)
x

f <- dnorm(x,mean= mean(tiempo_recup), sd = sd(tiempo_recup))
f

help(points)
points(x,f)
lines(x, f, col = "red", lwd = 2)

dnorm(50,45,10)

#PROBABILIDADES

dnorm(45, mean = 45, sd = 10) # Probabilidad de recuperacion en 45 dias
pnorm(30, mean = 45, sd = 10)
pnorm(60, mean = 45, sd = 10, lower.tail = FALSE)
1 - pnorm(60, mean = 45, sd = 10)
