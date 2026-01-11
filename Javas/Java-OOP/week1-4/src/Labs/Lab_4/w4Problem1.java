package Labs.Lab_4;

import java.util.Scanner;

public class w4Problem1 {
    private static final int CIPHER_N = 3;
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        char[] str = input.nextLine().toCharArray();
        int len = str.length;
        for(int i=0; i< len; i++){
            str[i] = cipherNforward( str[i] , CIPHER_N);
        }
        System.out.println(str);
        for(int i=0; i< len; i++){
            str[i] = decipherNbackward( str[i] , CIPHER_N);
        }
        System.out.println(str);
    }
    private static char cipherNforward (char in, int N){
        in += (char) N;
        if ( in > 122 ){
            in %= 122;
            in += 97;
        }
        return in;
    }
    private static char decipherNbackward (char in, int N){
        in -= (char) N;
        if ( in < 97 ){
            in += 26;
        }
        return in;
    }
}
