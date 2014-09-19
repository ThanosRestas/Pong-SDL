#include "paddles.h"




RightPaddle::RightPaddle()
{
    x = 900;
    y = SCREEN_HEIGHT;
    yVelocity = 0;
}

void RightPaddle::handle_right_input()
{

    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: yVelocity -= SPEED  ; break;
            case SDLK_DOWN: yVelocity += SPEED ; break;
        }
    }
    else if(event.type == SDL_KEYUP)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: yVelocity += SPEED; break;
            case SDLK_DOWN: yVelocity -= SPEED ;break;
        }
    }
}

void RightPaddle::move(Uint32 deltaTicks)
{
    y += yVelocity  * ( deltaTicks / 1000.f ) ;

    if( y  < 0 )
    {
        y =  0;

    }
    else if( y + PADDLE_HEIGHT > SCREEN_HEIGHT)
    {
        y = SCREEN_HEIGHT - PADDLE_HEIGHT;
    }
}

void RightPaddle::show()
{
    apply_surface( (int)x, (int)y, rightPaddle, screen );
}

LeftPaddle::LeftPaddle()
{
    x = 100;
    y = 0;
    yVelocity = 0;
}

void LeftPaddle::handle_left_input()
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_w: yVelocity -= SPEED  ; break;
            case SDLK_s: yVelocity += SPEED  ; break;
        }
    }
    else if(event.type == SDL_KEYUP)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_w: yVelocity += SPEED ; break;
            case SDLK_s: yVelocity -= SPEED ; break;
        }
    }
}

void LeftPaddle::move(Uint32 deltaTicks)
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

void LeftPaddle::show()
{
    apply_surface( (int)x, (int)y, leftPaddle, screen );
}
