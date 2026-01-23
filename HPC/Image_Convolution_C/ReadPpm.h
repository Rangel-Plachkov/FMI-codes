#ifndef READPPM_H
#define READPPM_H

#include <stdint.h>

#define GRID_WIDTH (100)    //x
#define GRID_HEIGHT (100)   //y

typedef struct Pixel {
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;
}Pixel;

Pixel* load_ppm(const char * filename);



#endif //READPPM_H
