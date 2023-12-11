#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    float x, y;
    float width, height;
    int speed, score;

    // METHODS
    Player();
    void draw();
    void update();
};

#endif