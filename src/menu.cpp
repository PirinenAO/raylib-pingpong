#include "../include/menu.h"
#include "raylib.h"

Menu::Menu()
{
    status = true;
}

void Menu::draw()
{
    timer += GetFrameTime();

    DrawText(title_txt, (screenWidth / 2) - MeasureText(title_txt, title_txt_size) / 2, (screenHeight / 2) - 150, title_txt_size, RED);

    if (timer <= 1)
    {
        DrawText(start_text, (screenWidth / 2) - MeasureText(start_text, start_txt_size) / 2, (screenHeight / 2) - 70, start_txt_size, LIGHTGRAY);
    }

    DrawText(ctrl_txt, (screenWidth / 2) - MeasureText(ctrl_txt, ctrl_txt_size) / 2, screenHeight / 2, ctrl_txt_size, LIGHTGRAY);
    DrawText(mvmt_txt, (screenWidth / 2) - MeasureText(mvmt_txt, ctrl_txt_size) / 2, screenHeight / 2 + 30, ctrl_txt_size, LIGHTGRAY);
    DrawText(exit_txt, (screenWidth / 2) - MeasureText(exit_txt, ctrl_txt_size) / 2, screenHeight / 2 + 60, ctrl_txt_size, LIGHTGRAY);

    if (timer >= blinkInterval)
    {
        timer = 0.0f;
    }
}

void Menu::update()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        status = false;
    }
}