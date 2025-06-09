package mk.finki.ukim.mk.lab.model;

import lombok.Data;

@Data
public class SavedBooking {
    private String eventName;
    private int numberOfTickets;

    public SavedBooking(String eventName, int numberOfTickets) {
        this.eventName = eventName;
        this.numberOfTickets = numberOfTickets;
    }

    public String getEventName() {
        return eventName;
    }

    public void setEventName(String eventName) {
        this.eventName = eventName;
    }

    public int getNumberOfTickets() {
        return numberOfTickets;
    }

    public void setNumberOfTickets(int numberOfTickets) {
        this.numberOfTickets = numberOfTickets;
    }
}
