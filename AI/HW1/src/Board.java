import java.util.LinkedList;
import java.util.Queue;

public class Board {
    private final int[][] tiles;
    private final int N;
    private final int zeroPosition;

    public Board(int[][] tiles, int zeroPosition) {
        this.N = tiles.length;
        this.tiles = new int[N][N];
        this.zeroPosition = zeroPosition;

        for (int i = 0; i < N; i++) {
            System.arraycopy(tiles[i], 0, this.tiles[i], 0, N);
        }
    }
    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append(N).append("\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                s.append(String.format("%2d ", tiles[i][j]));
            }
            s.append("\n");
        }
        return s.toString();
    }
    public int tileAt(int row, int col) {
        return tiles[row][col];
    }
    public int size() {
        return N;
    }
    public int hamming() {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == N - 1 && j == N - 1) {
                    continue;
                }
                if (tiles[i][j] != i * N + j + 1) {
                    count++;
                }
            }
        }
        return count;
    }
    public int manhattan() {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int value = tiles[i][j];
                if (value == 0) {
                    continue;
                }
                int expectedRow = (value - 1) / N;
                int expectedCol = (value - 1) % N;
                count += Math.abs(i - expectedRow) + Math.abs(j - expectedCol);
            }
        }
        return count;
    }
    public boolean isGoal() {
        return hamming() == 0;
    }

    @Override
    public boolean equals(Object y) {
        if (y == this) {
            return true;
        }
        if (y == null || y.getClass() != this.getClass()) {
            return false;
        }
        Board that = (Board) y;
        if (that.size() != this.size()) {
            return false;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (this.tiles[i][j] != that.tiles[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    @Override
    public int hashCode() {
        int hash = 17;
        hash = 31 * hash + N;
        for (int[] row : tiles) {
            for (int value : row) {
                hash = 31 * hash + value;
            }
        }
        return hash;
    }
    public Iterable<Board> neighbors() {
        Queue<Board> neighbors = new LinkedList<>();

        int zeroRow = 0;
        int zeroCol = 0;
        boolean found = false;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (tiles[x][y] == 0) {
                    zeroRow = x;
                    zeroCol = y;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (zeroRow > 0) {
            Board neighbor = new Board(tiles , zeroPosition);
            neighbor.swap(zeroRow, zeroCol, zeroRow - 1, zeroCol);
            neighbors.add(neighbor);
        }
        if (zeroRow < N - 1) {
            Board neighbor = new Board(tiles , zeroPosition);
            neighbor.swap(zeroRow, zeroCol, zeroRow + 1, zeroCol);
            neighbors.add(neighbor);
        }
        if (zeroCol > 0) {
            Board neighbor = new Board(tiles , zeroPosition);
            neighbor.swap(zeroRow, zeroCol, zeroRow, zeroCol - 1);
            neighbors.add(neighbor);
        }
        if (zeroCol < N - 1) {
            Board neighbor = new Board(tiles , zeroPosition);
            neighbor.swap(zeroRow, zeroCol, zeroRow, zeroCol + 1);
            neighbors.add(neighbor);
        }
        return neighbors;
    }
    public boolean isSolvable(){
        int inversions = inversionsCount();
        if (N % 2 == 1) {
            return inversions % 2 == 0;
        } else {
            int zeroRow = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (tiles[i][j] == 0) {
                        zeroRow = i;
                        break;
                    }
                }
            }
            return (zeroRow + inversions) % 2 == 1;
        }
    }
    public int[] blankPosition() {
          int[] position = new int[2];
          for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (tiles[i][j] == 0) {
                      position[0] = i;
                      position[1] = j;
                      return position;
                    }
                }
          }
          return position;
    }
    private int inversionsCount() {
        int inversions = 0;
        int[] arr = toOneDimensionalArray();
        for (int i = 0; i < N * N; i++) {
            for (int j = i + 1; j < N * N; j++) {
                if (arr[i] != 0 && arr[j] != 0 && arr[i] > arr[j]) {
                    inversions++;
                }
            }
        }
        return inversions;
    }
    private int[] toOneDimensionalArray() {
        int[] arr = new int[N * N];
        int k = 0;
        for (int[] row : tiles) {
            for (int value : row) {
                arr[k] = value;
                k++;
            }
        }
        return arr;
    }
    private void swap(int row1, int col1, int row2, int col2) {
        int temp = tiles[row1][col1];
        tiles[row1][col1] = tiles[row2][col2];
        tiles[row2][col2] = temp;
    }
}