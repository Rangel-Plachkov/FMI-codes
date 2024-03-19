package repository;

import models.Event;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Optional;

@SuppressWarnings("UnusedDeclaration")
public class EventRepository {

    private Map<Integer, Event> eventTable;

    public void addEvent(Event event) {
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
