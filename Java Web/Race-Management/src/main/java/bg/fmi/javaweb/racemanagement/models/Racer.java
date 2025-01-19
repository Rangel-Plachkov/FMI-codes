package bg.fmi.javaweb.racemanagement.models;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.FetchType;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Min;
import jakarta.validation.constraints.Size;
import lombok.Data;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Data
@Entity
@AllArgsConstructor
@NoArgsConstructor
public class Racer {
    static final int MAX_NAME_LENGTH = 32;

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Integer ID;

    @NotNull(message = "Racer: firstName can't be null")
    @NotBlank(message = "Racer: firstName need to have minimum 1 non-white space character")
    @Size(max = MAX_NAME_LENGTH, message = "Racer: Racer's firstname need to be maximum of " + MAX_NAME_LENGTH + "characters length")
    private String firstName;

    @NotNull(message = "Racer: lastName can't be null")
    @NotBlank(message = "Racer: lastName need to have minimum 1 non-white space character")
    @Size(max = MAX_NAME_LENGTH, message = "Racer: Racer's lastname need to be maximum of " + MAX_NAME_LENGTH + "characters length")
    private String lastName;

    @Min(value = 0, message = "Racer: age can't be negative")
    private Integer age;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "team_id")
    Team team;

    public Racer(String firstName, String lastName, Integer age) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
    }
    @Override
    public String toString() {
        return String.format("Racer %d: %s %s, age: %d\n", ID, firstName, lastName, age);
    }

}
