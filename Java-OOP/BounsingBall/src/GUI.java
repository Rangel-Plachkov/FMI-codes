import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.scene.shape.Rectangle;

import java.util.ArrayList;



public class GUI extends Application {
    public static ArrayList<Ball> ballsArray = new ArrayList<>();
    public static  ArrayList<Wall> wallsArray = new ArrayList<>();
    public static final double WIDTH = 800;
    public static final double HEIGHT = 600;

    public static void main(String[] args) {
        launch(args);
    }
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Bouncing Balls");
        Pane root = new Pane();

        displayPointsOnGraph(root);
        displayWallsOnGraph(root);

        Scene scene = new Scene(root, WIDTH, HEIGHT);
        primaryStage.setScene(scene);
        primaryStage.show();

        for(int i = 0; i<10; i++){
            displayPointsOnGraph(root);
            displayWallsOnGraph(root);
            System.out.println("zele");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }



    }
    public static void displayPointsOnGraph(Pane pane) {
        for (Ball ball : GUI.ballsArray) {
            double x = ball.getCoordinates().getX();
            double y = ball.getCoordinates().getY();
            double radius = ball.getRadius();

            Circle circle = new Circle(x, y, radius);
            circle.setFill(Color.BLUE);

            pane.getChildren().add(circle);
        }
    }
    public static void displayWallsOnGraph(Pane pane) {
        for (Wall wall : GUI.wallsArray) {
            double x1 = wall.getCoordinatesStart().getX();
            double y1 = wall.getCoordinatesStart().getY();
            double x2 = wall.getCoordinatesEnd().getX();
            double y2 = wall.getCoordinatesEnd().getY();

            Rectangle rectangle = new Rectangle(x1, y1, x2, y2);
            rectangle.setFill(Color.GREY);

            pane.getChildren().add(rectangle);
        }
    }


}
