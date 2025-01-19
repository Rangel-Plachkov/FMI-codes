package bg.fmi.javaweb.racemanagement.mapper;

import bg.fmi.javaweb.racemanagement.dtos.RacerDTO;
import bg.fmi.javaweb.racemanagement.models.Racer;

public class RacerMapperT {
    public static Racer dtoToEntity(RacerDTO racerDTO) {
        Racer racer = new Racer();
        racer.setFirstName(racerDTO.getFirstName());
        racer.setLastName(racerDTO.getLastName());
        racer.setAge(racerDTO.getAge());
        //racer.setTeam(racerDTO.getTeam());
        return racer;
    }
    public static RacerDTO entityToDto(Racer racer) {
        RacerDTO racerDTO = new RacerDTO();
        racerDTO.setFirstName(racer.getFirstName());
        racerDTO.setLastName(racer.getLastName());
        racerDTO.setAge(racer.getAge());
        if(racer.getTeam() == null) {
            racerDTO.setTeam(null);
        } else {
            racerDTO.setTeam(racer.getTeam().getName());
        }
        return racerDTO;
    }
}
