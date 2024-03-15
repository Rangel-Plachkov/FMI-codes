import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class SudokuFX extends Application {

    private final Sudoku sudoku = new Sudoku();

    @Override
    public void start(Stage primaryStage) {
        BorderPane root = new BorderPane();
        GridPane sudokuGrid = createSudokuGrid();
        Button solveButton = new Button("Solve");
        Button resetButton = new Button("Reset");

        solveButton.setOnAction(e -> solveSudoku());
        resetButton.setOnAction(e -> resetSudoku());

        root.setCenter(sudokuGrid);
        root.setBottom(solveButton);
        root.setAlignment(solveButton, Pos.CENTER);
        root.setRight(resetButton);
        root.setAlignment(resetButton, Pos.CENTER);

        Scene scene = new Scene(root, 400, 400);
        primaryStage.setTitle("Sudoku Game");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private GridPane createSudokuGrid() {
        GridPane gridPane = new GridPane();
        gridPane.setAlignment(Pos.CENTER);
        gridPane.setHgap(5);
        gridPane.setVgap(5);

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                TextField textField = createTextField(row, col);
                gridPane.add(textField, col, row);
            }
        }

        return gridPane;
    }

    private TextField createTextField(int row, int col) {
        TextField textField = new TextField();
        textField.setPrefWidth(40);
        textField.setPrefHeight(40);
        textField.setAlignment(Pos.CENTER);

        // Bind the text property bidirectionally with the Sudoku board
        //textField.textProperty().bindBidirectional(sudoku.getBoardProperty(row, col), new SudokuStringConverter());

        return textField;
    }

    private void solveSudoku() {
        //sudoku.solve();
    }

    private void resetSudoku() {
        //sudoku.reset();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
