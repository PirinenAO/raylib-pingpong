#ifndef MENU_H
#define MENU_H
#include "constants.h"

class Menu
{
    const int title_txt_size = 60;
    const int start_txt_size = 40;
    const int ctrl_txt_size = 20;
    const char *title_txt = "PING PONG";
    const char *start_text = "PRESS SPACE TO START";
    const char *ctrl_txt = "CONTROLS:";
    const char *mvmt_txt = "A and B to move";
    const char *exit_txt = "ESC to exit";
    float timer = 0.0;
    float blinkInterval = 2.0;

public:
    bool status;

    Menu();
    void draw();
    void update();
};

#endif