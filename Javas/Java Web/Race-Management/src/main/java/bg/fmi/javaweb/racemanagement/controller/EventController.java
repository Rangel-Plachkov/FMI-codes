package bg.fmi.javaweb.racemanagement.controller;

import bg.fmi.javaweb.racemanagement.models.Track;
import bg.fmi.javaweb.racemanagement.dtos.TrackDTO;
import bg.fmi.javaweb.racemanagement.service.EventService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;


import java.time.LocalDate;


@RestController
@RequestMapping("/events")
public class EventController {

    @Autowired
    private final EventService eventService;

    public EventController(EventService eventService) {
        this.eventService = eventService;
    }


    @GetMapping("/before")
    public String getAllEventsBefore(@RequestParam(name = "date" ,required = false) LocalDate date) {
        if(date == null) {
            return eventService.getAllEventsBefore(LocalDate.now()).toString();
        }
        return eventService.getAllEventsBefore(date).toString();
    }
    @GetMapping("/after")
    public String getAllEventsAfter(@RequestParam(name = "date" ,required = false) LocalDate date) {
        if(date == null) {
            return eventService.getAllEventsAfter(LocalDate.now()).toString();
        }
        return eventService.getAllEventsAfter(date).toString();
    }
    @GetMapping("/upcoming")
    public String getUpcomingEvents() {
        return eventService.getUpcomingEvents().toString();
    }
    @GetMapping("/")
    public String getAllEvents() {
        return eventService.getAllEvents().toString();
    }
    @GetMapping("/track")
    public String getAllRacersByTrackName(@RequestParam(name = "trackName") String trackName) {
        return eventService.getAllRacersByTrackName(trackName).toString();
    }
    @GetMapping("/nearest/racers")
    public String getAllRacersFromNearestEvent() {
        return eventService.getAllRacersFromNearestEvent().toString();
    }

    @PostMapping("/")
    public String createEvent(@RequestParam(name = "eventName") String eventName,
                              @RequestBody TrackDTO trackDTO,
                              @RequestParam(name = "date") LocalDate date) {

        Track track = new Track(trackDTO.getName(), trackDTO.getLength());
        eventService.createEvent(eventName, track, date);
        return "Event created";
    }
/*    @PostMapping("/")
    public String createEvent(@RequestParam(name = "eventName") String eventName,
                              @RequestBody TrackDTO trackDTO,
                              @RequestParam(name = "teams") String teams,
                              @RequestParam(name = "date") LocalDate date) {

        Track track = new Track(trackDTO.getName(), trackDTO.getLength());
        eventService.createEvent(eventName, track, date);
        return "Event created";
    }*/

    @DeleteMapping("/")
    public String deleteEventByID(@RequestParam(name = "eventID") Integer eventID) {
        if(eventService.deleteEventByID(eventID)) {
            return "Event with id " + eventID + " deleted";
        } else {
            return "Event with id " + eventID + " not found";
        }
    }
}
