
#t1

# sim.balls1 <- function() {
#   x <- sample( c(1:8), 2, replace=T )
#   x[1]==x[2]
# }

#res <- replicate( 100000, sim.balls1() )
# (sum(res)/length(res))
###############################################
#t2
# sim.socks <- function(){
#     x <- sample( c(1,1,2,2,3,3) , 2, replace=F)
#     x[1]==x[2]
# }
#res <- replicate( 10000 , sim.socks() )
#print(sum(res)/length(res))

###############################################
#t3

# sim.keys <- function() {
#   x <- sample( c(1:4), 4, replace=F )
#   x[4]==1
# }
# prob.keys <- function(Nrep) {
#   res <- replicate( Nrep, sim.keys() )
#   sum(res)/length(res) 
# }
#print( prob.keys(100000) )

#################################################
#t4

# sim.questions <- function(){
#     x <- sample( c(1:20) , 2, replace=F)
#     ( x[1] <= 17 && x[2] > 17 ) || ( x[2] <= 17 && x[1] > 17 )
# }
# res <- replicate( 100000 , sim.questions() )
# print(sum(res)/length(res))

##################################################
#t5

# sim.bday <- function() {
#     x <- sample ( c(1:365) , 25, replace=T)
#     any ( duplicated(x) )
# }

# res <- replicate( 10000 , sim.bday() )
# print(sum(res)/length(res))

##################################################
#t6

# sim.present <- function(){
#     x <- sample ( c(1:20) , 20, replace=F)
#     d <- x - c(1:20)
#     any( d == 0 )
# }

# res <- replicate( 10000 , sim.present() )
# print(sum(res)/length(res))


################################################
#t7

# sim.ants <- function(){
#     a <- sample( c(2,3) , 1)
#     b <- sample( c(1,3) , 1)
#     c <- sample( c(2,3) , 1)
#     ans <- c(a[1], b[1], c[1])
#     any(duplicated(ans)) == F
# }
# res <- replicate( 10000 , sim.ants() )
# print(sum(res)/length(res))

##############################################
#t8

# sim.eggs <- function(){
#     eggs <- c( rep("b", 2), rep("r", 6) )
#     draws <- sample( eggs , 8, replace=F)
#     p1 <- draws[seq(1,7,2)]
#     p2 <- draws[seq(2,8,2)]
#     s1 <- sum(p1 == "b")
#     s2 <- sum(p2 == "b")
#     c(p1,p2)
# }
# res <- replicate( 10000 , sim.eggs() )
# print(sum(res[1,] == 2) + sum(res[2,]==2) /10000)


##############################################
#t9

# sim.questions2_1 <- function(){
#     ans <- c( 1:4 )
#     x <- sample( ans , 1, replace=F)
#     x[1] == 1
# }
# sim.questions2_2 <- function(){
#     res <- replicate(10 , sim.questions2_1())
#     sum(res) >= 5
# }
# res <- replicate( 10000 , sim.questions2_2() )
# print(sum(res)/length(res))


# sim.test.ans <- function() {
#   x <- sample( c(0,0,0,1), 10, replace=T)
#   sum(x)
# }

# res <- replicate( 100000, sim.test.ans() )
# print(sum(res >= 5)/length(res))


###############################################
#t10

# sim.airplane <- function(){
#     x <- sample(c(0,1) , 143, replace=T, prob=c(0.08, 0.92))
#     sum(x) == 137
# }
# res <- replicate( 10000, sim.airplane() )
# print(sum(res)/length(res))

###############################################
#t11

# sim.box1 <- function(){
#     x <- sample(c("r","r", "z", "z"), 1)
#     x[1] == "z"
# }
# sim.box2 <- function(){
#     x <- sample(c("r","r","r", "r", "z"), 1)
#     x[1] == "z"
# }
# sim.zar <- function(){
#     zar <- sample(c(1:6) , 1)
#     if(zar == 6){
#         sim.box1()
#     }else{
#         sim.box2()
#     }
# }
# res <- replicate( 10000, sim.zar() )
# print(sum(res)/length(res))

###############################################
#t12

# sim.moneti <- function(){
#     coins <- c("t11" , "t11", "t22" ,"t12" , "t12")
#     pick <- sample( coins , 1)
#     if(pick[1] == "t11"){
#         res <- c(1,1)
#     }else if(pick[1] == "t12"){
#         temp <- sample(c(1,2) , 1)
#         if(temp == 1){
#             res <- c(1,2)
#         }else{
#             res <- c(2,1)
#         }
#     }else{
#         res <- c(2,2)
#     }
# }
# res <- replicate( 10000, sim.moneti() )
# print(sum(res == )/length(res))

###############################################
#t13

# sim.cards <- function(){
#     cards <- c("bb" , "bc" , "cc")
#     pick <- sample(cards , 1)
#     if(pick[1] == "bb" ){
#         c("b" , "b")
#     }else if(pick[1] == "cc"){
#         c("c" , "c")
#     }else{
#         flip <- sample(c("b" , "c") , 1)
#         if(flip == "b"){
#             c("b" , "c")
#         }else{
#             c("c" , "b")
#         }
#     }
# }
# res <- replicate( 10000, sim.cards() )
# print(sum(res[1,] == "b" & res[2,] == "b") / sum(res[1,] == "b"))

###############################################
#t14

# sim.balls1 <- function() {
#   x <- sample( c(1:99), 4, replace=F )
#   x[1] == max(x)
# }

# res <- replicate( 100000, sim.balls1() )
# print(sum(res)/length(res))

###############################################
#t16

# sim.aco <- function(){
#     teste <- c(rep("a" , 4) , rep("o" , 48))
#     teste <- sample(teste)
#     p1 <- teste[seq(1,52,4)]
#     p2 <- teste[seq(2,52,4)]
#     p3 <- teste[seq(3,52,4)]
#     p4 <- teste[seq(4,52,4)]
#     a1 <- sum(p1 == "a")
#     a2 <- sum(p2 == "a")
#     a3 <- sum(p3 == "a")
#     a4 <- sum(p4 == "a")
#     a1 == 1 && a2 == 1 && a3 == 1 && a4 == 1
# }
# res <- replicate( 10000, sim.aco() )
# print(sum(res)/length(res))

################################################
#t17
#a
# sim.elevator <- function(){
#     pfloors <- sample(c(2:16) , 7 , replace = T)
#     any( duplicated(pfloors))
# }
# res <- replicate( 10000, sim.elevator() )
# print(sum(res) / length(res))


# #b
# sim.elevator <- function(){
#     pfloors <- sample(c(2:16) , 7 , replace = T)
#     any( pfloors == 2 )
# }
# res <- replicate( 10000, sim.elevator() )
# print(sum(res) / length(res))

################################################
#t18 

# print(dbinom(2, 10 ,1/6))
# print(choose(10,2)*(1/6)^2*(5/6)^8)

# print(1 - pbinom(2, 10 ,1/6))

################################################
#t19

# print(pgeom(10 - 1 , 1/6))

################################################
#t20



################################################
#t22

# n <- 1500
# p <- 1/500

# print(pbinom(2, n, p))
# print(ppois(2 , 3))

# print(ppois(3 , n*p) - ppois(0 , n*p) )
# print(sum( dbinom(1:3, n, p) ))


################################################
#t23

# print( 1 - pbinom(4, 10, 1/4))

################################################
#t24

# print( pbinom(138, 143, 0.92) )

# print( dbinom(137, 143, 0.92) )

################################################
#t25

# print(pgeom(10-1 , 0.03))
# print(1- pbinom(1, 50 , 0.03))

################################################
#t26

# print(1 - phyper(1, 3, 97, 50))

################################################
#t27

#print(1 - phyper(1, 90, 3000-90, 50))

################################################
#t28

#print(pgeom(5, 1/10))

################################################
#t32

# x1 <- runif(5000, 2, 3)
# hist(x1)
# hist(x1, probability=T)
# curve( dunif(x, 2, 3), from=2, to=3, add=T, lwd=2 )

################################################
#t33

# x <- rexp(500, 1/7)
# hist(x, probability=T)
# curve( dexp(x, 1/7), from=0, to=max(x) ,add=T, lwd=2 )

################################################
#t34

# x <- rnorm(5000, 0, 1)
# hist(x, probability=T)
# curve( dnorm(x, 0, 1), from=min(x), to=max(x) ,add=T, lwd=2 )

################################################
#t35

# print( punif(250, 248 , 255) )
# print(qunif(0.05, 248, 255))

################################################
#t36

# print( pexp(11 , 1/10) -  pexp(7, 1/10))

# print(qexp(0.03, 1/10))

################################################
#t37

# print( 1 - pnorm(51, 41 , 5) )
# print( pnorm(50, 41 , 5) - pnorm(45, 41 , 5) )
# print( qnorm(0.99, 41, 5) )

################################################
#t38

#A

# sample <- rnorm(50000, 252, 3)
# print( sum(sample>=250) / 50000 )
# print( 1 - pnorm(250, 252, 3) )


################################################
#t45

# library(MASS)
# data(survey)
# ?survey

# table(survey$Exer)
# attach(survey)
# table(Exer)

# sort( table(Exer), decreasing=T )
# 100*table(Exer)/length(Exer)
# 100*prop.table( table(Exer) )

# barplot( table(Exer) )
# barplot( sort( table(Exer), decreasing=T ) )
# barplot( 100*table(Exer)/length(Exer) )
# pie( table(Exer) )
# pie( table(Exer), col=c("red", "yellow", "blue") )

################################################
#t48

# v1 <- rep(4, 30)
# v2 <- rep(c(3.5,4.5), 15)
# v3 <- rep(c(3,5), 15)
# v4 <- rep(c(2:6), 6)
# v5 <- rep(c(2,6), 15)

# my.summary <- function(x) {
#   res <- c( median(x, na.rm=T), mean(x, na.rm=T), sd(x, na.rm=T) )
#   names(res) <- c("Median", "Mean", "StDev")
#   res
# }

# my.summary(v1)
# my.summary(v2)
# my.summary(v3) 
# my.summary(v4)
# my.summary(v5)

# par(mfrow=c(2,3))
# stripchart(v1, pch="*", method="stack", xlim=c(2,6), ylim=c(0,10))
# stripchart(v2, pch="*", method="stack", xlim=c(2,6), ylim=c(0,10))
# stripchart(v3, pch="*", method="stack", xlim=c(2,6), ylim=c(0,10))
# stripchart(v4, pch="*", method="stack", xlim=c(2,6), ylim=c(0,10))
# stripchart(v5, pch="*", method="stack", xlim=c(2,6), ylim=c(0,10))
# par(mfrow=c(1,1))


#######################################################################
#t56

# e03sum <- replicate( 10000, sum( rexp(3, 1/5) ) )
# e07sum <- replicate( 10000, sum( rexp(7, 1/5) ) )
# e10sum <- replicate( 10000, sum( rexp(10, 1/5) ) )
# e30sum <- replicate( 10000, sum( rexp(30, 1/5) ) )
# e90sum <- replicate( 10000, sum( rexp(90, 1/5) ) )
# e200sum <- replicate( 10000, sum( rexp(200, 1/5) ) )

# hist(e03sum)
# hist(e07sum)
# hist(e10sum)
# hist(e30sum)
# hist(e90sum)
# hist(e200sum)


#######################################################################
#t57

# e03mean <- replicate( 10000, mean( rexp(3, 1/5) ) )
# e07mean <- replicate( 10000, mean( rexp(7, 1/5) ) )
# e10mean <- replicate( 10000, mean( rexp(10, 1/5) ) )
# e30mean <- replicate( 10000, mean( rexp(30, 1/5) ) )
# e90mean <- replicate( 10000, mean( rexp(90, 1/5) ) )
# e200mean <- replicate( 10000, mean( rexp(200, 1/5) ) )

# hist(e03mean)
# hist(e07mean)
# hist(e10mean)
# hist(e30mean)
# hist(e90mean)
# hist(e200mean)

#######################################################################
#t59

# mean.vals <- replicate(100000, mean(rexp(100, 1/900)))
# sum(mean.vals > 980)/length(mean.vals)
# hist(mean.vals)

#######################################################################
#t60

# mean.vals <- replicate(100000, mean(runif(50, 0, 60)))
# sum(mean.vals > 25 & mean.vals < 35)/length(mean.vals)
# hist(mean.vals)

#######################################################################
#t61

# stafidi <- replicate(10000,mean( 
#                             sample(c(4:7) , 49 , 
#                             prob=c(0.2,0.4,0.3,0.1),
#                             replace=T))
#                             )
# print(sum(stafidi>=5.5)/length(stafidi) )


# x <- c(4:7)
# p <- c(0.2,0.4,0.3,0.1)
# mu <- sum(x*p)
# sigma <- sqrt( sum((x^2)*p) - mu^2 )

# # с използване на ЦГТ
# a <- (5.5-mu)/(sigma/sqrt(49))
# 1 - pnorm(a)

#######################################################################
#t62

# res <- replicate(10000 , sum( rnorm(160, 24, 7) ) )
# print(sum(res>=4000) / length(res))

# a <- (4000 - 160*24)/(7*sqrt(160))
# 1 - pnorm(a)


#######################################################################
#t64

# res <- replicate(10000 , sum(sample(c(0,1) , 200 , replace=T)))
# print(1 - sum(res==100)  / length(res))

# print(1 - dbinom(100, 200, 1/2))


#######################################################################
#t65

# test <- rnorm(45, 6.7 , 0.12)
# reps <- replicate(10000 , mean(rnorm(45, 6.7 , 0.12)) , )
# conc <- sum(abs(reps - 6.7) <= 0.036)
# print(1 - (conc / length(reps)))

# a <- ( 0.036 / (0.12 /  sqrt(45)))
# print(pnorm(-a) + 1 - pnorm(a))


# mu <- 6.7
# sigma <- 0.12
# n <- 45
# mean.diam <- replicate(10^5, mean(rnorm(n, mu, sigma)))
# res2 <- sum(mean.diam <= 6.7-0.036 | mean.diam >= 6.7+0.036)/length(mean.diam)
# print(res2)

#######################################################################
#t66

# x <- 32
# n <- 58 
# p <- 0.51

# z.obs <- (x/n - p)/sqrt(p*(1-p)/n)
# z.obs
# p.value <- 1-pnorm(z.obs)
# p.value

# print(prop.test( x=32, n=58, p=0.51, alternative="greater", correct=F ))




#############################################################################
# Sample data
# data1 <- c(8, 9, 10, 11, 12)
# data2 <- c(15, 16, 17, 18, 19)

# # Perform two-sample t-test
# t.test(data1, data2)

#############################################################################
# t74



# x <- c(8, 15)
# n <- c(200, 200)

# p.hat <- (x[1] + x[2]) / (n[1] + n[2])
# z.obs <- (x[1]/n[1] - x[2]/n[2]) / sqrt(p.hat*(1-p.hat)*(1/n[1] + 1/n[2]))
# z.obs
# p.value <- 2*(1-pnorm(abs(z.obs)))
# p.value
# print(p.value)

# # може да ползваме и функцията prop.test
# prop.test( x=x, n=n, correct=F )
# print(prop.test( x, n, correct=F ))


#############################################################################
# t76


# sim.t2 <- function(n, mu1, mu2, sigma1, sigma2) {
#   x <- rnorm(n, mean=mu1, sd=sigma1)
#   y <- rnorm(n, mean=mu2, sd=sigma2)
#   t.test(x,y)$p.value
# }

# # rs <- replicate( 10000, sim.t2(n=500, mu1=5, mu2=5, sigma1=1, sigma2=0.8) )
# # print(sum(rs<=0.05)/length(rs))

# rs <- replicate( 10000, sim.t2(n=1000, mu1=5, mu2=5.2, sigma1=1, sigma2=1) )
# print(sum(rs<=0.05)/length(rs))

#############################################################################
# t78

# x <- c(26, 43)
# n <- c(500 ,540)

# print( prop.test(x, n, alternative="less",correct=F)$p.value )

#############################################################################
# t79

# t1 <- c(1.2, 1.3, 1.5, 1.4, 1.7,1.8, 1.4,1.3)
# t2 <- c(1.4, 1.7, 1.5, 1.3, 2.0,2.1, 1.7,1.6)

# print(t.test( t1, t2, paired=T )$p.value)

#############################################################################
# t80

# x.bar <- 7.88
# s.x <- 1.73
# y.bar <- 8.48
# s.y <- 2.12
# n <- 50
# m <- 50
# t.obs <- (x.bar - y.bar) / sqrt(s.x^2/n + s.y^2/m)
# p.value1 <- 2*(1-pnorm(abs(t.obs)))
# print(p.value1 )

#############################################################################
# t81

# z1.ci <- function(x.bar, sigma, n, alpha) {
#   b1 <- x.bar - qnorm(1-alpha/2)*(sigma/sqrt(n))
#   b2 <- x.bar + qnorm(1-alpha/2)*(sigma/sqrt(n))
#   c(b1, b2)
# }

# print(z1.ci( x.bar=61.9, sigma=4.1, n=66, alpha=0.05 ))
# print(z1.ci( x.bar=61.9, sigma=4.1, n=88, alpha=0.05 ))

#############################################################################
# t82

# x <- c(3.1 ,3.0 ,3.7 ,2.6 ,4.2 ,3.8 ,3.6 ,2.7 ,3.8 ,4.4)
# mu <- mean(x)
# sig <- sd(x)

# # res <- qnorm(0.975 , mu, sig)
# # print(res)
# #t1.ci( x.bar=mean(x), s=sd(x), n=length(x), alpha=0.05 )

# print(t.test( x, conf.level=0.95 ))

#############################################################################
# pr1


# sim.dice <- function(){
#     dice <- c(1:6)
#     t1 <- sample(dice , 2 ,  replace=T)
#     t2 <- sample(dice , 2 ,  replace=T)
#     sum(t1) > sum(t2)
# }
# stat <- replicate(100000, sim.dice())
# res <- sum(stat)/length(stat)
# print(res)

#############################################################################
# pr2

# x <- c(35, 15)
# y <- c(1000 ,500)

# print(prop.test(x=15 , n=500 , p=0.035 , alternative="less", correct=T))

#############################################################################
# kati6

# x <- c(25, 22)
# n <- c(200, 180)

# res <- prop.test(x, n, alternative  ="greater")
# print(res$p.value)  

#############################################################################
#t82

# t1.ci <- function(x.bar, s, n, alpha) {
#   b1 <- x.bar - qt(1-alpha/2, df=n-1)*(s/sqrt(n))
#   b2 <- x.bar + qt(1-alpha/2, df=n-1)*(s/sqrt(n))
#   c(b1, b2)
# }



# print(t1.ci( x.bar=mean(x), s=sd(x), n=length(x), alpha=0.05 ))

# x <- c(3.1, 3.0, 3.7, 2.6, 4.2, 3.8, 3.6, 2.7, 3.8, 4.4)
# print(t.test( x, conf.level=0.95 ))

#############################################################################
#t83

# print( prop.test( 32  , 58 , conf.level = 0.95) )

#############################################################################
#t84

# sim.84 <- function(n){
#     x <- runif(n , 5 ,9)
#     res <- t.test(x , conf.level=0.95)$conf.int[1:2]
#     (res[1] <= 7 & res[2] >= 7)
# }
# res <- replicate(1000, sim.84(20))
# print(sum(res) / length(res))


#############################################################################
#t85

# x <- c(28, 36, 36, 30, 27, 23)
# probs <- rep(1/6 ,6)
# print(chisq.test(x, p=probs))


#############################################################################
#t86

# x <- c(221 ,153 ,183 ,111 ,113 ,152 ,103 ,197 ,38 ,104 ,629)
# prob <- c( 0.1202, 0.0910, 0.0812, 0.0768, 0.0731, 0.0695, 0.0628, 0.0602, 0.0592, 0.0432, 0.2628)

# res <- chisq.test(x=x , p=prob)
# print(res)

#############################################################################
#t87

# x <- c(141, 291, 132)
# p <- c(1/4, 1/2 , 1/4)
# print(chisq.test(x=x, p=p))


#############################################################################


print(t.test(c(28, 36, 36, 30, 27, 23) ,c(28, 36, 36, 30, 27, 23)))