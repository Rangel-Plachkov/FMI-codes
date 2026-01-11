package problem1;

import java.io.FileNotFoundException;
import java.net.URL;
import java.util.Formatter;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.TextArea;

public class AccountController {
    private Object[] arrAccounts;
    private int current;
    private final int  ARR_SIZE=10;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btbSaving;

    @FXML
    private Button btnCredit;

    @FXML
    private Button btnSaveToFile;

    @FXML
    private Button btnShow;

    @FXML
    private Label lblBalance;

    @FXML
    private Label lblRate;

    @FXML
    private TextField txtBalance;

    @FXML
    private TextField txtRate;

    @FXML
    void btnCreditOnClick(ActionEvent event) {
        if(current>=ARR_SIZE){
            return;
        }
        double balance=Double.parseDouble(txtBalance.getText());
        arrAccounts[current++]=new CreditCardAcc(balance);
    }

    @FXML
    void btnSaveToFileOnClick(ActionEvent event) {
        try(Formatter formatter=new Formatter("accounts.txt")) {
            for(int i=0;i<current;i++){
                formatter.format("%s%n",arrAccounts[i]);
            }
        }
        catch (FileNotFoundException e){
            throw new RuntimeException(e);
        }
        Platform.exit();
    }

    @FXML
    void btnSavingOnClick(ActionEvent event) {
        if(current>=ARR_SIZE){
            return;
        }
        double balance=Double.parseDouble(txtBalance.getText());
        double rate=Double.parseDouble(txtRate.getText());
        arrAccounts[current++]=new SavingAcc(balance,rate);
    }
    @FXML
    private TextArea txaCredit;

    @FXML
    private TextArea txaSaving;
    @FXML
    void btnShowOnClick(ActionEvent event) {
        txaCredit.setText("");
        txaSaving.setText("");
        for(int i=0;i<current;i++){
            Object currentAcc=arrAccounts[current];
            if(arrAccounts[current] instanceof SavingAcc){
                currentAcc=(SavingAcc) currentAcc;
                txaSaving.appendText(currentAcc.toString());
                txaSaving.appendText("\n");
            }
            else if(currentAcc instanceof CreditCardAcc){
                currentAcc=(CreditCardAcc) currentAcc;
                txaCredit.appendText(currentAcc.toString());
                txaCredit.appendText("\n");
            }
        }
    }

    @FXML
    void initialize() {
        assert btbSaving != null : "fx:id=\"btbSaving\" was not injected: check your FXML file 'accountsScene.fxml'.";
        assert btnCredit != null : "fx:id=\"btnCredit\" was not injected: check your FXML file 'accountsScene.fxml'.";
        assert btnSaveToFile != null : "fx:id=\"btnSaveToFile\" was not injected: check your FXML file 'accountsScene.fxml'.";
        assert btnShow != null : "fx:id=\"btnShow\" was not injected: check your FXML file 'accountsScene.fxml'.";
        assert lblBalance != null : "fx:id=\"lblBalance\" was not injected: check your FXML file 'accountsScene.fxml'.";
        assert lblRate != null : "fx:id=\"lblRate\" was not injected: check your FXML file 'accountsScene.fxml'.";
        assert txaCredit != null : "fx:id=\"txaCredit\" was not injected: check your FXML file 'accountsScene.fxml'.";
        assert txaSaving != null : "fx:id=\"txaSaving\" was not injected: check your FXML file 'accountsScene.fxml'.";
        assert txtBalance != null : "fx:id=\"txtBalance\" was not injected: check your FXML file 'accountsScene.fxml'.";
        assert txtRate != null : "fx:id=\"txtRate\" was not injected: check your FXML file 'accountsScene.fxml'.";

        arrAccounts =new Object[ARR_SIZE];
        current=0;
    }
}

