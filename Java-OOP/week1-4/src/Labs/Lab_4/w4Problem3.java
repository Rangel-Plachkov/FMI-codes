package Labs.Lab_4;

import java.util.ArrayList;
import java.util.Scanner;

public class w4Problem3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> numbers = new ArrayList<>();

        System.out.println("Enter a sequence of numbers (end with 0):");

        int input;
        while (true) {
            input = scanner.nextInt();

            if (input == 0) {
                break;
            }

            if (!numbers.contains(input)) {
                numbers.add(input);
            }
        }

        scanner.close();

        System.out.println("Distinct numbers:");
        for (int number : numbers) {
            System.out.print(number + " ");
        }
    }
}
