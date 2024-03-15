package Labs.Lab_6;

public class w6pr1Line extends w6pr1point{
    private w6pr1point ePoint;

    public w6pr1Line(int[] coords, w6pr1point ePoint) {
        super(coords);
        setPoint(ePoint);
    }

    public w6pr1Line() {
        this(new int[2], new w6pr1point(new int[]{1, 1}));
    }

    public w6pr1Line(w6pr1Line l) {
        this(l.getCoords(), l.getPoint());
    }

    public w6pr1point getPoint() {
        return new w6pr1point(ePoint);
    }

    public void setPoint(w6pr1point ePoint) {
        if (ePoint == null) {
            this.ePoint = new w6pr1point();
        }else{
            this.ePoint = new w6pr1point(ePoint);
        }
    }

    public double measure(){
        return Math.sqrt((this.getCoords()[0] - ePoint.getCoords()[0]) * (this.getCoords()[0] - ePoint.getCoords()[0]) + (this.getCoords()[1] - ePoint.getCoords()[1])*(this.getCoords()[1] - ePoint.getCoords()[1]));
    }

    @Override
    public String toString() {
        return String.format("Line sPoint: %s, ePoint: %s",
                super.toString(), ePoint.toString());
    }
}
