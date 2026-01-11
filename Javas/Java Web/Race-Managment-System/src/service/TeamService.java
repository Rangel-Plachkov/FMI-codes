package service;

import repository.TeamRepository;
import models.Team;

import java.util.List;
import java.util.Objects;
@SuppressWarnings("UnusedDeclaration")
public class TeamService {
    TeamRepository teamRepository = new TeamRepository();

    public List<Team> getAllTeams() {
        return teamRepository.getAllTeams();
    }
    public List<Team> getAllTeamsByTeamName(String teamName) {
        return teamRepository.getAllTeams().stream()
                .filter(team -> Objects.equals(team.getName(), teamName) )
                .toList();
    }
    public void createTeam(String name, String country) {
        teamRepository.createTeam(new Team(name));
    }
    public boolean deleteTeamByName(String name) {
        return teamRepository.deleteTeamByName(name);
    }


}
