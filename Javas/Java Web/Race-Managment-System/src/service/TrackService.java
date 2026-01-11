package service;

import repository.TrackRepository;
import models.Track;

import java.util.List;
@SuppressWarnings("UnusedDeclaration")
public class TrackService {
    TrackRepository trackRepository = new TrackRepository();

    public List<Track> getAllTracks() {
        return trackRepository.getAllTracks();
    }
    public List<Track> getAllTracksByTrackName(String trackName) {
        return trackRepository.getAllTracks().stream()
                .filter(track -> track.getName().equals(trackName) )
                .toList();
    }

    public void createTrack(String name, Integer length) {
        trackRepository.createTrack(new Track(name, length));
    }

    public boolean deleteTrackById(Integer id) {
        return trackRepository.deleteTrackById(id);
    }

}
