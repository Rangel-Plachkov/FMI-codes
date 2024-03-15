package Lab_1;
import java.util.Scanner;
public class w1task2{
    static public void main(String[] args){
        Scanner input = new Scanner(System.in);
        int originalNumber = input.nextInt();
        if(originalNumber < 10000 || originalNumber > 99999){
            System.out.println("Invalid input");
        }else if(isPalindrome(originalNumber)){
            System.out.println("The number is palindrome \n");
        }else{
            System.out.println("The number is NOT palindrome \n");
        }
    }
    static private boolean isPalindrome(int number){
        return number == reverse(number);
    }
    static private int reverse(int number){
        int ans = 0;
        int lastDigit;
        while(number > 0){
            lastDigit = number % 10;
            ans = (ans * 10) + lastDigit;
            number /= 10;
        }
        return ans;
    }
    static private int numLen(int number){
        if(number < 10){
            return 1;
        }else{
            return numLen(number/10) + 1;
        }
    }
}
