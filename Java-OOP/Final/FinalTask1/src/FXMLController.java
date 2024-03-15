import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextArea;
import javafx.stage.FileChooser;

import java.io.File;
import java.net.URL;
import java.util.ResourceBundle;

import stock.java.StockManagement;

public class FXMLController implements Initializable {

    @FXML
    private TextArea textArea;

    private StockManagement stockManagement;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        stockManagement = new StockManagement();
    }

    @FXML
    private void handleLoad() {
        String result = stockManagement.showStocks();
        textArea.setText(result);
    }

    @FXML
    private void handleSaveAs() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Save As");
        File file = fileChooser.showSaveDialog(null);
        if (file != null) {
            stockManagement.writeSerializable(file);
        }
    }

    @FXML
    private void handleQuit() {
        System.exit(0);
    }

    @FXML
    private void handleSortData() {
        String result = "Stocks sorted by reorder quantity and ID\n\n";
        result += stockManagement.sortStockByReorderQtyAndID();
        //String result = stockManagement.sortStockByReorderQtyAndID().toString();
        textArea.setText(result);
    }

    @FXML
    private void handleComputeAverage() {
        double average = stockManagement.averagePrice();
        textArea.setText("Average price: " + average);
    }

    @FXML
    private void handleGroupData() {
        String result = "Group stock by reorder quantity and number of suppliers\n\n";
        result += stockManagement.groupByReorderQtyAndNumberSuppliers();
        textArea.setText(result);
    }
}
