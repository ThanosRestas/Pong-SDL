#ifndef GLOBALS_H
#define GLOBALS_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>

//Screen attributes
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;

//The dimensions of objects
const int PADDLE_WIDTH = 16;
const int PADDLE_HEIGHT = 100;
const int BALL_WIDTH = 18;
const int BALL_HEIGHT =18;
const int SPEED = 1000;

//The surfaces
extern SDL_Surface *paddleSprite ;
extern SDL_Surface *ball ;
extern SDL_Surface *screen ;
extern SDL_Surface *button ;
extern SDL_Surface *button2 ;

extern SDL_Surface *score1 ;
extern SDL_Surface *score2;
extern SDL_Surface *winningMessage ;

//The event structure
extern SDL_Event event;

//The font in use
extern TTF_Font *font;
extern SDL_Color textColor;

//The collision sound
extern Mix_Chunk *collisionSound;

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );
bool init();
SDL_Surface *load_image( std::string filename );
bool load_files();

void clean_up();


#endif // GLOBALS_H
