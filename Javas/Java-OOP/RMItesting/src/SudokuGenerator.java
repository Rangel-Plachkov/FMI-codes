//https://geeksforgeeks.org/program-sudoku-generator/

import java.lang.ref.Cleaner;
import java.util.Random;

import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class SudokuGenerator extends UnicastRemoteObject implements genCl {
    private static final int SIZE = 9;
    private static final int SUBGRID_SIZE = 3;
    private int[][] grid;
    private int[][] solution;
    private int cellsToKeep = 32;

    public SudokuPuzzle getPuzzle(int K)throws RemoteException {
        cellsToKeep = K;
        generate();
        System.out.println("Generated Sudoku Puzzle:");
        return new SudokuPuzzle(grid, solution);
    }

    public SudokuGenerator() throws RemoteException {
        super();
        grid = new int[SIZE][SIZE];
        solution = new int[SIZE][SIZE];
    }
    public void cleanUp() throws RemoteException {
        grid = new int[SIZE][SIZE];
        solution = new int[SIZE][SIZE];
    }

    private void generate() {
        fillGrid();
        fillSolution();
        removeCells();
    }

    private void fillGrid() {
        Random random = new Random();

        for (int i = 0; i < SIZE; i += SUBGRID_SIZE) {
            fillSubgrid(i, i);
        }

        solve(0, 0);
    }

    private void fillSolution() {
        for (int i = 0; i < SIZE; i++) {
            System.arraycopy(grid[i], 0, solution[i], 0, SIZE);
        }
    }

    private void fillSubgrid(int startRow, int startCol) {
        Random random = new Random();
        int[] values = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        shuffleArray(values);

        int index = 0;
        for (int i = 0; i < SUBGRID_SIZE; i++) {
            for (int j = 0; j < SUBGRID_SIZE; j++) {
                grid[startRow + i][startCol + j] = values[index++];
            }
        }
    }

    private boolean solve(int row, int col) {
        if (row == SIZE - 1 && col == SIZE)
            return true;

        if (col == SIZE) {
            row++;
            col = 0;
        }

        if (grid[row][col] != 0)
            return solve(row, col + 1);

        for (int num = 1; num <= SIZE; num++) {
            if (isValid(row, col, num)) {
                grid[row][col] = num;

                if (solve(row, col + 1))
                    return true;

                grid[row][col] = 0;
            }
        }
        return false;
    }

    private boolean isValid(int row, int col, int num) {
        for (int x = 0; x < SIZE; x++) {
            if (grid[row][x] == num || grid[x][col] == num || grid[row - row % SUBGRID_SIZE + x / SUBGRID_SIZE][col - col % 3 + x % SUBGRID_SIZE] == num)
                return false;
        }
        return true;
    }

    private void removeCells() {
        Random random = new Random();
        //int cellsToKeep = random.nextInt(15) + 17; // Adjust the range to control difficulty

        while (cellsToKeep > 0) {
            int row = random.nextInt(SIZE);
            int col = random.nextInt(SIZE);

            if (grid[row][col] != 0) {
                grid[row][col] = 0;
                cellsToKeep--;
            }
        }
    }

    private void shuffleArray(int[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            int temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }
}
