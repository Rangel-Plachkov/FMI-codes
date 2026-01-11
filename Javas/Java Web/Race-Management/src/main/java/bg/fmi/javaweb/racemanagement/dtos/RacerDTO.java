package bg.fmi.javaweb.racemanagement.dtos;

import jakarta.validation.constraints.Min;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;
import jakarta.validation.constraints.Pattern;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class RacerDTO {

    @NotBlank(message = "First name is mandatory")
    @Size(max = 50, message = "First name must be less than 50 characters")
    @Pattern(regexp = "^[a-zA-Z]*$", message = "First name must contain only letters")
    private String firstName;

    @NotBlank(message = "Last name is mandatory")
    @Size(max = 50, message = "Last name must be less than 50 characters")
    @Pattern(regexp = "^[a-zA-Z]*$", message = "Last name must contain only letters")
    private String lastName;

    @Min(value = 0, message = "Age must be non-negative")
    private Integer age;

    @NotBlank(message = "Team is mandatory")
    @Size(max = 50, message = "Team name must be less than 50 characters")
    @Pattern(regexp = "^[a-zA-Z0-9]*$", message = "Team name must contain only letters or digits")
    private String team;

    public RacerDTO(String firstName, String lastName, Integer age) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
    }

    @Override
    public String toString() {
        return "RacerDTO{" +
                "name='" + firstName     + '\'' +
                ", team='" + lastName + '\'' +
                ", age='" + age + '\'' +
                "team='" + team + '\'' +
                '}' + '\n';
    }
}
