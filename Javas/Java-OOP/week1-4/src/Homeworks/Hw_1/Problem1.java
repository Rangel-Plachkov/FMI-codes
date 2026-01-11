package Hw_1;

public class Problem1 {
    static final int NUM_LEN = 5;
    public static void main(String[] args){
        int countProperty1 = 0;
        int countProperty2 = 0;
        for(int i = 10000; i< 100000; i++){
            if( areCorrectDigits(i) ){
                countProperty1++;
                if(i % 12 == 0){
                    countProperty2++;
                }
            }
        }
        double probability = (double) countProperty2 / countProperty1;
        System.out.printf("Probability is %.4f", probability);

    }
    private static boolean areCorrectDigits(int number){
        int[] digits = new int[NUM_LEN];
        for(int i = NUM_LEN - 1; i >= 0; i--){
            digits[i] = number % 10;
            number /= 10;
        }

        return digits[0] >= 3 && digits[1] >= 2 && digits[1] <= 8 &&
                digits[2] >= 4 && digits[3] >= 1 && digits[3] <= 6 && digits[4] >= 6;

    }
}
