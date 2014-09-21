#include "ball.h"

SDL_Surface *paddleSprite = NULL ;
SDL_Surface *leftPaddle = NULL ;
SDL_Surface *ball = NULL ;
SDL_Surface *screen = NULL ;
SDL_Surface *button = NULL ;
SDL_Surface *button2 = NULL ;

SDL_Surface *score1 = NULL ;
SDL_Surface *score2 = NULL;
SDL_Surface *winningMessage = NULL ;


Ball::Ball()
{
    x = SCREEN_WIDTH/2;
    y = SCREEN_HEIGHT/2;
    xVelocity = 300;
    yVelocity = 150;
    Player1Score = 0;
    Player2Score = 0;
}

void Ball::move(float xLeftPaddle, float yLeftPaddle,float xpaddleSprite, float ypaddleSprite, Uint32 deltaTicks)
{
    y +=  yVelocity * ( deltaTicks / 1000.f );
    x +=  xVelocity * ( deltaTicks / 1000.f );

    if( y + BALL_HEIGHT > SCREEN_HEIGHT )//Bottom wall
    {
        Mix_PlayChannel(-1,collisionSound, 0);
        x = x-1;
        y = y-1;
        yVelocity = -yVelocity;

    }
    else if( y < 0 )//Top wall
    {
        Mix_PlayChannel(-1,collisionSound, 0);
        x = x+1;
        y = y+1;
        yVelocity = -yVelocity ;
    }
    else if(x + BALL_WIDTH >= xpaddleSprite && y <= ypaddleSprite + PADDLE_HEIGHT && y >=ypaddleSprite && x < xpaddleSprite + PADDLE_WIDTH  )//Right Paddle collision
    {

        x = x-1;
        y = y-1;
        xVelocity = -xVelocity;

        Mix_PlayChannel(-1,collisionSound, 0);

        if( y + BALL_WIDTH < ypaddleSprite + (PADDLE_HEIGHT)/2 && yVelocity > 0)
        {
            yVelocity = -yVelocity;
        }

        if( y  + BALL_WIDTH >= ypaddleSprite + (PADDLE_HEIGHT)/2 && yVelocity < 0)
        {
            yVelocity = -yVelocity;
        }

    }
    else if( x <= xLeftPaddle + PADDLE_WIDTH && y <= yLeftPaddle + PADDLE_HEIGHT && y >= yLeftPaddle && x > xLeftPaddle )//Left Paddle collision
    {
        x = x + 1;
        y = y + 1;

        Mix_PlayChannel(-1,collisionSound, 0);

        xVelocity = -xVelocity;

        if( y < yLeftPaddle + (PADDLE_HEIGHT)/2 && yVelocity > 0)
        {
            yVelocity = -yVelocity;
        }

        if( y >= yLeftPaddle + (PADDLE_HEIGHT)/2 && yVelocity < 0)
        {
            yVelocity = -yVelocity;
        }
    }
    else if(x < 0 )//Reset position if out of bounds
    {
        Player2Score++;

        x = SCREEN_WIDTH/2;
        y = SCREEN_HEIGHT/2;
    }
    else if(x > SCREEN_WIDTH)
    {
        Player1Score++;

        x = SCREEN_WIDTH/2;
        y = SCREEN_HEIGHT/2;
    }
}

void Ball::show()
{
    apply_surface( (int)x, (int)y, ball, screen );
}
