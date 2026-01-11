public class Wall {
    private Coordinates coordinatesStart;
    private Coordinates coordinatesEnd;
    public Wall(Coordinates coordinatesStart, Coordinates coordinatesEnd){
        this.coordinatesStart = coordinatesStart;
        this.coordinatesEnd = coordinatesEnd;
    }
    public Wall(double x1, double y1, double x2, double y2){
        this.coordinatesStart = new Coordinates(x1, y1);
        this.coordinatesEnd = new Coordinates(x2, y2);
    }
    public void setCoordinatesStart(Coordinates coordinatesStart){
        this.coordinatesStart = coordinatesStart;
    }
    public void setCoordinatesEnd(Coordinates coordinatesEnd){
        this.coordinatesEnd = coordinatesEnd;
    }
    public Coordinates getCoordinatesStart(){
        return this.coordinatesStart;
    }
    public Coordinates getCoordinatesEnd(){
        return this.coordinatesEnd;
    }
}
