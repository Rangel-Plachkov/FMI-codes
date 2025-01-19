package bg.fmi.javaweb.racemanagement.repository;

import bg.fmi.javaweb.racemanagement.models.Racer;
import bg.fmi.javaweb.racemanagement.models.Team;
import bg.fmi.javaweb.racemanagement.models.Event;
import org.springframework.stereotype.Repository;
import jakarta.persistence.EntityNotFoundException;
import org.springframework.data.jpa.repository.JpaRepository;


import java.util.ArrayList;
import java.util.Optional;

@Repository
public interface TeamRepository extends JpaRepository<Team, String> {
    default void addRacer(String teamName, Racer racer){
        Optional<Team> teamOptional = findById(teamName);
        if(teamOptional.isPresent()){
            Team team = teamOptional.get();
            team.getRacers().add(racer);
            save(team);
        }else{
            throw new EntityNotFoundException("Team with name: " + teamName + " not found");
        }
    }
    default void removeRacer(String teamName, Racer racer){
        Optional<Team> teamOptional = findById(teamName);
        if(teamOptional.isPresent()){
            Team team = teamOptional.get();
            team.getRacers().remove(racer);
            save(team);
        }else{
            throw new EntityNotFoundException("Team with name: " + teamName + " not found");
        }
    }

}
