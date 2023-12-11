#ifndef BALL_H
#define BALL_H
#include "constants.h"
#include "player.h"

class Ball
{
public:
    float x, y;
    int speed_x, speed_y, radius;

    // METHODS
    Ball();
    void draw();
    void update(Player &player);
};

#endif