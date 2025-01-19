package bg.fmi.javaweb.racemanagement.repository;

import bg.fmi.javaweb.racemanagement.models.Racer;
import bg.fmi.javaweb.racemanagement.models.Team;
import org.springframework.stereotype.Repository;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.ArrayList;


@Repository
public interface RacerRepository extends JpaRepository<Racer, Integer>{

    default void assignTeam(Integer racerID, Team team){
        findById(racerID).ifPresent(racer -> {
            racer.setTeam(team);
            save(racer);
        });
    }
    default void assignTeam(ArrayList<Integer> racers, Team team){
        racers.forEach(racerID -> assignTeam(racerID, team));
    }
    default void removeTeam(Integer racerID){
        findById(racerID).ifPresent(racer -> {
            racer.setTeam(null);
            save(racer);
        });
    }

    default void createRacer(String firstName, String lastName, Integer age){
        save(new Racer(firstName, lastName, age));
    }
    default void createRacer(String firstName, String lastName){
        save(new Racer(firstName, lastName, null));
    }
}
