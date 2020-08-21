#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"game.h"

#define W_Screen 800
#define H_Screen 600


#define SPEED 5


#define SPRITE_H 148
#define SPRITE_W 102
#define MAX_FRAMES 6 



                     #define W_BackgImg 259
                     #define H_BackgImg 194
/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for annimation enemi
*
*/



int main(int argc, char** argv)//ces deux variables sont utulisés pour récupérer des arguments pour lancer l'exécutable
{
    SDL_Surface* screen = NULL;

	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
	screen = SDL_SetVideoMode(W_Screen, H_Screen, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE | SDL_RESIZABLE );//SDL_HWPALETTE:Mise a jour de la surface

	enemy enemy;
    
    SDL_Surface* backg = NULL;
    backg = IMG_Load("index.jpeg");
    SDL_BlitSurface(backg, NULL, screen, NULL);
       SDL_WM_SetCaption("animation enemy", NULL);
    SDL_Flip(screen);

	enemy.spriteleft = IMG_Load("walk-left.png");
	enemy.spriteright = IMG_Load("walk-right.png");
	enemy.dst.x =300 ;
	enemy.dst.y =418;

	//Hide Cursor
	SDL_ShowCursor(SDL_DISABLE);

	int continuer = 1;
	while(continuer)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		int i;

		for(i = 0; i<MAX_FRAMES; i++)
		{
			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
                        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0)) ;
                         
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteright, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(100);
		}
		for(i = (MAX_FRAMES - 1); i>=0; i--)
		{
			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
                        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0)) ;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteleft, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(100);
		}

		switch(event.type)

		{            case SDL_QUIT:
                               continuer = 0;
                               break;
			case SDL_KEYDOWN:
			    if(event.key.keysym.sym == SDLK_ESCAPE)
			    {
			    	continuer = 0;
			    }
                       


		}

	}
	SDL_Quit();
return 0;
}
