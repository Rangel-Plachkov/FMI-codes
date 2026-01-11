package models;

@SuppressWarnings("UnusedDeclaration")
public class Track {
    private static final String DEFAULT_NAME = "Unknown models.Track";
    private static final Integer DEFAULT_LENGTH = 0;
    private static Integer nextID = 0;
    public Integer ID;
    public String name;
    public Integer length; //in meters

    public static void main(String[] args) {
        Track track1 = new Track();
        track1.setID();
        Track track2 = new Track("models.Track 2", 100);
        track2.setID();
        System.out.println(track1);
        System.out.println(track2);
    }
    public Track() {
        setName(DEFAULT_NAME);
        setLength(DEFAULT_LENGTH);
    }
    public Track(String name, Integer length) {
        setName(name);
        setLength(length);
    }

    public void setID() {
        ID = nextID;
        nextID++;
    }
    public Integer getID() {
        return ID;
    }
    public void setName(String name) {
        this.name = (name != null && !name.isEmpty() ? name : DEFAULT_NAME);
    }
    public String getName() {
        return name;
    }
    public void setLength(Integer length) {
        this.length = (length > DEFAULT_LENGTH ? length : DEFAULT_LENGTH);
    }
    public Integer getLength() {
        return length;
    }
    @Override
    public String toString() {
        return String.format("models.Track %d: %s, %d meters", ID, name, length);
    }


}
