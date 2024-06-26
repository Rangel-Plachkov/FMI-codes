package repository;

import models.Event;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.Optional;

import java.util.stream.Collectors;

@SuppressWarnings("UnusedDeclaration")
public class EventRepository {

    private static final Map<Integer, Event> eventTable = new HashMap<>();

    public void createEvent(Event event) {
        if(event.getID() != null) {
            throw new IllegalArgumentException("Cannot create Event with already given ID.");
        }
        event.setID();
        eventTable.put(event.getID(), event);
    }
    public void updateEvent(Event event) {
        if(event.getID() == null) {
            throw new IllegalArgumentException("Cannot update Event without ID.");
        }
        eventTable.put(event.getID(), event);
    }
    public boolean deleteEventById(Integer id) {
        return eventTable.remove(id) != null;
    }

    public Optional<Event> getEventById(Integer id) {
        return Optional.of(eventTable.get(id));
    }

    public List<Event> getAllEvents() {
        return new ArrayList<>(eventTable.values());
        //return eventTable.values().stream().collect(Collectors.toList());
    }
}
