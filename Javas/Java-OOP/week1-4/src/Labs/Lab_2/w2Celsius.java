package Lab_2;

public class w2Celsius {
    private double _celsius;

    public w2Celsius(double newCelsius) {
        _celsius = newCelsius;
    }
    public w2Celsius(){
        _celsius = 0;
    }
    public double get_celsius() {
        return _celsius;
    }
    public void set_celsius(double newCelsius) {
        _celsius = newCelsius;
    }
    public double convertToFehrenheit(){
        return 9.0/ 5.0 * _celsius + 32;
    }
}
