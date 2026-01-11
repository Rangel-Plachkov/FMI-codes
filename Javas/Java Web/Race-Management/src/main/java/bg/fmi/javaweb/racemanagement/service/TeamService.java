package bg.fmi.javaweb.racemanagement.service;

import bg.fmi.javaweb.racemanagement.models.Racer;
import bg.fmi.javaweb.racemanagement.models.Team;

import bg.fmi.javaweb.racemanagement.repository.TeamRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

@Service
public class TeamService {
    @Autowired
    TeamRepository teamRepository;

    public List<Team> getAllTeams() {
        return teamRepository.findAll();
    }
    public List<Team> getAllTeamsByTeamName(String teamName) {
        return teamRepository.findAll().stream()
                .filter(team -> Objects.equals(team.getName(), teamName) )
                .toList();
    }
    public void createTeam(String name) {
        teamRepository.save(new Team(name));
    }
    public boolean deleteTeamByName(String name) {

        Optional<Team> teamOptional = teamRepository.findById(name);
        if (teamOptional.isPresent()) {
            teamRepository.deleteById(name);
            return true;
        } else {
            return false;
        }
    }
    public void addRacerToTeam(String teamName, Racer racer) {
        Optional<Team> teamOptional = teamRepository.findById(teamName);
        if (teamOptional.isPresent()) {
            Team team = teamOptional.get();
            team.getRacers().add(racer);
            teamRepository.save(team);
        } else {
            throw new RuntimeException("Team with name: " + teamName + " not found");
        }
    }
}
