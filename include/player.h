#ifndef PLAYER_H
#define PLAYER_H
#include "constants.h"

class Player
{
public:
    float x, y;
    float width, height;
    int speed, score;

    // METHODS
    Player();
    void draw();
    void update();
};

#endif