#ifndef BALL_H
#define BALL_H
#include "constants.h"

class BALL
{
public:
    float x, y;
    int speed_x, speed_y, score, radius;

    // METHODS
    BALL();
    void draw();
    void update();
};

#endif