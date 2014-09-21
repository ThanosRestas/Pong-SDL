#ifndef BUTTON_H
#define BUTTON_H
#include "globals.h"

class Button
{
    private:
        SDL_Rect box;
    public:
        Button(int x,int y,int w, int h);
        void handle_events(bool *win,Uint32 *score1,Uint32 *score2,bool *menuState,bool *gameState,Uint32 *firstTick);
        void handle_events1(bool *gameState,bool *menuState);
        void show();
        void show1();
};

#endif // BUTTON_H
