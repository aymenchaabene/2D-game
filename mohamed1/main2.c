#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
/**
* @file main2.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/


int main()
{
SDL_Surface *screen = NULL ;
Objet map,wood,boat,perso ;
int running=1 ;

 screen= SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

  
  initialiser (&map ,&wood ,&boat,&perso ) ;
  setup (screen,&map ,&wood,&boat,&perso) ;

  SDL_EnableKeyRepeat(10, 10);
  while(running){
      evenement (screen ,&boat ,&wood,&map,&running,&perso  ) ;
     }
    free_memory (&boat ,&wood,&map) ;

    

    return EXIT_SUCCESS;
}
