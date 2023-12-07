#include "../include/player.h"
#include "../include/constants.h"

PLAYER::PLAYER()
{
    width = 100;
    height = 20;
    x = screenWidth / 2 - width / 2;
    y = screenHeight - 50;
    speed = 14;
}

void PLAYER::draw()
{
    DrawRectangle(x, y, width, height, RED);
}

void PLAYER::update()
{
    // reads user input
    if (IsKeyDown(KEY_A))
    {
        x = x - speed;
    }
    else if (IsKeyDown(KEY_D))
    {
        x = x + speed;
    }

    // prevents paddle from crossing the borders
    if (x <= 0)
    {
        x = 0;
    }
    else if (x + width >= screenWidth)
    {
        x = screenWidth - width;
    }
}