package repository;

import models.Track;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.ArrayList;
@SuppressWarnings("UnusedDeclaration")
public class TrackRepository {

    private static final Map<Integer, Track> trackMapTable = new HashMap<>();


    public void createTrack(Track track) {
        if (track.getID() != null) {
            throw new IllegalArgumentException("Cannot create Track with already given ID.");
        }
        track.setID();
        trackMapTable.put(track.getID(), track);
    }
    public void updateTrack(Track track) {
        if (track.getID() == null) {
            throw new IllegalArgumentException("Cannot update Track without ID.");
        }
        trackMapTable.put(track.getID(), track);
    }

    public boolean deleteTrackById(Integer id) {
        return trackMapTable.remove(id) != null;
    }
    public boolean deleteTrackByName(String name) {
        for (Map.Entry<Integer, Track> entry : trackMapTable.entrySet()) {
            if (entry.getValue().getName().equals(name)) {
                trackMapTable.remove(entry.getKey());
                return true;
            }
        }
        return false;
    }

    public Optional<Track> getTrackById(Integer id) {
        return Optional.of(trackMapTable.get(id));
    }

    public List<Track> getAllTracks() {
        return new ArrayList<>(trackMapTable.values());
    }
}