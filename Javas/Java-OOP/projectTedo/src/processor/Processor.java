package processor;

import command.CommandExecutor;

import java.util.List;

public class Processor extends Thread {

    private final int id;
    private final CommandExecutor commandExecutor;

    public Processor(int id, CommandExecutor commandExecutor) {
        this.id = id;
        this.commandExecutor = commandExecutor;
    }

    @Override
    public void run() {


        System.out.println("Processor " + id + " started");

        List<List<Integer>> adjList = commandExecutor.getAdjList();

        while (!commandExecutor.isQueueEmpty()) {
            int current = commandExecutor.pollElementFromQueue();
            for (int i = 0; i < adjList.get(current).size(); i++) {
                int next = adjList.get(current).get(i);
                if (!commandExecutor.getVisited(next)) {
                    commandExecutor.addElementToQueue(next);
                    commandExecutor.setVisited(next, true);
                    commandExecutor.setDist(next, commandExecutor.getDist(current) + 1);
                    commandExecutor.setParent(next, current);
                }
            }
        }
    }
}
