package Labs.Lab_6;

public class w6pr1Rectangle extends w6pr1point{
    private w6pr1point lPoint;

    public w6pr1Rectangle(int[] coords, w6pr1point lPoint) {
        super(coords);
        setlPoint(lPoint);
    }

    public w6pr1Rectangle() {
        this(new int[2], new w6pr1point(new int[]{1, 1}));
    }

    public w6pr1Rectangle(w6pr1Rectangle r) {
        this(r.getCoords(), r.getPoint());
    }

    public w6pr1point getPoint() {
        return new w6pr1point(lPoint);
    }

    public void setlPoint(w6pr1point lPoint) {
        if (lPoint == null) {
            this.lPoint = new w6pr1point();
        }else{
            this.lPoint = new w6pr1point(lPoint);
        }
    }

    public int measure(){
        return 2 * (Math.abs(this.getCoords()[0] - lPoint.getCoords()[0]) + Math.abs(this.getCoords()[1] - lPoint.getCoords()[1]));
    }

    @Override
    public String toString() {
        return String.format("Rectangle uPoint: %s, lPoint: %s",
                super.toString(), lPoint.toString());
    }
}

