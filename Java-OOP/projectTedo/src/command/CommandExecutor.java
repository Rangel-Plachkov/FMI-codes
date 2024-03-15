package command;


import processor.Processor;

import java.nio.channels.SelectionKey;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.LinkedBlockingQueue;

public class CommandExecutor {


    public synchronized void addElementToQueue(int element) {
        queue.add(element);
    }

    public synchronized int pollElementFromQueue() {

        if (queue.isEmpty()) {
            return -1;
        }
        return queue.poll();
    }

    public synchronized boolean isQueueEmpty() {
        return queue.isEmpty();
    }

    public synchronized void setVisited(int index, boolean value) {
        visited.set(index, value);
    }

    public synchronized boolean getVisited(int index) {
        return visited.get(index);
    }

    public synchronized void setDist(int index, int value) {
        dist.set(index, value);
    }

    public synchronized int getDist(int index) {
        return dist.get(index);
    }

    public synchronized void setParent(int index, int value) {
        parent.set(index, value);
    }


    public synchronized List<List<Integer>> getAdjList() {
        return adjList;
    }

    private final Queue<Integer> queue;
    private final List<Boolean> visited;
    private final List<List<Integer>> adjList;
    private final List<Integer> dist;
    private final List<Integer> parent;
    private static final String INVALID_ARGS_COUNT_MESSAGE_FORMAT =
        "Invalid count of arguments: \"%s\" expects %d arguments. Example: \"%s\"";

    public CommandExecutor() {
        this.queue = new LinkedBlockingQueue<>();
        this.visited = new CopyOnWriteArrayList<>();
        this.adjList = new ArrayList<>();
        this.dist = new ArrayList<>();
        this.parent = new ArrayList<>();
    }

    private static final String BFS = "bfs";

    public String execute(Command cmd, SelectionKey key) {
        return switch (cmd.command()) {
            case BFS -> bfs(cmd.arguments());
            default -> "Unknown command";
        };
    }

    private String bfs(String[] args)  {
        if (args.length < 2) {
            return String.format(INVALID_ARGS_COUNT_MESSAGE_FORMAT, BFS, 3,
                BFS + " <number_of_threads> <number_of_vertices> <edges..>");
        }


        int numberOfThreads = Integer.parseInt(args[0]);
        int numberOfVertices = Integer.parseInt(args[1]);

        //remove all data from previous bfs
        queue.clear();
        visited.clear();
        adjList.clear();
        dist.clear();

        for (int i = 0; i <= numberOfVertices; i++) {
            this.adjList.add(new CopyOnWriteArrayList<>());
            this.visited.add(false);
            this.dist.add(-1);
            this.parent.add(-1);
        }

        for (int i = 2; i < args.length; i += 2) {
            int from = Integer.parseInt(args[i]);
            int to = Integer.parseInt(args[i + 1]);
            adjList.get(from).add(to);
            adjList.get(to).add(from);
        }

        addElementToQueue(1);
        setVisited(1, true);
        setDist(1, 0);
        setParent(1, -1);

        Processor[] processors = new Processor[numberOfThreads];
        //create a new thread
        for (int i = 0; i < numberOfThreads; i++) {

            processors[i] = new Processor(i, this);
            processors[i].start();
        }


        for (int i = 0; i < numberOfThreads; i++) {
            try {
                processors[i].join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        StringBuilder result = new StringBuilder();
        for (int i = 1; i <= numberOfVertices; i++) {
            result.append("Distance to ").append(i).append(" from 1 is ").append(dist.get(i)).append("\n");
        }
        return result.toString();
    }
}
