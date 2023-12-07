#ifndef OPPONENT_H
#define OPPONENT_H
#include "player.h"

class OPPONENT : public PLAYER
{
public:
    // METHODS
    OPPONENT();
    void update(int ball_x);
};

#endif