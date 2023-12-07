#include "raylib.h"
#include "../include/ball.h"
#include "../include/player.h"
#include "../include/constants.h"
#include "../include/opponent.h"

int main(void)
{
    BALL ball;
    PLAYER player;
    OPPONENT opponent;

    InitWindow(screenWidth, screenHeight, "Ping Pong");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // updating objects
        ball.update();
        player.update();
        opponent.update(ball.x);

        // if ball collides with paddle
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            ball.y = player.y - ball.radius; // fixing the bug where the ball gets stuck inside paddle
            ball.speed_y *= -1;
            ball.score++;
        }

        // if ball collides with opposing paddle
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{opponent.x, opponent.y, opponent.width, opponent.height}))
        {
            ball.speed_y *= -1;

            // increasing speed
            if (ball.speed_y > 0)
            {
                ball.speed_y++;
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
        DrawText(TextFormat("%i", ball.score), screenWidth / 2, screenHeight / 2 - 25, 50, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
