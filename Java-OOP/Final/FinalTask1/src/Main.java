import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends javafx.application.Application {

    public void start(javafx.stage.Stage stage) throws java.lang.Exception {
        javafx.scene.Parent root
                = javafx.fxml.FXMLLoader.load(getClass().getResource("sampleScene.fxml"));

        javafx.scene.Scene scene = new javafx.scene.Scene(root);

        // Set the Window title
        stage.setTitle("Stock Management");
        stage.sizeToScene();
        stage.resizableProperty().setValue(java.lang.Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(java.lang.String[] args) {
        launch(args);
    }
}