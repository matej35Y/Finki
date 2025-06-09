package mk.finki.ukim.mk.lab.web;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import mk.finki.ukim.mk.lab.model.SavedBooking;
import mk.finki.ukim.mk.lab.service.EventService;
import org.thymeleaf.context.IWebContext;
import org.thymeleaf.context.WebContext;
import org.thymeleaf.spring6.SpringTemplateEngine;
import org.thymeleaf.web.IWebExchange;
import org.thymeleaf.web.servlet.JakartaServletWebApplication;

import java.io.IOException;
import java.util.List;

@WebServlet(name = "EventBookingServlet", urlPatterns = {"/servlet/events/event-booking"})
public class EventBookingServlet extends HttpServlet {

    private final EventService eventService;
    private final SpringTemplateEngine templateEngine;

    public EventBookingServlet(EventService eventService, SpringTemplateEngine templateEngine) {
        this.eventService = eventService;
        this.templateEngine = templateEngine;
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String queryString = req.getParameter("bookingSearch");
        List<SavedBooking> bookingsToSend = eventService.getSavedBookings().stream()
                .filter(booking -> booking.getEventName().toLowerCase().contains(queryString.toLowerCase()))
                .toList();

        IWebExchange iWebExchange = JakartaServletWebApplication.buildApplication(req.getServletContext()).buildExchange(req, resp);
        WebContext context = new WebContext(iWebExchange);
        context.setVariable("savedBookingList", bookingsToSend);
        templateEngine.process("bookingConfirmation.html", context, resp.getWriter());
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        List<SavedBooking> savedBookingList = eventService.getSavedBookings();

        String eventName = req.getParameter("rad");
        String numOfTickets = req.getParameter("numTickets");

        eventService.addBooking(eventName, Integer.parseInt(numOfTickets));

        IWebExchange iWebExchange = JakartaServletWebApplication.buildApplication(req.getServletContext()).buildExchange(req, resp);
        WebContext context = new WebContext(iWebExchange);
        context.setVariable("hostName", req.getRemoteHost());
        context.setVariable("hostAddress", req.getRemoteAddr());
        context.setVariable("eventName", eventName);
        context.setVariable("numOfTickets", numOfTickets);
        context.setVariable("savedBookingList", savedBookingList);
        templateEngine.process("bookingConfirmation.html", context, resp.getWriter());
    }
}
