package bg.fmi.javaweb.racemanagement.models;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;
import lombok.Data;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

import java.util.ArrayList;
import java.util.Calendar;

@Data
@Entity
@AllArgsConstructor
@NoArgsConstructor
public class Team {
    static final int MAX_NAME_LENGTH = 32;

    @Id
    @NotNull(message = "Team: name can't be null")
    @NotBlank(message = "Team: name need to have minimum 1 non-white space character")
    @Size(max = MAX_NAME_LENGTH, message = "Team: Team's name need to be maximum of " + MAX_NAME_LENGTH + "characters length")
    private String name;

    @NotNull(message = "Team: racers can't be null")
    @OneToMany(mappedBy = "team")
    ArrayList<Racer> racers;


    public Team(String name) {
        setName(name);
        racers = new ArrayList<>();
    }

    @Override
    public String toString() {
        return String.format("Team: %s, %d #racers", name, racers.size());
    }

}
