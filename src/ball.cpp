#include "../include/ball.h"
#include "../include/player.h"
#include "../include/opponent.h"

Ball::Ball()
{
    radius = 10;
    x = screenWidth / 2 + 10;
    y = screenHeight / 2;
    speed_x = 5;
    speed_y = 5;
}

void Ball::draw()
{
    DrawCircle(x, y, radius, RED);
}

void Ball::update(Player &player, Opponent &opponent)
{

    x -= speed_x;
    y -= speed_y;

    // if player misses the ball
    if (y + radius >= screenHeight)
    {
        x = screenWidth / 2;
        y = screenHeight / 2;
        speed_y = 5;
        speed_x = 5;
        speed_x = speed_x * -1;
        player.score = 0;
        opponent.speed = 5;
    }
    else if (y + radius <= 0)
    {
        x = screenWidth / 2;
        y = screenHeight / 2;
        speed_y = 5;
        speed_x = 5;
        speed_x = speed_x * -1;
        opponent.speed = 5;
    }

    // reversing the direction of x when hitting side borders
    if (x + radius >= screenWidth || x - radius <= 0)
    {
        speed_x *= -1;
    }
}