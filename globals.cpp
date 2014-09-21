#include "globals.h"


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if(TTF_Init() == -1)
    {
        return false;
    }

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "SDL-Pong", NULL );

    //If everything initialized fine
    return true;
}

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

bool load_files()
{
    //Load the dot image
    paddleSprite = load_image( "assets/Paddle.bmp" );
    ball = load_image("assets/ball.bmp");
    font = TTF_OpenFont("assets/agentorange.ttf",30);
    collisionSound = Mix_LoadWAV("assets/bounce.wav");
    button = load_image("assets/playAgain.bmp");
    button2 = load_image("assets/play.bmp");


    if( paddleSprite == NULL )
    {
        return false;
    }

    if( ball == NULL )
    {
        return false;
    }

    if(font == NULL)
    {
        return false;
    }

    if(collisionSound == NULL)
    {
        return false;
    }

    if(button == NULL)
    {
        return false;
    }

    if(button2 == NULL)
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surface    
    SDL_FreeSurface( paddleSprite );
    SDL_FreeSurface( ball );
    SDL_FreeSurface(score1);
    SDL_FreeSurface(score2);
    Mix_FreeChunk(collisionSound);
    SDL_FreeSurface(winningMessage);
    SDL_FreeSurface(button);
    SDL_FreeSurface(button2);

    TTF_CloseFont(font);

    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

