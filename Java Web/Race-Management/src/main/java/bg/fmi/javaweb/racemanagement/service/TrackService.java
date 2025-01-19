package bg.fmi.javaweb.racemanagement.service;

import bg.fmi.javaweb.racemanagement.models.Team;
import bg.fmi.javaweb.racemanagement.models.Track;
import bg.fmi.javaweb.racemanagement.repository.TrackRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class TrackService {
    @Autowired
    TrackRepository trackRepository;

    public List<Track> getAllTracks() {
        return trackRepository.findAll();
    }
    public List<Track> getAllTracksByTrackName(String trackName) {
        return trackRepository.findAll().stream()
                .filter(track -> track.getName().equals(trackName) )
                .toList();
    }

    public void createTrack(String name, Integer length) {
        trackRepository.save(new Track(name, length));
    }

    public boolean deleteTrackById(Integer id) {
        Optional<Track> teamOptional = trackRepository.findById(id);
        if (teamOptional.isPresent()) {
            trackRepository.deleteById(id);
            return true;
        } else {
            return false;
        }
    }

}
