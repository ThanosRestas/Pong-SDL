#include "paddles.h"

Paddle::Paddle(int xUser , int yUser, SDLKey key1, SDLKey key2)
{
    x = xUser;
    y = yUser;
    yVelocity = 0;
    paddleUp = key1;
    paddleDown = key2;
}

void Paddle::handle_input()
{
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == paddleUp)
        {
            yVelocity -= SPEED;
        }
        else if(event.key.keysym.sym == paddleDown)
        {
            yVelocity += SPEED;
        }
    }
    else if(event.type == SDL_KEYUP)
    {
        if(event.key.keysym.sym == paddleUp)
        {
            yVelocity += SPEED;
        }
        else if(event.key.keysym.sym == paddleDown)
        {
            yVelocity -= SPEED;
        }
    }
}
void Paddle::move(Uint32 deltaTicks)
{
    y += yVelocity * ( deltaTicks / 1000.f );

    if( y  < 0 )
    {
        y =  0;
    }
    else if( y + PADDLE_HEIGHT > SCREEN_HEIGHT)
    {
        y = SCREEN_HEIGHT - PADDLE_HEIGHT;
    }
}

void Paddle::show()
{
    apply_surface( (int)x, (int)y, paddleSprite, screen );
}

