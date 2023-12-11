#ifndef OPPONENT_H
#define OPPONENT_H
#include "player.h"

class Opponent : public Player
{
public:
    // METHODS
    Opponent();
    void update(int ball_x);
};

#endif