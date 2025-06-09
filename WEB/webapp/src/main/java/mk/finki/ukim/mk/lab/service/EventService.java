package mk.finki.ukim.mk.lab.service;

import mk.finki.ukim.mk.lab.model.Event;
import mk.finki.ukim.mk.lab.model.Location;
import mk.finki.ukim.mk.lab.model.SavedBooking;

import java.util.List;
import java.util.Optional;

public interface EventService {
    List<Event> listAll();
    List<Event> searchEvents(String text);
    List<SavedBooking> getSavedBookings();
    void addBooking(String evName, int numTickets);
    void deleteById(Long id);
    Optional<Event> save(String name, String description, double popularityScore, Long locationId);
    Optional<Event> findById(Long id);
}
