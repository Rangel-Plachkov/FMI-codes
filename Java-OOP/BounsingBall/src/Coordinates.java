public class Coordinates {
    private double x;
    private double y;

    public Coordinates(double x, double y){
        this.x = x;
        this.y = y;
    }
    public double distanceTo(Coordinates coordinates){
        return Math.sqrt(Math.pow(this.x - coordinates.getX(), 2) + Math.pow(this.y - coordinates.getY(), 2));
    }
    public Coordinates multiply(double factor){
        this.x *= factor;
        this.y *= factor;
        return this;
    }
    public double getX(){
        return this.x;
    }
    public double getY(){
        return this.y;
    }
    public void setX(double x){
        this.x = x;
    }
    public void setY(double y){
        this.y = y;
    }
}
