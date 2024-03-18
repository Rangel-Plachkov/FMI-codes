import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
@SuppressWarnings("UnusedDeclaration")
public class TeamRepository {

    private final Map<String, Team> teamTable = new HashMap<>();

    public void addTeam(Team team) {
        teamTable.put(team.getName(), team);
    }

    public boolean deleteTeamByName(String name) {
        return teamTable.remove(name) != null;
    }


    public Optional<Team> getTeamById(String name) {
        return Optional.ofNullable(teamTable.get(name));
    }

    public List<Team> getAllTeams() {
        return (List<Team>) teamTable.values();
    }
}
