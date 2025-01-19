package bg.fmi.javaweb.racemanagement.models;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.JoinTable;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.FetchType;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;
import java.util.ArrayList;

@Data
@Entity
@NoArgsConstructor
@AllArgsConstructor
public class Event {
    static final int MAX_NAME_LENGTH = 32;

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Integer ID;

    @NotNull(message = "Event: name can't be null")
    @NotBlank(message = "Event: name need to have minimum 1 non-white space character")
    @Size(max = MAX_NAME_LENGTH, message = "Event: Event's name need to be maximum of " + MAX_NAME_LENGTH + "characters length")
    private String name;

    @NotNull(message = "Event: track can't be null")
    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "track_id")
    private Track track;

    @NotNull(message = "Event: teams can't be null")
    @ManyToMany
    @JoinTable(
            name = "Event_Team",
            joinColumns = {@JoinColumn(name = "event_id")},
            inverseJoinColumns = {@JoinColumn(name = "team_id")}
    )
    private ArrayList<Team> teams;


    @NotNull(message = "Event: date can't be null")
    private LocalDate date;

    public Event(String name, Track track, ArrayList<Team> teams, LocalDate date) {
        this.name = name;
        this.track = track;
        this.teams = teams;
        this.date = date;
    }
    public Event(String name, Track track, LocalDate date) {
        this.name = name;
        this.track = track;
        this.date = date;
    }
    @Override
    public String toString() {
        return String.format("Event %d: %s, %s, %d #teams, %s", ID, name, track, teams.size(), date);
    }
}
