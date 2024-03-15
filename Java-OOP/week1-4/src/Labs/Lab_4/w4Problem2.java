package Labs.Lab_4;

import java.util.Scanner;
public class w4Problem2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a credit card number: ");
        long cardNumber = scanner.nextLong();

        if (isValidCreditCard(cardNumber)) {
            System.out.println("The credit card number is valid.");
        } else {
            System.out.println("The credit card number is invalid.");
        }
    }

    public static boolean isValidCreditCard(long cardNumber) {
        char[] cardDigits = Long.toString(cardNumber).toCharArray();
        int length = cardDigits.length;

        int sum = 0;
        for (int i = length - 2; i >= 0; i -= 2) {
            int digit = cardDigits[i] - '0';
            int doubled = digit * 2;
            sum += (doubled % 10) + (doubled / 10);
        }

        for (int i = length - 1; i >= 0; i -= 2) {
            sum += cardDigits[i] - '0';
        }

        return (sum % 10) == 0;
    }
}
