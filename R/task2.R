

N <- 30

sum_rexp <- function(N) {
    lambda <- 1/5
    rexp_values <- rexp(N, lambda)
    sum_values <- sum(rexp_values)
    result <- sum_values/N
    return(result)
}
F <- function(t){
    count <- sum(vector <= t)
    return(count/num_iterations)
}

num_iterations <- 10000
vector <- replicate(num_iterations, sum_rexp(N))

t_values <- seq(2, 8, by = 00.1)

F_values <- sapply(t_values, F)
plot(t_values, F_values, type = "l", main = paste("N = ", N) ,
    col = "red", 
    xlab = "t", ylab = "F(t) //// pnorm(t, 5, 5 / sqrt(N))")


p_values <- pnorm(t_values, 5, 5 / sqrt(N))

lines(t_values, p_values, col = "blue")
