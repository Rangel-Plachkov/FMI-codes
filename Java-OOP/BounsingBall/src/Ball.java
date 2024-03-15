public class Ball {
    private Coordinates coordinates;
    private double radius;
    private Coordinates speed;

    public Ball(Coordinates coordinates, Coordinates speed, double radius){
        this.coordinates = coordinates;
        this.speed = speed;
        this.radius = radius;

    }
    public Ball(double x, double y, Coordinates speed){
        this.coordinates = new Coordinates(x, y);
        this.speed = speed;
    }
    public boolean isCollidingWithWall(Wall wall){
        double closestX = clamp(coordinates.getX(), wall.getCoordinatesStart().getX(), wall.getCoordinatesEnd().getX());
        double closestY = clamp(coordinates.getY(), wall.getCoordinatesStart().getY(), wall.getCoordinatesEnd().getY());
        double distance = Math.sqrt(Math.pow(coordinates.getX() - closestX, 2) + Math.pow(coordinates.getY() - closestY, 2));
        return distance <= radius;

        /// https://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection
    }
    private double clamp(double value, double min, double max) {
        return Math.max(min, Math.min(max, value));
    }
    public boolean isCollidingWithBall(Ball ball){
        return this.coordinates.distanceTo(ball.getCoordinates()) <= this.radius + ball.getRadius();
    }

    void move(){
        this.coordinates.setX(this.coordinates.getX() + this.speed.getX());
        this.coordinates.setY(this.coordinates.getY() + this.speed.getY());
        //TODO: check if ball is out of bounds
    }

    public Coordinates getCoordinates(){
        return this.coordinates;
    }
    public double getRadius(){
        return this.radius;
    }
    public Coordinates getSpeed(){
        return this.speed;
    }
    public void setCoordinates(Coordinates coordinates){
        this.coordinates = coordinates;
    }
    public void setRadius(double radius){
        this.radius = radius;
    }
    public void setSpeed(Coordinates speed){
        this.speed = speed;
    }

}
