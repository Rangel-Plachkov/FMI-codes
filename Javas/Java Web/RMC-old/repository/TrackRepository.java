package repository;

import models.Track;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.ArrayList;
@SuppressWarnings("UnusedDeclaration")
public class TrackRepository {

    private final Map<Integer, Track> trackMapTable = new HashMap<>();


    public void addTrack(Track track) {
        trackMapTable.put(track.getID(), track);
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