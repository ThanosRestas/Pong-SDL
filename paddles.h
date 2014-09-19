#ifndef PADDLES_H
#define PADDLES_H
#include "globals.h"

class RightPaddle
{
    private:

        float yVelocity;
    public:
        float x,y;
        RightPaddle();
        void handle_right_input();
        void move(Uint32 deltaTicks);
        void show();
};

class LeftPaddle
{
    private:

        float yVelocity;
    public:
        float x,y;
        LeftPaddle();
        void handle_left_input();
        void move(Uint32 deltaTicks);
        void show();
};



#endif // PADDLES_H
