package bg.fmi.javaweb.racemanagement.models;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.validation.constraints.Min;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;
import lombok.Data;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Entity
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Track {
    static final int MAX_NAME_LENGTH = 32;

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Integer ID;

    @NotNull(message = "Track: name can't be null")
    @NotBlank(message = "Track: name need to have minimum 1 non-white space character")
    @Size(max = MAX_NAME_LENGTH, message = "Track: Track's name need to be maximum of " + MAX_NAME_LENGTH + "characters length")
    private String name;

    @Min(value = 0, message = "Track: length can't be negative")
    private Integer length; //in meters


    public Track(String name, Integer length) {
        this.name = name;
        this.length = length;
    }

    @Override
    public String toString() {
        return String.format("Track %d: %s, %d meters", ID, name, length);
    }

}
