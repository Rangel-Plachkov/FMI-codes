package problem1;

public record SavingAcc(double balance,double rate) {

    @Override
    public String toString() {
        return "SavingAcc{" +
                "balance=" + balance +
                ", rate=" + rate +
                '}';
    }
}
