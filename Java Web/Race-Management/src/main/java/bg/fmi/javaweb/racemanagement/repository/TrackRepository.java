package bg.fmi.javaweb.racemanagement.repository;

import bg.fmi.javaweb.racemanagement.models.Track;
import org.springframework.stereotype.Repository;
import org.springframework.data.jpa.repository.JpaRepository;

@Repository
public interface TrackRepository extends JpaRepository<Track, Integer>{

}