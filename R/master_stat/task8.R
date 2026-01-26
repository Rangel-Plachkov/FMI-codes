test <- c(25, 39, 25, 26, 43, 42)
dice_test <- function(n){
  sim <- sample(1:6, n, replace = TRUE)
  my_test <- c(sum(sim==1), sum(sim==2), sum(sim==3),
               sum(sim==4), sum(sim==5), sum(sim==6))
  matr <- rbind(my_test, test)
  res <- chisq.test(matr)
  print(my_test)
  print(res)
}


dice_test(100)
# dice_test(200)
# dice_test(500)
# dice_test(1000)
# dice_test(2000)