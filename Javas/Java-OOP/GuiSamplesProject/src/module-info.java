module ThreadGuiProject {
    requires javafx.fxml;
    requires javafx.controls;
    requires javafx.web;
    opens gui to javafx.fxml;
    exports gui to javafx.graphics;
}