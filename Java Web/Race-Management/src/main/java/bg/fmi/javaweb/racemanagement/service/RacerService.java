package bg.fmi.javaweb.racemanagement.service;

import bg.fmi.javaweb.racemanagement.mapper.RacerMapper;
import bg.fmi.javaweb.racemanagement.models.Racer;
import bg.fmi.javaweb.racemanagement.models.Team;
import bg.fmi.javaweb.racemanagement.repository.RacerRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.Optional;

@Service
public class RacerService {

    @Autowired
    private final RacerRepository racerRepository;



    @Autowired
    public RacerService(RacerRepository racerRepository) {
        this.racerRepository = racerRepository;
    }


    public List<Racer> getAllRacers() {
        return racerRepository.findAll();
    }

    public List<Racer> getAllRacersByFirstName(String firstName) {
        return racerRepository.findAll().stream()
                .filter(racer -> Objects.equals(racer.getFirstName(), firstName) )
                .toList();
    }
    public Racer getRacerById(Integer id) {
        Optional<Racer> racerOptional = racerRepository.findById(id);
        return racerOptional.orElse(null);
    }
    public void createRacer(String firstName, String lastName, Integer age) {
        racerRepository.save(new Racer(firstName, lastName, age));
    }
    public boolean deleteRacerById(Integer id) {
        Optional<Racer> racerOptional = racerRepository.findById(id);
        if (racerOptional.isPresent()) {
            racerRepository.deleteById(id);
            return true;
        } else {
            return false;
        }
    }
    public void deleteAllRacers() {
        racerRepository.deleteAll();
    }
    public boolean assignRacerToTeam(Integer racerId, Team team) {
        Optional<Racer> racerOptional = racerRepository.findById(racerId);
        if (racerOptional.isPresent()) {
            Racer racer = racerOptional.get();
            racer.setTeam(team);
            racerRepository.save(racer);
            return true;
        }else{
            return false;
        }
    }
    public boolean assignRacerToTeam(Integer racerId, String teamName) {
        Optional<Racer> racerOptional = racerRepository.findById(racerId);
        if (racerOptional.isPresent()) {
            Racer racer = racerOptional.get();
            racer.setTeam(new Team(teamName));
            racerRepository.save(racer);
            return true;
        }else{
            return false;
        }
    }

}
