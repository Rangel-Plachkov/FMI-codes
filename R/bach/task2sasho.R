
n <- 30

num_simulations <- 10000

gen_nums <- function(n, lambda) {
    xNums <- rexp(n, lambda)
    return (sum(xNums)/n)
}

simulations <- replicate(num_simulations, gen_nums(n, 1/5))

f_function <- function(t) {
    sum <- 0
    
    for(i in 1:num_simulations) {
        if (simulations[i] <= t) {
            sum <- sum + 1
        }
    }
    
    return (sum/num_simulations)
}

# Генериране на стойности за t
t_values <- seq(0, 10, by = 0.01)

# Генериране на стойности за F(t)
F_values <- sapply(t_values, f_function)

# Изчертаване на графика
plot(t_values, F_values, type="l", xlab="t", ylab="F(t)", main="Емпирична кумулативна функция на разпределение")


# print(f_function(7))
