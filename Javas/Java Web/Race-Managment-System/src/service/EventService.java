package service;

import models.Racer;
import models.Track;
import repository.EventRepository;
import models.Event;
import models.Team;


import java.util.ArrayList;
import java.util.List;
import java.time.LocalDate;

@SuppressWarnings("UnusedDeclaration")
public class EventService {
    EventRepository eventRepository = new EventRepository();

    public List<Event> getAllEvents(){
        return eventRepository.getAllEvents();
    }
    public List<Event> getAllRacersByTrackName(String trackName){
        return eventRepository.getAllEvents().stream()
                .filter(event -> event.getTrack().getName().equals(trackName))
                .toList();
    }
    public void createEvent(String eventName, Track track, ArrayList<Team> teams, LocalDate date){
        eventRepository.createEvent(new Event());
    }
    public boolean deleteEventByID(Integer eventID){
        return eventRepository.deleteEventById(eventID);
    }
    public List<Event> getAllEventsBefore(LocalDate date){
        return eventRepository.getAllEvents().stream()
                .filter(event -> event.getDate().isBefore(date))
                .toList();
    }
    public List<Event> getAllEventsAfter(LocalDate date){
        return eventRepository.getAllEvents().stream()
                .filter(event -> event.getDate().isAfter(date))
                .toList();
    }
    public List<Event> getUpcomingEvents(){
        return eventRepository.getAllEvents().stream()
                .filter(event -> event.getDate().isAfter(LocalDate.now()))
                .toList();
    }
    public List<Racer> getAllRacersFromNearestEvent(){
        return eventRepository.getAllEvents().stream()
                .filter(event -> event.getDate().isAfter(LocalDate.now()))
                .findFirst()
                .get()
                .getTeams()
                .stream()
                .flatMap(team -> team.getRacers().stream())
                .toList();
    }
    public List<Event> getEventsForTrack(Track track){
        return eventRepository.getAllEvents().stream()
                .filter(event -> event.getTrack().equals(track))
                .toList();
    }


}
