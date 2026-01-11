import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        double[][] matrix1 = createMatrix();

        double[][] matrix2 = createMatrix();

        double[][] result = AlgebraUtils.multiplyMatrices(matrix1, matrix2);

        System.out.println("Matrix 1:");
        printMatrix(matrix1);

        System.out.println("Matrix 2:");
        printMatrix(matrix2);

        System.out.println("Result of Matrix Multiplication:");
        printMatrix(result);
    }
    public static double[][] createMatrix() {
        double[][] matrix = new double[3][3];
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter 9 double values for the 3x3 matrix:");

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print("Enter value at position [" + (i + 1) + "][" + (j + 1) + "]: ");
                matrix[i][j] = scanner.nextDouble();
            }
        }

        return matrix;
    }
    public static void printMatrix(double[][] matrix) {
        for (double[] row : matrix) {
            for (double element : row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }
}