package Lab_1;
import java.util.Scanner;
public class w1task1 {
    public static void main(String[] args){
        double currTemp;

        System.out.println("Enter 1 for Celsius or 0 for Fahrenheit: ");
        Scanner input = new Scanner(System.in);
        int isCelsius;
        isCelsius = input.nextInt();
        //input = new Scanner(System.in);

        if(isCelsius == 1){
            System.out.println("Enter temperature in Celsius: ");
            currTemp = input.nextDouble();
            currTemp = 9.0 / 5.0 * currTemp + 32;
            System.out.print("Temperature in Fahrenheit: " + currTemp);
        }else{
            System.out.println("Enter temperature in Fahrenheit: ");
            currTemp = input.nextDouble();
            currTemp = 9.0 / 5.0 * currTemp + 32;
            System.out.print("Temperature in Fahrenheit: " + currTemp);
        }
    }
}
