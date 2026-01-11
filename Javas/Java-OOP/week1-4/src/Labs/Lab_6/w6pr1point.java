package Labs.Lab_6;

public class w6pr1point {
    private int[] coords;

    public w6pr1point(int[] coords) {
        setCoords(coords);
    }

    public w6pr1point() {
        this(new int[2]);
    }
    public w6pr1point(w6pr1point p) {
        this(p.getCoords());
    }

    public int[] getCoords() {
        int[] copy = new int[coords.length];
        System.arraycopy(coords, 0, copy, 0, copy.length);
        return copy;
    }

    public void setCoords(int[] coords) {
        if (coords != null && coords.length == 2){
            this.coords = new int[coords.length];
            for (int i = 0; i < coords.length; i++) {
                this.coords[i] = coords[i];
            }
        }else{
            this.coords = new int[2];
        }
    }
    @Override
    public String toString() {
        return String.format("(%d; %d)", coords[0], coords[1]);
    }

}

