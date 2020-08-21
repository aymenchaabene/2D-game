
/**  * @file scrolling.c 
*/ 

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
/**  
* @brief  To initialize the background b .  
* @param b the background  
* @param url  the url of the image   
* @return Nothing  
*/ 
void initialiser (Objet *map ,Objet *wood ,Objet *boat,Objet *perso ) 
{
  SDL_WM_SetCaption("scrolling", NULL);

  map->img=IMG_Load("map.png") ;
  map->pos.x=0 ;
  map->pos.y=0 ;
  
  wood->img=IMG_Load("2.png") ;
  wood->pos.x=xwood ;
  wood->pos.y=ywood ;

  boat->img=IMG_Load("1.png") ;
  boat->pos.x=xboat ;
  boat->pos.y=yboat ;

 

  

}
/**  
* @brief  To setup objects .  
* @param scren the screen  
* @param b  the background  
* @return Nothing  
*/ 
void setup (SDL_Surface *screen, Objet *map ,Objet *wood, Objet *boat,Objet *perso)
{
  SDL_BlitSurface(map->img,NULL,screen, &(map->pos));
  SDL_BlitSurface(wood->img,NULL, screen, &(wood->pos)) ;
  
  

  SDL_Flip(screen) ;
}
/**  
* @brief  To show the object to the left .  
* @param b  the background  
* @return Nothing  
*/ 
void affichage_objet (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,Objet *perso)
{
           
        
     if(map->pos.x>=mapw-1390)                
       SDL_BlitSurface(boat->img,NULL, screen, &(boat->pos)) ;   
       else 
       SDL_BlitSurface(wood->img,NULL, screen, &(wood->pos)) ;
}
/**  
* @brief  To scroll the background to the right .  
* @param b  the background  
* @return Nothing  
*/ 
void scrolling_droit (SDL_Surface *screen , Objet *map)
{
 if (map->pos.x<=mapw-1368)
     map->pos.x+=20 ;
     

   SDL_BlitSurface(map->img,&(map->pos),screen, NULL);
}
/**  
* @brief  To scroll the background to the left .  
* @param b  the background  
* @return Nothing  
*/ 
void scrolling_gauche (SDL_Surface*screen , Objet *map)
{
 if (map->pos.x>=0)
   map->pos.x-=20 ;
 SDL_BlitSurface(map->img,&(map->pos),screen, NULL);  
}
/**  
* @brief to show the event .  
* @param b  the background  
* @return Nothing  
*/ 
void evenement (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,int *running ,Objet *perso )
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
                          affichage_objet (screen,boat,wood,map,perso)  ;

                          SDL_Flip(screen);

                     break;

                     case SDLK_LEFT: // Flèche gauche
                          scrolling_gauche (screen ,map) ;
                          affichage_objet (screen,boat,wood,map,perso)  ; 
                 
                          SDL_Flip(screen);

                     break;
              

                  }

            break;    
        }

}
/**  
* @brief  To free the memory .  
* @param b  the background  
* @return Nothing  
*/ 

void free_memory (Objet *boat ,Objet *wood,Objet *map)
{
 SDL_FreeSurface (boat->img) ;
 SDL_FreeSurface (wood->img) ;
 SDL_FreeSurface (map->img) ;

 SDL_Quit () ;

}
