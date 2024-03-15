import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class ClientGUI extends Application {

    private static final int CELL_SIZE = 50;
    private static final int GRID_SIZE = 9;

    private int[][] sudokuGrid;

    public static void drawSudoku(int[][] sudokuGrid) {
        Application.launch(ClientGUI.class, serializeSudokuGrid(sudokuGrid));
    }

    @Override
    public void start(Stage primaryStage) {
        sudokuGrid = deserializeSudokuGrid(getParameters().getUnnamed().get(0));

        GridPane gridPane = createSudokuGridPane();
        drawSudokuGrid(gridPane);

        Scene scene = new Scene(gridPane, GRID_SIZE * CELL_SIZE, GRID_SIZE * CELL_SIZE);
        primaryStage.setTitle("Sudoku Drawer");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private static String serializeSudokuGrid(int[][] sudokuGrid) {
        StringBuilder sb = new StringBuilder();
        for (int[] row : sudokuGrid) {
            for (int value : row) {
                sb.append(value).append(" ");
            }
        }
        return sb.toString().trim();
    }

    private static int[][] deserializeSudokuGrid(String serializedGrid) {
        String[] values = serializedGrid.split("\\s+");
        int[][] grid = new int[GRID_SIZE][GRID_SIZE];
        int index = 0;
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int col = 0; col < GRID_SIZE; col++) {
                grid[row][col] = Integer.parseInt(values[index++]);
            }
        }
        return grid;
    }

    private GridPane createSudokuGridPane() {
        GridPane gridPane = new GridPane();
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int col = 0; col < GRID_SIZE; col++) {
                Canvas canvas = new Canvas(CELL_SIZE, CELL_SIZE);
                gridPane.add(canvas, col, row);
            }
        }
        return gridPane;
    }

    private void drawSudokuGrid(GridPane gridPane) {
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int col = 0; col < GRID_SIZE; col++) {
                Canvas canvas = (Canvas) gridPane.getChildren().get(row * GRID_SIZE + col);
                drawCell(canvas, sudokuGrid[row][col]);
            }
        }
    }

    private void drawCell(Canvas canvas, int value) {
        GraphicsContext gc = canvas.getGraphicsContext2D();

        // Draw cell background
        gc.setFill(Color.WHITE);
        gc.fillRect(0, 0, CELL_SIZE, CELL_SIZE);

        // Draw cell border
        gc.setStroke(Color.BLACK);
        gc.setLineWidth(1);
        gc.strokeRect(0, 0, CELL_SIZE, CELL_SIZE);

        // Draw cell value (if not empty)
        if (value != 0) {
            gc.setFill(Color.BLACK);
            gc.fillText(Integer.toString(value), (double) CELL_SIZE / 2 - 5, (double) CELL_SIZE / 2 + 5);
        }
    }

    public static void main(String[] args) {
        int[][] sudokuGrid = {
                {5, 3, 0, 0, 7, 0, 0, 0, 0},
                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                {0, 9, 8, 0, 0, 0, 0, 6, 0},
                {8, 0, 0, 0, 6, 0, 0, 0, 3},
                {4, 0, 0, 8, 0, 3, 0, 0, 1},
                {7, 0, 0, 0, 2, 0, 0, 0, 6},
                {0, 6, 0, 0, 0, 0, 2, 8, 0},
                {0, 0, 0, 4, 1, 9, 0, 0, 5},
                {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };

        drawSudoku(sudokuGrid);
    }
}
