package Labs.Lab_6;

public enum w6pr2a {
    RED(20_000), GREEN(15_000), YELLOW(5_000);
    private final int duration;
    w6pr2a(int duration){
        this.duration = duration;
    }

    public int getDuration() {
        return duration;
    }
}
