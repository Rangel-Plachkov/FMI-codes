#include <iostream>

using namespace std;

const int NUM_ROWS = 7;
const int NUM_COLS = 5;

int isInteresting(const int input[NUM_ROWS][NUM_COLS], const size_t sizeN, const size_t sizeM) {
    for (size_t x = 0; x < sizeN - 1; x++) {
        for (size_t y = 0; y < sizeM - 1; y++) {
            if (input[x][y] + input[x+1][y+1] > input[x+1][y] + input[x][y+1]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int arr[NUM_ROWS][NUM_COLS] = {
        {15, 19, 8, 4, 25},
        {16, 18, 5, 1, 20},
        {50, 35, 22, 10, 24},
        {91, 64, 21, 9, 5},
        {90, 60, 16, 4, 0},
        {100, 70, 20, 4, 0},
        {120, 75, 22, 5, 1}
    };
    cout << isInteresting(arr, NUM_ROWS, NUM_COLS) << endl;

    return 0;
}
