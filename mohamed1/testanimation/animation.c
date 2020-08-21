#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation.h"


void initialiser (Objet tab []) 
{
  int i ; 
  char image [20] ;
  for (i=0;i<6;i++)
  {
   sprintf(image,"%dwalk.png",i+1)  ;
   tab[i].img=IMG_Load(image) ;
   tab[i].pos.x=0 ;
   tab[i].pos.y=0 ;
  }

}
void deplacement_objet(SDL_Surface *screen , Objet tab [],int *running)
{
  SDL_Event event ;
  int i=0 ;

 
 SDL_WaitEvent(&event);
     switch(event.type)
      {
         case SDL_QUIT:
              *running=0;
         break;
         case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
               {
                case SDLK_RIGHT:
                    i++ ;
                    
                    if (i==6)
                    i=1 ;

                    SDL_BlitSurface (screen,NULL,tab[i].img,&(tab[i].pos)) ;

                break;
                case SDLK_LEFT:
                    i-- ;
                    if (i==0)
                    i=5 ;

                    SDL_BlitSurface (screen,NULL,tab[i].img,&(tab[i].pos)) ;
                break;
               }
      }
  }