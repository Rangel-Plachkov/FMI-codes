package service;

import models.Racer;
import repository.RacerRepository;

import java.util.List;
import java.util.Objects;

@SuppressWarnings("UnusedDeclaration")
public class RacerService {
    RacerRepository racerRepository = new RacerRepository();

    public List<Racer> getAllRacers() {
        return racerRepository.getAllRacers();
    }

    public List<Racer> getAllRacersByFirstName(String firstName) {
        return racerRepository.getAllRacers().stream()
                .filter(racer -> Objects.equals(racer.getFirstName(), firstName) )
                .toList();
    }
    public void createRacer(String firstName, String lastName, Integer age) {
        racerRepository.createRacer(new Racer(firstName, lastName, age));
    }
    public boolean deleteRacerById(Integer id) {
        return racerRepository.deleteRacerById(id);
    }
}
