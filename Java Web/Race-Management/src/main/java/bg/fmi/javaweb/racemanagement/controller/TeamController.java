package bg.fmi.javaweb.racemanagement.controller;

import bg.fmi.javaweb.racemanagement.dtos.RacerDTO;
import bg.fmi.javaweb.racemanagement.mapper.RacerMapper;
import bg.fmi.javaweb.racemanagement.mapper.RacerMapperT;
import bg.fmi.javaweb.racemanagement.mapper.TeamMapper;
import bg.fmi.javaweb.racemanagement.models.Team;
import bg.fmi.javaweb.racemanagement.service.TeamService;
import bg.fmi.javaweb.racemanagement.dtos.TeamDTO;
import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/teams")
public class TeamController {
    @Autowired
    private final TeamService teamService;

    public TeamController(TeamService teamService) {
        this.teamService = teamService;
    }


    @PostMapping("/")
    public ResponseEntity<TeamDTO> createTeam(@Valid @RequestBody TeamDTO newTeam) {
        teamService.createTeam(newTeam.getName());
        for(RacerDTO racerDTO : newTeam.getRacers()) {
            teamService.addRacerToTeam(newTeam.getName(), RacerMapperT.dtoToEntity(racerDTO));
        }
        return new ResponseEntity<>(newTeam, org.springframework.http.HttpStatus.CREATED);
    }
    @GetMapping("/")
    public ResponseEntity<List<TeamDTO>> getTeams(@RequestParam(name = "teamName", required = false) String teamName) {
        List<Team> temp;
        ArrayList<TeamDTO> result = new ArrayList<>();
        if(teamName != null) {
            temp = teamService.getAllTeamsByTeamName(teamName);
            for (Team team : temp) {
                result.add(TeamMapper.entityToDto(team));
            }
        } else {
            temp = teamService.getAllTeams();
            for (Team team : temp) {
                result.add(TeamMapper.entityToDto(team));
            }
        }
        return new ResponseEntity<>(result, org.springframework.http.HttpStatus.OK);
    }
    @PatchMapping("/")
    public ResponseEntity<TeamDTO> updateTeam(@Valid @RequestParam(name = "name") String name, @RequestBody TeamDTO newTeam) {
        if(teamService.deleteTeamByName(name)) {
            teamService.createTeam(newTeam.getName());
            return new ResponseEntity<>(newTeam, HttpStatus.NO_CONTENT);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }
    @DeleteMapping("/")
    public ResponseEntity<TeamDTO> deleteTeam(@RequestParam(name = "name") String name) {
        if(teamService.deleteTeamByName(name)) {
            return new ResponseEntity<>(HttpStatus.NO_CONTENT);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }

}
