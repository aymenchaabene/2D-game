#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"


int main()
{
SDL_Surface *screen = NULL ;
Objet map,wood,boat ;
int running=1 ;

 screen= SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

  
  initialiser (&map ,&wood ,&boat ) ;
  setup (screen,&map ,&wood,&boat) ;

  SDL_EnableKeyRepeat(10, 10);
  while(running){
      evenement (screen ,&boat ,&wood,&map,&running  ) ;
     }
    free_memory (&boat ,&wood,&map) ;

    

    return EXIT_SUCCESS;
}
