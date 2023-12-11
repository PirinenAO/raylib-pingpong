#include "raylib.h"
#include "../include/ball.h"
#include "../include/player.h"
#include "../include/constants.h"
#include "../include/opponent.h"
#include "../include/menu.h"
#include <iostream>

void checkPlayerCollision(Player &player, Ball &ball);
void checkOpponentCollision(Opponent &opponent, Ball &ball);

int main(void)
{
    Ball ball;
    Player player;
    Opponent opponent;
    Menu menu;
    float timer;
    InitWindow(screenWidth, screenHeight, "Ping Pong");

    SetTargetFPS(60);

    // START MENU LOOP
    while (menu.status && !WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        menu.update();
        menu.draw();
        EndDrawing();
    }

    // GAME LOOP
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // updating objects
        ball.update(player, opponent);
        player.update();
        opponent.update(ball.x);

        // check collisions
        checkPlayerCollision(player, ball);
        checkOpponentCollision(opponent, ball);

        // drawing objects
        ball.draw();
        player.draw();
        opponent.draw();

        // draw score
        DrawText(TextFormat("%i", player.score), screenWidth / 2, screenHeight / 2 - 25, 50, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void checkPlayerCollision(Player &player, Ball &ball)
{

    // if ball collides with paddle
    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}) && ball.speed_x > 0 && IsKeyDown(KEY_D))
    {
        ball.speed_x *= -1;
        ball.y = player.y - ball.radius; // fixing the bug where the ball gets stuck inside paddle
        ball.speed_y *= -1;
        player.score++;
    }
    else if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}) && ball.speed_x < 0 && IsKeyDown(KEY_A))
    {
        ball.speed_x *= -1;
        ball.y = player.y - ball.radius; // fixing the bug where the ball gets stuck inside paddle
        ball.speed_y *= -1;
        player.score++;
    }
    else if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
    {
        ball.y = player.y - ball.radius; // fixing the bug where the ball gets stuck inside paddle
        ball.speed_y *= -1;
        player.score++;
    }
}

void checkOpponentCollision(Opponent &opponent, Ball &ball)
{
    // if ball collides with opposing paddle
    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{opponent.x, opponent.y, opponent.width, opponent.height}))
    {

        ball.speed_y *= -1;
        // increasing speed

        if (ball.speed_y > 0)
        {
            ball.speed_y++;
        }
        else
        {
            ball.speed_y--;
        }

        if (ball.speed_x > 0)
        {
            ball.speed_x++;
        }
        else
        {
            ball.speed_x--;
        }

        opponent.speed++;
    }
}
