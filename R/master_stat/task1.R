
data <- c(1, 35, 6, 2, 49, 8, 3, 8, 3, 7, 17, 11, 25, 1, 22, 5, 12, 2, 25, 9, 7, 1, 4, 5, 42, 2, 1, 54, 7, 13)

# print( mean(data) )  #Средно
# print ( var(data) ) # Дисперсия
# print ( sd(data) ) #Старндартно отколонение
# print(quantile(data, probs = 0.30)) #30-процентил

png("t1-boxplot.png")
boxplot(data,
        main="Call durations",
        ylab="Minutes")