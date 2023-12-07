#ifndef PLAYER_H
#define PLAYER_H
#include "constants.h"

class PLAYER
{
public:
    float x, y;
    float width, height;
    int speed;

    // METHODS
    PLAYER();
    void draw();
    void update();
};

#endif