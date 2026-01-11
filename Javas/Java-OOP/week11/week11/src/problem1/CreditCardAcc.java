package problem1;

public record CreditCardAcc(double balance) {
    @Override
    public String toString() {
        return "CreditCardAcc{" +
                "balance=" + balance +
                '}';
    }
}
