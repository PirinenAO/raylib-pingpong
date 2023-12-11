#ifndef MENU_H
#define MENU_H
#include "constants.h"

class Menu
{
public:
    bool status;
    const int start_txt_size = 40;
    const int ctrl_txt_size = 20;
    const char *start_text = "PRESS SPACE TO START";
    const char *ctrl_txt = "CONTROLS:";
    const char *mvmt_txt = "A and B to move";
    const char *exit_txt = "ESC to exit";
    Menu()
    {
        status = true;
    }

    void draw()
    {
        DrawText(start_text, (screenWidth / 2) - MeasureText(start_text, start_txt_size) / 2, (screenHeight / 2) - 100, start_txt_size, LIGHTGRAY);
        DrawText(ctrl_txt, (screenWidth / 2) - MeasureText(ctrl_txt, ctrl_txt_size) / 2, screenHeight / 2, ctrl_txt_size, LIGHTGRAY);
        DrawText(mvmt_txt, (screenWidth / 2) - MeasureText(mvmt_txt, ctrl_txt_size) / 2, screenHeight / 2 + 30, ctrl_txt_size, LIGHTGRAY);
        DrawText(exit_txt, (screenWidth / 2) - MeasureText(exit_txt, ctrl_txt_size) / 2, screenHeight / 2 + 60, ctrl_txt_size, LIGHTGRAY);
    }

    void update()
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            status = false;
        }
    }
};

#endif