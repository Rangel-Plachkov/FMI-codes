package stock.java;

import java.util.Random;
import java.util.function.IntSupplier;

public class Wrap {
    interface ICanRandomize {
        default IntSupplier randGenerator(double... bounds) {
            Random rand = new Random();

            return () -> {
                if (bounds.length == 1) {
                    return rand.nextInt((int) bounds[0] + 1);
                } else if (bounds.length == 2) {
                    int a1 = (int) bounds[0];
                    int a2 = (int) bounds[1];
                    if (a1 > a2) {

                        int temp = a1;
                        a1 = a2;
                        a2 = temp;
                    }
                    return rand.nextInt((a2 - a1) + 1) + a1;
                } else {
                    return rand.nextInt(Integer.MAX_VALUE);
                }
            };
        }
    }

    public static void main(String[] args) {
        IntSupplier randomSupplier1 = new ICanRandomize() {}.randGenerator(10);
        IntSupplier randomSupplier2 = new ICanRandomize() {}.randGenerator(20, 30);
        IntSupplier randomSupplier3 = new ICanRandomize() {}.randGenerator();

        System.out.println("Random number between 0 and 10: " + randomSupplier1.getAsInt());
        System.out.println("Random number between 20 and 30: " + randomSupplier2.getAsInt());
        System.out.println("Random positive number: " + randomSupplier3.getAsInt());
    }
}
