#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "menu.h"








void calculer_centre_rayon (Objet *objet1,Objet *objet2)
{

 objet1->c.x=objet1->pos.x+ (objet1->img->w)/2 ;
 objet1->c.y=objet1->pos.y+ (objet1->img->h)/2 ;
 objet1->c.rayon=sqrt( pow( (objet1->img->w)/2 , 2) + pow( (objet1->img->h)/2 , 2) ) ;
/*  pour le circle inscrit :
 if(width<height)
 {
 objet1->c.rayon= (objet1->img->w)/2 ;
 objet2->c.rayon= (objet2->img->w)/2 ;
 }
 else 
 {
 objet1->c.rayon= (objet1->img->h)/2 ;
 objet2->c.rayon= (objet2->img->h)/2 ;
 } */
 objet2->c.x=objet2->pos.x+ (objet2->img->w)/2 ;
 objet2->c.y=objet2->pos.y+ (objet2->img->h)/2 ;
 objet2->c.rayon=sqrt( pow( (objet2->img->w)/2 , 2) + pow( (objet2->img->h)/2 , 2) ) ;

}

float calculer_distance (Objet *objet1,Objet *objet2) 
{
  float D ;

  D=sqrt( pow( (objet1->c.x) - (objet2->c.x) ,2 ) + pow ( (objet1->c.y) - (objet2->c.y) , 2  ) ) ;

  return D ;
}

int verif_collision ( Objet *objet1,Objet *objet2,float D1 )
{
  float D2 ;
  int collision=0 ;

  D2=objet1->c.rayon + objet2->c.rayon ;

  if(D1<=D2)
    collision= 1 ;
  
  return collision ;
}

void deplacement_objet(Objet *objet,Objet *map,Objet *wood,int *running)
{
  SDL_Event event ;


 
 SDL_WaitEvent(&event);
     switch(event.type)
      {
         case SDL_QUIT:
              *running=0;
         break;
         case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
               {
                case SDLK_DOWN:
                    objet->pos.y+=2;

                break;
                case SDLK_UP:
                    objet->pos.y-=2;
                break;
                case SDLK_RIGHT:
                if(map->pos.x<=mapw-1360)
                 {
                    map->pos.x+=15 ;
                    objet->pos.x+=2;
                    wood->pos.x-=2;
                    
                 }
                break;
                case SDLK_LEFT:
                  if(map->pos.x>=0)
                 {
                    map->pos.x-=15 ;
                    objet->pos.x-=2;
                    wood->pos.x+=2;
                    
                 }
                break;
               }
      }
  }
