pdf("t4-hist.pdf")
for(n in c(2,10,50)){
  x <- replicate(100, mean(rnorm(n, mean=36, sd=6)))
  hist(x, main=paste("Normal, n =", n), xlab="x")
}
# Увеличаването на размера на извадката предвид ,че популацията е нормално рапзределена означава:
# Новата случайна величина е нормално разпределена (Средното е събирана на нормални разпределения разделено на константа)
# Колкото по-голямо n, толкова по-малко стандартно отколонение

pdf("t4-sd-n.pdf")
n <- 1:50
sd_x <- sapply(n, function(k)
  sd(replicate(100, mean(rnorm(k, mean=36, sd=6))))
)

plot(n, sd_x,
     xlab="n", ylab="SD(x)",
     main="SD(x) vs n")

#######################
pdf("t4-poaason.pdf")

for(n in c(2, 10, 50)){
  x <- replicate(100, mean(rpois(n, 36)))
  hist(x, main=paste("n =", n), xlab="x")
}