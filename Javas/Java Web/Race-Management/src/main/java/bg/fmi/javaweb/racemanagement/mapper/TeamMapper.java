package bg.fmi.javaweb.racemanagement.mapper;

import bg.fmi.javaweb.racemanagement.models.Team;
import bg.fmi.javaweb.racemanagement.dtos.TeamDTO;

import java.util.ArrayList;


public class TeamMapper {
    public static Team dtoToEntity(TeamDTO teamDTO) {
        Team team = new Team();
        team.setName(teamDTO.getName());
        team.setRacers( new ArrayList<>());
        return team;
    }
    public static TeamDTO entityToDto(Team team) {
        TeamDTO teamDTO = new TeamDTO();
        teamDTO.setName(team.getName());

        return teamDTO;
    }


}
