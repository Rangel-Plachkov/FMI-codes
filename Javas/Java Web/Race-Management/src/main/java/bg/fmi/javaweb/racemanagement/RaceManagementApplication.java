package bg.fmi.javaweb.racemanagement;

import bg.fmi.javaweb.racemanagement.mapper.RacerMapper;
import bg.fmi.javaweb.racemanagement.service.*;
import bg.fmi.javaweb.racemanagement.models.*;
import java.time.LocalDate;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class RaceManagementApplication /*implements CommandLineRunner*/{

    public static void main(String[] args) {
        SpringApplication.run(RaceManagementApplication.class, args);
            
    }
    @Autowired
    private RacerService racerService;
    @Autowired
    private TeamService teamService;
    @Autowired
    private TrackService trackService;
    @Autowired
    private EventService eventService;


    @Autowired
    private ApplicationContext context;


}