simulation <- function() {
  vector <- c(rep("good_apples", 20), rep("bad_apples", 4))

  permuted_vector <- sample(vector)

  count_var1 <- sum(permuted_vector[1:6] == "bad_apples")
  count_var2 <- sum(permuted_vector[7:12] == "bad_apples")
  count_var3 <- sum(permuted_vector[13:18] == "bad_apples")
  count_var4 <- sum(permuted_vector[19:24] == "bad_apples")

  return(count_var1 == 1 && count_var2 == 1 && count_var3 == 1 && count_var4 == 1)
}

NumRep <- 100000
results <- replicate(NumRep, simulation())

correctVar <- sum(results)
print(correctVar/NumRep)
