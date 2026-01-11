import command.CommandExecutor;
import server.Server;


public class Main {
    private static final int SERVER_PORT = 8080;

    public static void main(String[] args) {

        CommandExecutor commandExecutor = new CommandExecutor();

        Server server = new Server(SERVER_PORT, commandExecutor);

        server.start();

        server.stop();
    }
}