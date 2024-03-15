package Lab_1;

import java.util.Scanner;
public class w1task3 {
    static public void main(String[] args){
        Scanner input = new Scanner(System.in);

        int number = input.nextInt();
        if( !is4digits(number) ){
            System.out.println("Invalid input\n");
            return;
        }
        int encrypted = encrypt(number);
        int decrypted = decrypt(encrypted);
        System.out.println("Input: " + number);
        System.out.println("Encrypted: " + encrypted);
        System.out.println("Decrypted: " + decrypted);
    }
    private static boolean is4digits(int number){
        return (number > 999) && (number < 10000);
    }
    private static int encrypt(int number){
        int n1 = (number/1000) % 10;
        int n2 = (number/100) % 10;
        int n3 = (number/10) % 10;
        int n4 = number % 10;
        n1 += 7;
        n2 += 7;
        n3 += 7;
        n4 += 7;
        n1 %= 10;
        n2 %= 10;
        n3 %= 10;
        n4 %= 10;
        int ans = 0;
        ans += n4;
        ans += (n3*10);
        ans += (n2*100);
        ans += (n1*1000);
        return ans;
    }
    private static int decrypt(int number){
        int n1 = (number/1000) % 10;
        int n2 = (number/100) % 10;
        int n3 = (number/10) % 10;
        int n4 = number % 10;
        n1 += 3;
        n2 += 3;
        n3 += 3;
        n4 += 3;
        n1 %= 10;
        n2 %= 10;
        n3 %= 10;
        n4 %= 10;
        int ans = 0;
        ans += n4;
        ans += (n3*10);
        ans += (n2*100);
        ans += (n1*1000);
        return ans;
    }

}
