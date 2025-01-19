package bg.fmi.javaweb.racemanagement.controller;

import bg.fmi.javaweb.racemanagement.dtos.TrackDTO;
import bg.fmi.javaweb.racemanagement.service.TrackService;

import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/tracks")
public class TrackController {

    @Autowired
    private final TrackService trackService;

    public TrackController(TrackService trackService) {
        this.trackService = trackService;
    }

    @PostMapping("/")
    public String createTrack(@Valid @RequestBody TrackDTO newTrack) {
        trackService.createTrack(newTrack.getName(), newTrack.getLength());
        return newTrack.toString();
    }
    @GetMapping("/")
    public String getTracks(@RequestParam(name = "trackName", required = false) String trackName) {
        if(trackName != null) {
            return trackService.getAllTracksByTrackName(trackName).toString();
        } else {
            return trackService.getAllTracks().toString();
        }
    }
    @PatchMapping("/")
    public String updateTrack(@Valid @RequestParam(name = "id") Integer id, @RequestBody TrackDTO newTrack) {
        if(trackService.deleteTrackById(id)) {
            trackService.createTrack(newTrack.getName(), newTrack.getLength());
            return "Track with name " + id + " updated";
        } else {
            return "Track with name " + id + " not found";
        }
    }
    @DeleteMapping("/")
    public String deleteTrack(@RequestParam(name = "id") Integer id) {
        if(trackService.deleteTrackById(id)) {
            return "Track with name " + id + " deleted";
        } else {
            return "Track with name " + id + " not found";
        }
    }
}
