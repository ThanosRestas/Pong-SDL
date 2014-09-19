#ifndef BALL_H
#define BALL_H
#include "globals.h"

class Ball
{
    private:
        float xVelocity,yVelocity;
        float x,y;

    public:
        Uint32 Player1Score ;
        Uint32 Player2Score ;
        Ball();
        void move(float xLeftPaddle, float yLeftPaddle,float xRightPaddle, float yRightPaddle, Uint32 deltaticks);
        void show();
};

#endif // BALL_H
