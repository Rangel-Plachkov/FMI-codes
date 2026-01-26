#qnorm -> P(x  <= d ) = 0.7   <=>   P(x  < d ) = 0.3
d <- qnorm(0.70, mean = 60, sd = 10)
print(d)