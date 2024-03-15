package Homeworks.Hw_3;
public class RouteCipher {
    public static void main(String[] args) {
        String text = "abort the mission you have been spotted";
        int key = 5;
        String encrypted = encrypt(text, key);
        System.out.println(encrypted);
    }
    private static String encrypt(String input, int key){
        if(key == 0 || input.isEmpty()){
            return input;
        }else if(key < 0){
            key *= -1;
        }
        input = removeSpaces(input);
        char[][] grid = stringToGrid(input,key);
        return new String(spiralCounterclockwiseTL(grid));

    }
    private static String removeSpaces(String input) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < input.length(); i++) {
            char character = input.charAt(i);
            if (character != ' ') {
                result.append(character);
            }
        }

        return result.toString();
    }
    private static char[][] stringToGrid(String input, int numColumns) {
        int length = input.length();
        int numRows = (length + numColumns - 1) / numColumns;
        char[][] grid = new char[numRows][numColumns];

        int charIndex = 0;
        for (int x = 0; x < numRows; x++) {
            for (int y = 0; y < numColumns; y++) {
                if (charIndex < length) {
                    grid[x][y] = input.charAt(charIndex);
                    charIndex++;
                } else {
                    grid[x][y] = 'X';
                }
            }
        }
        return grid;
    }


    private static char[] spiralCounterclockwiseTL(char[][] grid) {

        int numRows = grid.length;
        int numCols = grid[0].length;
        char[] result = new char[numRows * numCols];
        int top = 0, bottom = numRows - 1, left = 0, right = numCols - 1;
        int index = 0;

        while (top <= bottom && left <= right) {
            for (int i = top; i <= bottom; i++) {
                result[index++] = grid[i][left];
            }
            left++;
            if (top > bottom || left > right) {
                break;
            }
            for (int i = left; i <= right; i++) {
                result[index++] = grid[bottom][i];
            }
            bottom--;
            for (int i = bottom; i >= top; i--) {
                result[index++] = grid[i][right];
            }
            right--;
            for (int i = right; i >= left; i--) {
                result[index++] = grid[top][i];
            }
            top++;
        }
        return result;
    }
}
