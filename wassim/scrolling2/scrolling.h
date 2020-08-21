#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define w 1360
#define h 760

void initialiser (SDL_Rect *positionFond,SDL_Rect *positioncir,SDL_Surface *imageDeFond ,SDL_Surface *circle )
void afficher (SDL_Rect *positionFond,SDL_Rect *positioncir,SDL_Surface *imageDeFond ,SDL_Surface *circle,SDL_Surface *ecran) ;
void scrolling_map ();