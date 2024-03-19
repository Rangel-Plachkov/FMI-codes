package repository;

import models.Racer;

import java.util.Map;
import java.util.Optional;
@SuppressWarnings("UnusedDeclaration")
public class RacerRepository {
    private Map<Integer, Racer> racerTable;

    public void addRacer(Racer racer) {
        
        racerTable.put(racer.getID(), racer);
    }
    public boolean deleteRacerById(Integer id) {
        return racerTable.remove(id) != null;
    }
    public Optional<Racer> getRacerById(Integer id) {
            return Optional.of(racerTable.get(id));
    }

}
