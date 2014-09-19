#include "button.h"

Button::Button(int x, int y, int w, int h)
{
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
}

void Button::handle_events(bool *win,Uint32 *score1,Uint32 *score2,bool *menuState,bool *gameState,Uint32 *firstTick)
{
    int x = 0 ;
    int y = 0 ;

    while( SDL_PollEvent(&event))
    {
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            x = event.button.x;
            y = event.button.y;

            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Reset the values of the match (win and scores) and return to the game state
                *win = false;
                *score1 = 0;
                *score2 = 0;
                *menuState = false;
                *gameState = true;
                *firstTick =0;

            }
        }
    }
    }
}

void Button::handle_events1(bool *gameState,bool *menuState)
{
    int x = 0 ;
    int y = 0 ;

    while( SDL_PollEvent(&event))
    {
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            x = event.button.x;
            y = event.button.y;

            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Do after button is pressed
                *gameState = true;
                *menuState = false;
            }
        }
    }
    }
}

void Button::show()
{
    apply_surface(box.x, box.y, button, screen);
}
void Button::show1()
{
    apply_surface(box.x, box.y, button2, screen);
}

