package mk.finki.ukim.mk.lab.bootstrap;

import jakarta.annotation.PostConstruct;
import mk.finki.ukim.mk.lab.model.Event;
import mk.finki.ukim.mk.lab.model.Location;
import org.springframework.stereotype.Component;

import java.util.ArrayList;
import java.util.List;

@Component
public class DataHolder {
    public static List<Event> eventList = new ArrayList<>();
    public static List<Location> locationList = new ArrayList<>();

    @PostConstruct
    public void init() {
        locationList.add(new Location("Rakometno", "Adresa 1", "500", "Deskripcija za rakometno"));
        locationList.add(new Location("Dihovo", "Adresa 2", "1235", "Deskripcija za dihovo"));
        locationList.add(new Location("Silbo", "Adresa 3", "150", "Deskripcija za silbo"));
        locationList.add(new Location("Imperator", "Adresa 4", "300", "Deskripcija za imperator"));
        locationList.add(new Location("Netavile", "Adresa 5", "80", "Deskripcija za netavile"));

        eventList.add(new Event("Gamers Cup", "A finale where gamers compete for the title of BEST", 10.00, locationList.get(0)));
        eventList.add(new Event("Cooking Show", "The best chefs show you how its done", 7.30, locationList.get(1)));
        eventList.add(new Event("Basketball Finale", "The 2 best teams will settle their score in a 3v3 showoff", 10.00, locationList.get(2)));
        eventList.add(new Event("CS Meetup", "Biggest meetup for the students of FINKI", 9.25, locationList.get(3)));
        eventList.add(new Event("Bullet Chess Finale", "Fastest chess players will challange the title of GM", 6.75, locationList.get(4)));
        eventList.add(new Event("National Volleyball Championship", "The brackets will face off in the start of the national championship", 7.45, locationList.get(1)));
        eventList.add(new Event("Test", "This is a test example with description", 2.15, locationList.get(0)));
        eventList.add(new Event("Test Number 2", "This is the second test", 1.45, locationList.get(2)));
        eventList.add(new Event("Test Finale", "This is the final test of the test section", 1.00, locationList.get(4)));
        eventList.add(new Event("Code Wars", "A hackaton for the fastest programmers", 10.00, locationList.get(3)));
    }
}
