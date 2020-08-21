#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "menu.h"

int Collision_Parfaite(SDL_Surface *Background,Coordinate C)
{
 int collision=0;
 SDL_Color color ;


 SDL_GetRGB(getpixel(Background,C),Background->format,&color.r,&color.g,&color.b);

 if (color.r==0 && color.g==0 && color.b==0)
 {collision=1;}

 return collision;

}
Uint32 getpixel(SDL_Surface *surface,Coordinate C)
{
    int bpp = surface->format->BytesPerPixel;
   
    Uint8 *p = (Uint8 *)surface->pixels + C.Y * surface->pitch + C.X * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;      
    }
}

int collisionBB(Objet perso [],Objet ennemi [])
{
  //|| perso[0].pos.y+perso[0].img->h <ennemi[0].pos.y || perso[0].pos.y > ennemi[0].pos.y+ennemi[0].img->h 
 if(perso[0].pos.x+perso[0].img->w <ennemi[0].pos.x-100 || perso[0].pos.x -100> ennemi[0].pos.x+ennemi[0].img->w   )
   return 0 ;
 else 
 return 1   ;
}

void calculer_centre_rayon (Objet *perso,Objet tab [])
{

 perso->c.x=perso->pos.x+ (perso->img->w)/2 ;
 perso->c.y=perso->pos.y+ (perso->img->h)/2 ;
 perso->c.rayon=sqrt( pow( (perso->img->w)/2 , 2) + pow( (perso->img->h)/2 , 2) ) ;
 /*  pour le circle inscrit :
 if(width<height)
 {
 perso->c.rayon= (perso->img->w)/2 ;
 tab [0]->c.rayon= (tab [0]->img->w)/2 ;
 }
 else 
 {
 perso->c.rayon= (perso->img->h)/2 ;
 tab [0]->c.rayon= (tab [0]->img->h)/2 ;
 } */
 tab[0].c.x=tab [0].pos.x+ (tab [0].img->w)/2 ;
 tab[0].c.y=tab [0].pos.y+ (tab [0].img->h)/2 ;
 tab[0].c.rayon=sqrt( pow( (tab [0].img->w)/2 , 2) + pow( (tab [0].img->h)/2 , 2) ) ;
}
float calculer_distance (Objet *perso,Objet tab []) 
{
  float D ;

  D=sqrt( pow( (perso->c.x) - (tab [0].c.x) ,2 ) + pow ( (perso->c.y) - (tab [0].c.y) , 2  ) ) ;

  return D ;

}

int verif_collision ( Objet *perso,Objet tab [],float D1 )
{
  float D2 ;
  int collision=0 ;

  D2=perso->c.rayon + tab [0].c.rayon ;

  if(D1<=(D2-180) )
    collision= 1 ;
  
  return collision ;
}

float deplacement_objet(Objet tab[],Objet *map,Objet *wood,int *running,float *curseur_perso,int *right,int *left,int *saut,Objet ennemi [],Objet *mask)
{
  SDL_Event event ;
 *left=0 ;
 *right=0;
 int up=0 ;

  SDL_PollEvent(&event);
     switch(event.type)
      {
         case SDL_QUIT:
              *running=0;
         break;
         case SDL_KEYDOWN:
              
              switch(event.key.keysym.sym)
               {
                    case SDLK_UP :
                    up=1 ;
              	if(tab[0].jump ==0 && tab[0].pos.y==768-249)
						{
							tab[0].vy = -7;
						  tab[0].jump = 1 ;
						} 
/* 						else if(tab[0].jump ==1)
					{
						tab[0].vy = -7;
						tab[0].jump =0 ;
					} */
                    break ;                 
                 case SDLK_ESCAPE:
                     *running=0 ;
                  break ;
                case SDLK_RIGHT:
                *right=1 ; 

                 if((tab[0].pos.y==768-249) || (tab[0].pos.y!=768-249 && tab[0].vx >= 0))
					        tab[0].vx = 5;                    
                
                  if(*curseur_perso >= 6.9)
                     *curseur_perso = 1;
                   (*curseur_perso)+=0.5 ;   
                    
                 
                break;
                case SDLK_LEFT:
                 *left=1;
                  if((tab[0].pos.y==768-249) || (tab[0].pos.y!=768-249 && tab[0].vx <= 0))
					        tab[0].vx = -5;   
                   if(*curseur_perso >= 6.9)
                     *curseur_perso = 1;
                    
                    
                   (*curseur_perso) +=0.5 ; 
                 
                break;
               }
          break ;
            case SDL_KEYUP :
                    if(event.key.keysym.sym==SDLK_LSHIFT)
                    //(*enablefast)=0 ;
					if(event.key.keysym.sym==SDLK_RIGHT)
					{
					if(tab[0].pos.y==768-249)
					{
					  if(tab[0].vx > 0)
				        tab[0].vx = 0;
					
				  }
          else
					{
						
						tab[0].stop=1;
					}

				  }
				    
				   
				      
					if(event.key.keysym.sym==SDLK_LEFT)
				    {
					if(tab[0].pos.y==768-249)
					{
					  if(tab[0].vx < 0)
				        tab[0].vx = 0;
					
				  }
          	else
					{
						
						tab[0].stop=1;
					}
            }
            break ;          
               case SDL_MOUSEBUTTONDOWN:
             if(event.button.button==(SDL_BUTTON_LEFT ||SDL_BUTTON_RIGHT))
              {
                if(event.button.x<(1368/2))
                  {
                    *left=1;
                    if(*curseur_perso >= 6.9)
                     *curseur_perso = 1;

                      tab[0].pos.x-= 7 ;
                    
                          
                 
                  (*curseur_perso) +=0.5 ;
                  }
               if(event.button.x>=(1368/2)) 
             {
                *right=1 ;
              if(*curseur_perso >= 6.9)
                *curseur_perso = 1;
                 tab[0].pos.x+= 7 ;
              
               (*curseur_perso) +=0.5 ;
                       
                          
               
             }
              }  

            break ;
      }
if((tab[0].pos.y!=768-249) && ( tab[0].jump == 1) && up==1 )
				    {
						
				    tab[0].vy = -7;
						tab[0].jump=0;
            up=0 ;
				    }  
           else if ((tab[0].pos.y==768-249) &&  ( tab[0].jump == 1) && up!=1 )
          {
          tab[0].jump =0 ;
          }   
           if(tab[0].stop==1 && tab[0].pos.y==768-249)
				    {
						
				    tab[0].vx = 0;
						tab[0].stop=0;
				    }             
  if( tab[0].vx>0)  
  { 
                     if(tab[0].pos.x< (1368 -tab[0].img->w))
                    {  
                     tab[0].pos.x+=5;
                    }


  }
  				    if(tab[0].pos.y==768-249)
				         tab[0].jump=0;
 
   if(tab[0].vx<0)   
  {
tab[0].pos.x-=5;
  }
  	tab[0].vy += 0.2;
	tab[0].pos.y +=(int)tab[0].vy;
		
	if(tab[0].pos.y + 249 > 768){
		tab[0].pos.y =768-249;
		tab[0].vy = 0;
	}



  return (*curseur_perso) ;   
}
