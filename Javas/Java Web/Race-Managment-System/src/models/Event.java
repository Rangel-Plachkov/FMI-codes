package models;

import java.time.LocalDate;
import java.util.ArrayList;
@SuppressWarnings("UnusedDeclaration")
public class Event {
    private static final String DEFAULT_NAME = "Unknown models.Event";
    private static final LocalDate DEFAULT_DATE = LocalDate.EPOCH;
    private static Integer nextID = 0;
    private Integer ID;
    private String name;
    private Track track;
    private final ArrayList<Team> teams;
    private LocalDate date;

    public static void main(String[] args) {
        Event event1 = new Event();
        event1.setID();
        Event event2 = new Event("models.Event 2", new Track("models.Track 2", 100), new ArrayList<>(), LocalDate.now());
        event2.setID();
        System.out.println(event1);
        System.out.println(event2);
    }


    public Event() {
        setName(DEFAULT_NAME);
        teams = new ArrayList<>();
        date = LocalDate.now();
    }
    public Event(String name, Track track , ArrayList<Team> teams, LocalDate date) {
        setName(name);
        setTrack(track);
        this.teams = teams;
        setDate(date);
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
    public void setTrack(Track track) {
        this.track = track;
    }
    public Track getTrack() {
        return track;
    }
    public void addTeam(Team team) {
        teams.add(team);
    }
    public void removeTeam(Team team) {
        teams.remove(team);
    }
    public ArrayList<Team> getTeams() {
        return teams;
    }
    public void setDate(LocalDate date) {
        this.date = date;
    }
    public LocalDate getDate() {
        return date;
    }
    @Override
    public String toString() {
        return String.format("models.Event %d: %s, %s, %d teams, %s", ID, name, track, teams.size(), date);
    }
}
