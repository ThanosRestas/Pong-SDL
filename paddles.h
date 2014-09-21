#ifndef PADDLES_H
#define PADDLES_H
#include "globals.h"

class Paddle
{
    private:
        float yVelocity;
    public:
        float x,y;
        SDLKey paddleUp;
        SDLKey paddleDown;
        Paddle(int xUser , int yUser, SDLKey key1, SDLKey key2);
        void handle_input();
        void move(Uint32 deltaTicks);
        void show();
};

#endif // PADDLES_H
