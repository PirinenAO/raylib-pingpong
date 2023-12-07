#include "../include/opponent.h"

OPPONENT::OPPONENT()
{
    width = 100;
    height = 20;
    x = screenWidth / 2 - width / 2;
    y = 30;
    speed = 7;
}

void OPPONENT::update(int ball_x)
{
    // opponents paddle is following x coordinate of the ball
    if (x + width / 2 > ball_x)
    {
        x = x - speed;
    }
    else if (x + width / 2 < ball_x)
    {
        x = x + speed;
    }
}