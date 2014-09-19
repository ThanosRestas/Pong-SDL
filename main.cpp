#include "ball.h"
#include "globals.h"
#include "paddles.h"
#include "button.h"
#include "timer.h"

/*Implement debug mode and pause*/

//An event structure
SDL_Event event;

//The font in use
TTF_Font *font;
SDL_Color textColor = { 255, 250, 250 };

//The collision sound
Mix_Chunk *collisionSound;

int main( int argc, char* args[] )
{
    bool quit = false;
    bool win = false;
    bool menuState = true;
    bool gameState = false;

    Uint32 firstTick = 0;
    LeftPaddle player1;
    RightPaddle player2;
    Timer delta;
    Ball ball;
    Button playButton(SCREEN_WIDTH/2-120, SCREEN_HEIGHT/2 + 200, 280 , 56);
    Button playStart(SCREEN_WIDTH/2-65 , SCREEN_HEIGHT/2, 130, 54);
    //std::stringstream Score1 ;
    //std::stringstream Score2 ;

    if( init() == false)
    {
        return 1;
    }

    if(load_files() == false)
    {
        return 1;
    }

    delta.start();

    while(quit == false )
    {

        if(menuState == true)
        {
                if(win == false)//Play button
                {

                    playStart.show1();
                    playStart.handle_events1(&gameState,&menuState);

                }
                else if(win == true)//Play again button
                {
                    playButton.show();
                    playButton.handle_events(&win,&ball.Player1Score,&ball.Player2Score,&menuState,&gameState,&firstTick);
                    delta.start();
                }

                if(event.type == SDL_QUIT)
                {
                    quit = true;
                }
        }

        if(gameState == true )
        {
            firstTick = SDL_GetTicks();

            while( SDL_PollEvent(&event))
            {
                player1.handle_left_input();
                player2.handle_right_input();

                if(event.type == SDL_QUIT)
                {
                    quit = true;
                }
            }

            player1.move(delta.get_ticks());
            player2.move(delta.get_ticks());

            if(firstTick >= 3000)
            {
               ball.move(player1.x,player1.y,player2.x,player2.y, delta.get_ticks());
            }

            delta.start();

            SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );

            if(ball.Player1Score == 0)
            {
                score1 = TTF_RenderText_Solid( font, "0", textColor );
            }
            else if( ball.Player1Score == 1)
            {
                SDL_FreeSurface(score1);
                score1 = TTF_RenderText_Solid( font, "1", textColor );
            }
            else if( ball.Player1Score == 2)
            {
                SDL_FreeSurface(score1);
                score1 = TTF_RenderText_Solid( font, "2", textColor );
            }
            else if( ball.Player1Score == 3)
            {
                SDL_FreeSurface(score1);
                score1 = TTF_RenderText_Solid( font, "3", textColor );
            }

            if(ball.Player2Score == 0)
            {
                score2 = TTF_RenderText_Solid( font, "0", textColor );
            }
            else if( ball.Player2Score == 1)
            {
                SDL_FreeSurface(score2);
                score2 = TTF_RenderText_Solid( font, "1", textColor );
            }
            else if( ball.Player2Score == 2)
            {
                SDL_FreeSurface(score2);
                score2 = TTF_RenderText_Solid( font, "2", textColor );
            }
            else if( ball.Player2Score == 3)
            {
                SDL_FreeSurface(score2);
                score2 = TTF_RenderText_Solid( font, "3", textColor );
            }

            if(ball.Player1Score == 3)
            {
                win = true;
                winningMessage = TTF_RenderText_Solid( font, "Player 1 wins !", textColor );

            }
            else if(ball.Player2Score == 3)
            {
                win = true;
                winningMessage = TTF_RenderText_Solid( font, "Player 2 wins !", textColor );
            }

            apply_surface(SCREEN_WIDTH/2 - 100, 10, score1, screen );
            apply_surface(SCREEN_WIDTH/2 + 100, 10, score2, screen );


            if( win == false)
            {
                player1.show();
                player2.show();
                ball.show();
            }
            else if(win == true)
            {
                apply_surface(SCREEN_WIDTH/2-150, SCREEN_HEIGHT/2, winningMessage, screen );
                gameState = false;
                menuState = true;//Return to the menu if a match is won
            }
        }

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }

    clean_up();

    return 0;
}











