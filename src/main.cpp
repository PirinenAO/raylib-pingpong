#include "raylib.h"
#include "../include/ball.h"
#include "../include/player.h"
#include "../include/constants.h"
#include "../include/opponent.h"
#include "../include/menu.h"
#include <chrono>

int main(void)
{
    Ball ball;
    Player player;
    Opponent opponent;
    Menu menu;

    InitWindow(screenWidth, screenHeight, "Ping Pong");

    SetTargetFPS(60);

    while (menu.status && !WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        menu.update();
        menu.draw();
        EndDrawing();
    }
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // updating objects
        ball.update(player);
        player.update();
        opponent.update(ball.x);

        // if ball collides with paddle
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            ball.y = player.y - ball.radius; // fixing the bug where the ball gets stuck inside paddle
            ball.speed_y *= -1;
            player.score++;
        }

        // if ball collides with opposing paddle
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{opponent.x, opponent.y, opponent.width, opponent.height}))
        {
            ball.speed_y *= -1;

            // increasing speed
            if (ball.speed_y > 0)
            {
                ball.speed_y++;
                opponent.speed++;
            }
            else if (ball.speed_y < 0)
            {
                ball.speed_y--;
            }
        }

        // drawing objects
        ball.draw();
        player.draw();
        opponent.draw();
        DrawText(TextFormat("%i", player.score), screenWidth / 2, screenHeight / 2 - 25, 50, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
