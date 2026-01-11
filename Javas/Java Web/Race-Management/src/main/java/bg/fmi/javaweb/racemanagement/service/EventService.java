package bg.fmi.javaweb.racemanagement.service;

import bg.fmi.javaweb.racemanagement.models.*;
import bg.fmi.javaweb.racemanagement.repository.EventRepository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


import java.util.ArrayList;
import java.util.List;
import java.time.LocalDate;
import java.util.Optional;

@Service
public class EventService {
    @Autowired
    EventRepository eventRepository;

    public List<Event> getAllEvents(){
        return eventRepository.findAll();
    }
    public List<Event> getAllRacersByTrackName(String trackName){
        return eventRepository.findAll().stream()
                .filter(event -> event.getTrack().getName().equals(trackName))
                .toList();
    }
    public void createEvent(String eventName, Track track, ArrayList<Team> teams, LocalDate date){
        eventRepository.save(new Event(eventName, track, teams, date));
    }
    public void createEvent(String eventName, Track track, LocalDate date){
        eventRepository.save(new Event(eventName, track, date));
    }

    public boolean deleteEventByID(Integer eventID){
        Optional<Event> eventOptional = eventRepository.findById(eventID);
        if(eventOptional.isPresent()){
            eventRepository.deleteById(eventID);
            return true;
        }else{
            return false;
        }
    }
    public List<Event> getAllEventsBefore(LocalDate date){
        return eventRepository.findAll().stream()
                .filter(event -> event.getDate().isBefore(date))
                .toList();
    }
    public List<Event> getAllEventsAfter(LocalDate date){
        return eventRepository.findAll().stream()
                .filter(event -> event.getDate().isAfter(date))
                .toList();
    }
    public List<Event> getUpcomingEvents(){
        return eventRepository.findAll().stream()
                .filter(event -> event.getDate().isAfter(LocalDate.now()))
                .toList();
    }
    public List<Racer> getAllRacersFromNearestEvent(){
        return eventRepository.findAll().stream()
                .filter(event -> event.getDate().isAfter(LocalDate.now()))
                .findFirst()
                .get()
                .getTeams()
                .stream()
                .flatMap(team -> team.getRacers().stream())
                .toList();
    }
    public List<Event> getEventsForTrack(Track track){
        return eventRepository.findAll().stream()
                .filter(event -> event.getTrack().equals(track))
                .toList();
    }


}
