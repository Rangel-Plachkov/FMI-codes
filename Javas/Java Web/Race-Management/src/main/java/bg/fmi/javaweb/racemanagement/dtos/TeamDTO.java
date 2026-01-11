package bg.fmi.javaweb.racemanagement.dtos;

import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Pattern;
import jakarta.validation.constraints.Size;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.ArrayList;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class TeamDTO {
    @NotBlank(message = "Team name is mandatory")
    @Size(max = 50, message = "Team name must be less than 50 characters")
    @Pattern(regexp = "^[a-zA-Z0-9]*$", message = "Team name must contain only letters or digits")
    private String name;

    private ArrayList<RacerDTO> racers;


    public TeamDTO(String name) {
        this.name = name;
        this.racers = new ArrayList<>();
    }


    @Override
    public String toString() {
        return String.format("Team: %s, %d racers", name, racers.size());
    }
}
