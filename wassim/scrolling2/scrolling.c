#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"

void initialiser (SDL_Rect *positionFond,SDL_Rect *positioncir,SDL_Surface *imageDeFond ,SDL_Surface *circle ) 
{
  positionFond->x=0 ;
  positionFond->y=0 ;
  positioncir->x = 1920/ 2 - 100 / 2;
  positioncir->y = 1080;
   SDL_WM_SetCaption("scrolling", NULL);
    
        
    imageDeFond = IMG_Load("map.jpg");
    circle = IMG_Load("carreau.png");

}
void afficher (SDL_Rect *positionFond,SDL_Rect *positioncir,SDL_Surface *imageDeFond ,SDL_Surface *circle,SDL_Surface *ecran)
{
               SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                SDL_BlitSurface(circle,NULL, ecran, &positioncir) ;
                SDL_Flip(ecran) ;
}

void scrolling_map ()
{
 
   
}