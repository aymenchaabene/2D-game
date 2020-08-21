#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include "collision.h"

#define width 1360 
#define height 760

int main()
{
  SDL_Surface *screen=NULL ;
  int running=1,collision ;
  float D ;

  Objet objet1,objet2 ;

   SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    init (&objet1,&objet2) ;
    setup (screen,&objet1,&objet2) ;
    
    SDL_EnableKeyRepeat(10, 10);

    while(running){
     deplacement_objet(&objet1,&running) ;
     calculer_centre_rayon (&objet1,&objet2) ;
     D=calculer_distance (&objet1,&objet2) ;
     collision=verif_collision (&objet1,&objet2,D ) ;
     if(collision)
     {
       SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,255,255)) ;
       SDL_BlitSurface(objet1.img,NULL,screen,&(objet1.pos)) ;
       SDL_BlitSurface(objet2.img,NULL,screen,&(objet2.pos)) ;
       SDL_Flip(screen);
     }
     else
     {
       update (screen,&objet1,&objet2) ;
     }
     


    }
    liberate_memory (&objet1,&objet2) ;




    return EXIT_SUCCESS;
}



