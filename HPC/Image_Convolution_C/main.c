#include <stdio.h>
#include "ReadPpm.h"

#define KERNEL_WIDTH (3)    //x
#define KERNEL_HEIGHT (3)   //y


int main(void) {
    double grid[GRID_WIDTH][GRID_HEIGHT];
    for (int x = 0; x < GRID_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            grid[x][y] = 0.0;
        }
    }



    printf("Hello, World!\n");
    return 0;
}