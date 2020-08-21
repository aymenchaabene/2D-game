#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"

void initialiser (Objet *map ,Objet *wood ,Objet *boat ) 
{
  SDL_WM_SetCaption("scrolling", NULL);

  map->img=IMG_Load("map.png") ;
  map->pos.x=0 ;
  map->pos.y=0 ;
  
  wood->img=IMG_Load("wood.png") ;
  wood->pos.x=xwood ;
  wood->pos.y=ywood ;

  boat->img=IMG_Load("boatt.png") ;
  boat->pos.x=xboat ;
  boat->pos.y=yboat ;
  

}
void setup (SDL_Surface *screen, Objet *map ,Objet *wood, Objet *boat)
{
  SDL_BlitSurface(map->img,NULL,screen, &(map->pos));
  SDL_BlitSurface(wood->img,NULL, screen, &(wood->pos)) ;
  SDL_BlitSurface(boat->img,NULL, screen, &(boat->pos)) ;
  SDL_Flip(screen) ;
}

void affichage_objet (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map)
{
      if(map->pos.x<=(mapw/2 +1000) && map->pos.x>=mapw/2)
                     {
                        SDL_BlitSurface(wood->img,NULL, screen, &(wood->pos)) ;
                        SDL_BlitSurface(boat->img,NULL, screen, &(boat->pos)) ;
                        
                     }
}
void scrolling_droit (SDL_Surface *screen , Objet *map)
{
 if (map->pos.x<=mapw)
   map->pos.x+=20 ;

   SDL_BlitSurface(map->img,&(map->pos),screen, NULL);
}
void scrolling_gauche (SDL_Surface*screen , Objet *map)
{
 if (map->pos.x>=0)
   map->pos.x-=20 ;
 SDL_BlitSurface(map->img,&(map->pos),screen, NULL);  
}

void evenement (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,int *running  )
{
 SDL_Event event;

 SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                *running = 0;
            break;
            case SDL_KEYDOWN:

               switch(event.key.keysym.sym)

                  {

                     case SDLK_RIGHT: // Flèche droite
            	
                          scrolling_droit (screen ,map) ;
                          affichage_objet (screen,boat,wood,map)  ;

                          SDL_Flip(screen);

                     break;

                     case SDLK_LEFT: // Flèche gauche
                          scrolling_gauche (screen ,map) ;
                          affichage_objet (screen,boat,wood,map)  ; 
                 
                          SDL_Flip(screen);

                     break;
              

                  }

            break;    
        }

}

void free_memory (Objet *boat ,Objet *wood,Objet *map)
{
 SDL_FreeSurface (boat->img) ;
 SDL_FreeSurface (wood->img) ;
 SDL_FreeSurface (map->img) ;

 SDL_Quit () ;

}