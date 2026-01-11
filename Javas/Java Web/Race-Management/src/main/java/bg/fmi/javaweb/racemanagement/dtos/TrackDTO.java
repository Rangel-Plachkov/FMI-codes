package bg.fmi.javaweb.racemanagement.dtos;

import jakarta.validation.constraints.Min;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Pattern;
import jakarta.validation.constraints.Size;
import lombok.Data;

@Data
public class TrackDTO {
    @NotBlank
    @Size(max = 50, message = "Track name must be less than 50 characters")
    @Pattern(regexp = "^[a-zA-Z0-9-_:]*$", message = "Track name must contain only letters, digits and -_:")
    private String name;

    @Min(value = 0, message = "Track length must be non-negative")
    private Integer length;

    public TrackDTO(String name, Integer length) {
        this.name = name;
        this.length = length;
    }
    public TrackDTO(String name) {
        this.name = name;
        this.length = 0;
    }

    public TrackDTO() {
    }

    @Override
    public String toString() {
        return "TrackDTO{" +
                "name='" + name + '\'' +
                ", length=" + length +
                '}';
    }
}
