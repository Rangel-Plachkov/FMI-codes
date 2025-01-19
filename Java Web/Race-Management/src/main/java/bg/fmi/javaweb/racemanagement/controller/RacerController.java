package bg.fmi.javaweb.racemanagement.controller;

import bg.fmi.javaweb.racemanagement.dtos.RacerDTO;
import bg.fmi.javaweb.racemanagement.mapper.RacerMapperT;
import bg.fmi.javaweb.racemanagement.models.Racer;
import bg.fmi.javaweb.racemanagement.service.RacerService;

import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;
import org.springframework.http.ResponseEntity;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/racers")
public class RacerController {

    @Autowired
    private final RacerService racerService;


    @Autowired
    public RacerController(RacerService racerService) {
        this.racerService = racerService;

    }

    @PatchMapping("/assignTeam/")
    public ResponseEntity<RacerDTO> assignTeam (@RequestParam(name = "racerId") Integer racerId, @RequestParam(name = "teamId") String teamId) {
        if (racerService.assignRacerToTeam(racerId, teamId)) {
            return new ResponseEntity<>(HttpStatus.NO_CONTENT);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }


    @GetMapping("/")
    public ResponseEntity<List<RacerDTO>> getRacers(@RequestParam(name = "firstName", required = false) String firstName) {
        List<Racer> temp;
        List<RacerDTO> result = new ArrayList<>();
        if(firstName != null) {
            temp = racerService.getAllRacersByFirstName(firstName);
            for (Racer racer : temp) {
                result.add(RacerMapperT.entityToDto(racer));
            }
        } else {
            temp = racerService.getAllRacers();
            for (Racer racer : temp) {
                result.add(RacerMapperT.entityToDto(racer));
            }
        }
        return new ResponseEntity<>(result, org.springframework.http.HttpStatus.OK);
    }

    @GetMapping("/{id}")
    public ResponseEntity<RacerDTO> getRacerById(@PathVariable Integer id) {
        return new ResponseEntity<>(RacerMapperT.entityToDto(racerService.getRacerById(id)), org.springframework.http.HttpStatus.OK);
    }

    @PostMapping("/")
    public ResponseEntity<RacerDTO> createRacer(@Valid @RequestBody RacerDTO newRacer) {
        racerService.createRacer(newRacer.getFirstName(), newRacer.getLastName(), newRacer.getAge());
        return new ResponseEntity<>(HttpStatus.CREATED);
    }
    @DeleteMapping("/")
    public ResponseEntity<RacerDTO> deleteRacer(@RequestParam(name = "id") Integer id) {
        if (racerService.deleteRacerById(id)) {
            return new ResponseEntity<>(HttpStatus.NO_CONTENT);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }
    @DeleteMapping("/all")
    public ResponseEntity<RacerDTO> deleteAllRacer() {
        racerService.deleteAllRacers();
        return new ResponseEntity<>(HttpStatus.NO_CONTENT);
    }
    @PatchMapping("/")
    public ResponseEntity<RacerDTO> updateRacer(@Valid @RequestParam(name = "id") Integer id, @RequestBody RacerDTO newRacer) {
        if (racerService.deleteRacerById(id)) {
            racerService.createRacer(newRacer.getFirstName(), newRacer.getLastName(), newRacer.getAge());
            return new ResponseEntity<>(HttpStatus.NO_CONTENT);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }
}
