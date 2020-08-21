#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "menu.h"
#include "time.h"

void gestion_vie(Objet vie [],int *valeur_vie,Objet tabD [])
{
  if(*valeur_vie<4)
  (*valeur_vie)++ ;

  //tabD[0].pos.x+=40;
  
}
void affiche_vie(SDL_Surface *screen , Objet vie [] ,int valeur_vie)
{
  if(valeur_vie<4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[0].pos)) ;
  SDL_Flip(screen) ;
  }
  if(valeur_vie==4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[4].pos)) ;
  SDL_Flip(screen) ;
  }

}
void deplacement_ennemi(Objet ennemi [],float *compteur,int *right_ennemi,int *left_ennemi)
{
 int s ;
 srand(time(NULL)) ;

 if(*compteur<4)
 {
  (*compteur)+=0.2 ; 
  if((*right_ennemi)==1)
  {
   if(ennemi[0].pos.x>=(width-200)) 
   {
    *left_ennemi=1 ;
    *right_ennemi=0 ;
    
   }
   else
    ennemi[0].pos.x+=2 ; 
  }
  if((*left_ennemi)==1)
  {
   if(ennemi[0].pos.x<=200) 
   {
    *left_ennemi=0 ;
    *right_ennemi=1 ;
   }
   else
   ennemi[0].pos.x-=2 ;  
  }
 
 }
 if(*compteur>=4)
 {
   *left_ennemi=0 ;
   *right_ennemi=0 ;
   *compteur=0 ;
    s=rand() ;
  if(s%2==0)
  {
   *right_ennemi=1 ;  
  }
    if(s%2==1)
  {
   *left_ennemi=1 ;  
  }
 }
 
   
}
void renderD (SDL_Surface *screen, Objet *map ,Objet *box, Objet tabD [],float curseur_perso,Objet ennemi [],float compteur,int right_ennemi,int left_ennemi,Objet ennemiD [],Objet vie [] ,int valeur_vie,SDL_Surface *texte ,SDL_Rect position,SDL_Surface *gestion_score ,SDL_Rect position2,Objet *mask,SDL_Rect pos )
{ 
  
   SDL_BlitSurface(map->img,(&(map)->pos),screen,NULL) ;
  
   
  
  
  if(tabD[0].pos.x>= (1368 -tabD[0].img->w))
  SDL_BlitSurface(tabD[0].img,NULL,screen,&(tabD[0].pos)); 
  else
  SDL_BlitSurface(tabD[(int)curseur_perso].img,NULL,screen,&(tabD[0].pos)); 
  if(box)
  {
   if(box->pos.x>=0)
  SDL_BlitSurface(box->img,NULL,screen,&(box->pos)) ;
  }
  if(ennemi[0].pos.x>=0)
  {
     if(left_ennemi) 
     {
      if(curseur_perso>=5.4)
     SDL_BlitSurface(ennemi[5].img,NULL,screen,&(ennemi[0].pos)); 
     else 
     SDL_BlitSurface(ennemi[(int)compteur].img,NULL,screen,&(ennemi[0].pos)) ;
     }
     if(right_ennemi) 
     {
            if(curseur_perso>=5.4)
     SDL_BlitSurface(ennemiD[5].img,NULL,screen,&(ennemi[0].pos)); 
     else 
     SDL_BlitSurface(ennemiD[(int)compteur].img,NULL,screen,&(ennemi[0].pos)) ; 
     }
  }
    if(valeur_vie<4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[0].pos)) ;
  
  }
  if(valeur_vie==4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[4].pos)) ;
  
  }
  SDL_BlitSurface(texte, NULL, screen, &position); 
  SDL_BlitSurface(gestion_score, NULL, screen, &position2); 

            

  SDL_Flip(screen) ;
}
void renderG (SDL_Surface *screen, Objet *map ,Objet *box, Objet tabD [],Objet tabG [],float *curseur_perso,Objet ennemi [],float compteur,int right_ennemi,int left_ennemi,Objet ennemiD [],Objet vie [] ,int valeur_vie,SDL_Surface *texte ,SDL_Rect position,SDL_Surface *gestion_score ,SDL_Rect position2,Objet *mask,SDL_Rect pos )
{ 
  
  
  SDL_BlitSurface(map->img,&(map->pos),screen,NULL);
  
 
   
  if(tabD[0].pos.x<=0)
  SDL_BlitSurface(tabG[0].img,NULL,screen,&(tabD[0].pos));
  else
  {
    if(*curseur_perso>=6.4 )
       *curseur_perso=1 ;
    SDL_BlitSurface(tabG[(int)(*curseur_perso)].img,NULL,screen,&(tabD[0].pos));
  }
  if(box)
  {
   if(box->pos.x>=0)
  SDL_BlitSurface(box->img,NULL,screen,&(box->pos)) ;
  }

    if(ennemi[0].pos.x>=0)
    {
     if(left_ennemi) 
     {
      if(*curseur_perso>=5.4)
     SDL_BlitSurface(ennemi[5].img,NULL,screen,&(ennemi[0].pos)); 
     else 
     SDL_BlitSurface(ennemi[(int)compteur].img,NULL,screen,&(ennemi[0].pos)) ;
     }
     if(right_ennemi) 
     {
            if(*curseur_perso>=5.4)
     SDL_BlitSurface(ennemiD[5].img,NULL,screen,&(ennemi[0].pos)); 
     else 
     SDL_BlitSurface(ennemiD[(int)compteur].img,NULL,screen,&(ennemi[0].pos)) ; 
     }
    }
      if(valeur_vie<4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[0].pos)) ;
  
  }
  if(valeur_vie==4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[4].pos)) ;
  
  }
  SDL_BlitSurface(texte, NULL, screen, &position); 
  SDL_BlitSurface(gestion_score, NULL, screen, &position2); 

  SDL_Flip(screen) ;
}
void scrolling_droit (SDL_Surface *screen , Objet *map,Objet *mask)
{
 if (map->pos.x<=mapw-1368)
 {
   map->pos.x+=10 ;
   mask->pos.x+=10 ;
 }

   
}
void scrolling_gauche (SDL_Surface*screen , Objet *map,Objet *mask)
{
 if (map->pos.x>=0)
 {
   map->pos.x-=10 ;
   mask->pos.x-=10 ;
 }
}

float evenement (SDL_Surface *screen ,Objet *boat ,Objet *box,Objet *map,int *running,int *right,int*left,float *curseur_perso,Objet ennemi [],Objet *mask  )
{
 *left=0 ;
 *right=0 ;     
 SDL_Event event;

 SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                *running = 0 ;
            break;
            case SDL_KEYDOWN:

               switch(event.key.keysym.sym)

                  {
                    case SDLK_ESCAPE:
                         *running = 0;
                    break ;     
                  /* case SDLK_UP :
                   pos_perso->y-=7;
                  break ;
                  case SDLK_DOWN:
                  pos_perso->y+=7;
                  break ; */
                     case SDLK_RIGHT: // Flèche droite*
                     *right=1 ;
                   if(*curseur_perso >= 6.9)
                     *curseur_perso = 1;
                          box->pos.x-= 10 ;
                          ennemi[0].pos.x-=10 ;
                          scrolling_droit (screen ,map,mask) ;
                          (*curseur_perso) +=0.2 ;

                     break;

                     case SDLK_LEFT: // Flèche gauche
                      *left=1;

                     if(*curseur_perso >= 6.9)
                     *curseur_perso = 1;

                      box->pos.x+= 10 ;
                      ennemi[0].pos.x+=10 ;
                      scrolling_gauche (screen ,map,mask) ;
                          
                 
                  (*curseur_perso) +=0.2 ;
   
                     break;
              

                  }

            break;
           case SDL_MOUSEBUTTONDOWN:
            if(event.button.button==(SDL_BUTTON_LEFT ||SDL_BUTTON_RIGHT))
              {
                if(event.button.x<(1368/2))
                  {
                    *left=1;
                    if(*curseur_perso >= 6.9)
                     *curseur_perso = 1;

                      box->pos.x+= 10 ;
                    scrolling_gauche (screen ,map,mask) ;
                  (*curseur_perso) +=0.5 ;
                  }
             if(event.button.x>=(1368/2)) 
             {
                *right=1 ;
              if(*curseur_perso >= 6.9)
                *curseur_perso = 1;
                 box->pos.x-= 10 ;
              scrolling_droit (screen ,map,mask) ;
               (*curseur_perso) +=0.5 ;
                       
                          
               
             }
              }  

            break ;       
        }
 return (*curseur_perso) ; 
}
