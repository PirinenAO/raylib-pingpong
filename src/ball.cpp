#include "../include/ball.h"

BALL::BALL()
{
    radius = 10;
    x = screenWidth / 2 + 10;
    y = screenHeight / 2;
    speed_x = 7;
    speed_y = 7;
    score = 0;
}

void BALL::draw()
{
    DrawCircle(x, y, radius, RED);
}

void BALL::update()
{
    x += speed_x;
    y += speed_y;

    // if player misses the ball
    if (y + radius >= screenHeight)
    {
        x = screenWidth / 2;
        y = screenHeight / 2;
        speed_y = 7;
        speed_x = speed_x * -1;
        score = 0;
    }
    else if (y + radius <= 0)
    {
        x = screenWidth / 2;
        y = screenHeight / 2;
        speed_y = 7;
        speed_x = 7;
    }

    // reversing the direction of x when hitting side borders
    if (x + radius >= screenWidth || x - radius <= 0)
    {
        speed_x *= -1;
    }
}