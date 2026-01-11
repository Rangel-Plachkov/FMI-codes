package lab2aProblem2;

public class Rectangle {
    private double width;
    private double heigth;
    private static String color;

    public Rectangle() {
    }

    public Rectangle(double width, double heigth) {
        setWidth(width);
        setHeigth(heigth);
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        if( width <= 0){
            this.width = 1;
        }else{
            this.width = width;   
        }
    }

    public double getHeigth() {
        return heigth;
    }

    public void setHeigth(double heigth) {
        if(heigth <= 0){
            heigth = 1;
        }else {
            this.heigth = heigth;
        }
    }

    public static String getColor() {
        return color;
    }

    public static void setColor(String color) {
        if (color == null){
            Rectangle.color = "yellow";
        }else {
            Rectangle.color = color;
        }
    }
    public double getArea(){
        return width * heigth;
    }
    public  double getPerimeter(){
        return 2 * (width + heigth);
    }

}
