package Homeworks.Hw_4;

public class AlgebraUtils {
    public static double[][] multiplyMatrices(double[][] matrix1, double[][] matrix2) {
        int rowsA = matrix1.length;
        int colsA = matrix1[0].length;
        int rowsB = matrix2.length;
        int colsB = matrix2[0].length;

        if (colsA != rowsB) {
            throw new IllegalArgumentException("Number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }

        double[][] result = new double[rowsA][colsB];

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        return result;
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
