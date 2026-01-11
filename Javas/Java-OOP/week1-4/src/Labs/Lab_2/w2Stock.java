package Lab_2;

public class w2Stock {
    private String _symbol;
    private String _name;
    private double _previousClosingPrice;
    private double _currPrice;
    public w2Stock(String newSymbol, String newName){
        _symbol = newSymbol;
        _name = newName;
    }
    public String getSymbol(){
        return _symbol;
    }
    public String getName(){
        return _name;
    }
    public double getCurrPrice(){
        return _currPrice;
    }
    public double getPreviousClosingPrice(){
        return _previousClosingPrice;
    }
    public void setCurrPrice(double newCurrPrice){
        _currPrice = newCurrPrice;
    }
    public void setPreviousClosingPrice(double newPrevPrice){
        _previousClosingPrice = newPrevPrice;
    }
    public double chagePercent(){
        return (_currPrice * 100) / _previousClosingPrice;
    }
}
