import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Solver {
    private final SearchNode goalNode;

    private static final byte UP = 0;
    private static final byte DOWN = 1;
    private static final byte LEFT = 2;
    private static final byte RIGHT = 3;

    private static class SearchNode implements Comparable<SearchNode> {
        private final Board board;
        private final int moves;
        private final SearchNode previous;
        private final byte direction;
        private final int priority;

        public SearchNode(Board board, int moves, SearchNode previous, byte direction) {
            this.board = board;
            this.moves = moves;
            this.previous = previous;
            this.direction = direction;
            this.priority = board.manhattan() + moves;
        }

        @Override
        public int compareTo(SearchNode other) {
            return Integer.compare(this.priority, other.priority);
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            SearchNode that = (SearchNode) obj;
            return board.equals(that.board);
        }
        @Override
        public int hashCode() {
            return board.hashCode();
        }

    }

    public Solver(Board initial) {
        if (initial == null) throw new IllegalArgumentException("Initial board cannot be null");
        if (!initial.isSolvable()) throw new IllegalArgumentException("Unsolvable board");

        PriorityQueue<SearchNode> pq = new PriorityQueue<>();
        pq.add(new SearchNode(initial, 0, null, (byte) -1));

        SearchNode currentNode;
        while (true) {
            currentNode = pq.poll();
            if (currentNode == null ||currentNode.board.isGoal()) break;

            for (Board neighbor : currentNode.board.neighbors()) {
                if (currentNode.previous == null || !neighbor.equals(currentNode.previous.board)) {
                    byte direction = getDirection(currentNode.board, neighbor);
                    pq.add(new SearchNode(neighbor, currentNode.moves + 1, currentNode, direction));
                }
            }
        }
        this.goalNode = currentNode;
    }


    public int moves() {
        return goalNode.moves;
    }

    public Iterable<Board> solution() {
        List<Board> solutionPath = new ArrayList<>();
        for (SearchNode node = goalNode; node != null; node = node.previous) {
            solutionPath.add(node.board);
        }
        Collections.reverse(solutionPath);
        return solutionPath;
    }

    public Iterable<String> solutionDirections() {
        List<String> directions = new ArrayList<>();
        for (SearchNode node = goalNode; node != null; node = node.previous) {
            if (node.direction != -1) {
                directions.add(decryptDirection(node.direction));
            }
        }
        Collections.reverse(directions);
        return directions;
    }

    private String decryptDirection(byte direction) {
        return switch (direction) {
            case UP -> "up";
            case DOWN -> "down";
            case LEFT -> "left";
            case RIGHT -> "right";
            default -> throw new IllegalArgumentException("Invalid direction");
        };
    }

    private byte getDirection(Board board1, Board board2) {
        int[] pos1 = board1.blankPosition();
        int[] pos2 = board2.blankPosition();

        if (pos1[0] == pos2[0]) {
            if (pos1[1] < pos2[1]) return LEFT;
            if (pos1[1] > pos2[1]) return RIGHT;
        } else if (pos1[1] == pos2[1]) {
            if (pos1[0] < pos2[0]) return UP;
            return DOWN; // pos1[0] > pos2[0]
        }
        throw new IllegalArgumentException("Boards are not adjacent");
    }
    private static void printSolutionPath(Solver solver){
        System.out.println("Solution path:");
        for (Board board : solver.solution()) {
            System.out.println(board);
        }
    }
    private static void printSolutionDirections(Solver solver){
        System.out.println("Solution directions:");
        for (String direction : solver.solutionDirections()) {
            System.out.println(direction);
        }
    }



    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        n = (int) Math.sqrt((n + 1));

        int zeroPosition = scanner.nextInt();
        if(zeroPosition == -1) zeroPosition = 0;

        int[][] tiles = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tiles[i][j] = scanner.nextInt();
            }
        }
        long time = System.currentTimeMillis();
        Board initial = new Board(tiles, zeroPosition);

        try {
            Solver solver = new Solver(initial);
            //System.out.println("Execution time: " + (System.currentTimeMillis() - time) + " milliseconds");
            System.out.println("Minimum number of moves = " + solver.moves());
            //printSolutionPath(solver);
            printSolutionDirections(solver);
        } catch (IllegalArgumentException e) {
            System.out.println("-1");
            //System.out.println(e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
