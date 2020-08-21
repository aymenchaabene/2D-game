



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "entite.h"

int main()
{
ent E;

   SDL_Surface* screen = NULL;

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
    screen = SDL_SetVideoMode(W_Screen, H_Screen, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE | SDL_RESIZABLE );//SDL_HWPALETTE:Mise a jour de la surface

	
    
    SDL_Surface* backg = NULL;
    backg = IMG_Load("index.jpeg");
    SDL_BlitSurface(backg, NULL, screen, NULL);
    SDL_WM_SetCaption("animation enemy", NULL);
    SDL_Flip(screen);


//E=animation_entite(E,screen,backg);
deplacement_aleatoire_animation(E,screen,backg);

}
