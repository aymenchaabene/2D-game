#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "menu.h"





void affichage_objet (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map)
{
      if(map->pos.x<=(mapw/2 +1000) && map->pos.x>=mapw/2)
                     {
                        SDL_BlitSurface(wood->img,NULL, screen, &(wood->pos)) ;
                        SDL_BlitSurface(boat->img,NULL, screen, &(boat->pos)) ;
                        SDL_Flip(screen) ;
                     }
}
void scrolling_droit (SDL_Surface *screen , Objet *map)
{
 if (map->pos.x<=mapw)
   map->pos.x+=100 ;

   SDL_BlitSurface(map->img,&(map->pos),screen, NULL);
   SDL_Flip(screen) ;
}
void scrolling_gauche (SDL_Surface *screen , Objet *map)
{
 if (map->pos.x>=0)
   map->pos.x-=100 ;
 SDL_BlitSurface(map->img,&(map->pos),screen, NULL); 
   SDL_Flip(screen) ;

}
void scrolling (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,int *running4  )
{
 SDL_Event event;

 SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                *running4 = 0;
            break;
            case SDL_KEYDOWN:

               switch(event.key.keysym.sym)

                  {

                     case SDLK_RIGHT: // Flèche droite
            	
                          scrolling_droit (screen ,map) ;
                          affichage_objet (screen,boat,wood,map)  ;

                          

                     break;

                     case SDLK_LEFT: // Flèche gauche
                          scrolling_gauche (screen ,map) ;
                          affichage_objet (screen,boat,wood,map)  ; 
                          

                     break;
              

                  }

            break;    
        }

}
