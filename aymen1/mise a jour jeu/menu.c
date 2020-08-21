#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "menu.h"


void initiial (Objet *map,Objet *wood,Objet *boat,Objet tabD [],Objet tabG [],Objet ennemi [],Objet ennemiD [],Objet vie [],Objet *mask,Objet *keyboard,Objet *mouse,Objet *controller,Objet *choose,int save)
{
int i ;
   
  choose->img=IMG_Load("menu/Choose.png") ;
  choose->pos.x=0 ;
  choose->pos.y=0 ;


  mouse->img=IMG_Load("menu/Souris.png") ;
  mouse->pos.x=0 ;
  mouse->pos.y=0 ;
  mouse->pos_text.w=370 ;
  mouse->pos_text.h=320 ;
  mouse->pos_text.x=995 ;
  mouse->pos_text.y=220 ;

  controller->img=IMG_Load("menu/Manette.png") ;
  controller->pos.x=0 ;
  controller->pos.y=0 ;
  controller->pos_text.w=370 ;
  controller->pos_text.h=320 ;
  controller->pos_text.x=520 ;
  controller->pos_text.y=220 ;

  keyboard->img=IMG_Load("menu/Clavier.png") ;
  keyboard->pos.x=0 ;
  keyboard->pos.y=0 ;
  keyboard->pos_text.w=370 ;
  keyboard->pos_text.h=320 ;
  keyboard->pos_text.x=20 ;
  keyboard->pos_text.y=220 ;

  mask->img=IMG_Load("mask22.png") ; 
  mask->pos.x=0 ;
  mask->pos.y=0 ;
  mask->pos.w=width ;
  mask->pos.h=height ;


  char image [20] ;
  for (i=0;i<5;i++)
  {
    if(i<4)
    {
   sprintf(image,"Vie/coeur%d.png",i+1)  ;
      vie[i].img=IMG_Load(image) ;
   vie[i].pos.x=vie_w ;
   vie[i].pos.y=vie_h;
    }
   else if(i==4)
   {
   sprintf(image,"Vie/coeur%d.jpg",i+1)  ;
   vie[i].img=IMG_Load(image) ;
   vie[i].pos.x=150 ;
   vie[i].pos.y=200;
   }

  } 
  for (i=0;i<6;i++)
  {
   sprintf(image,"ennemiD/%d.png",i+1)  ;
   ennemiD[i].img=IMG_Load(image) ;
   ennemiD[i].pos.x=xboat ;
   ennemiD[i].pos.y=yboat;
  } 
  for (i=0;i<6;i++)
  {
   sprintf(image,"ennemi/%d.png",i+1)  ;
   ennemi[i].img=IMG_Load(image) ;
   ennemi[i].pos.x=(1386*2)-700 ;
   ennemi[i].pos.y=yboat;
  } 

   
  for (i=0;i<8;i++)
  {
   sprintf(image,"persoD/%d.png",i+1)  ;
   tabD[i].img=IMG_Load(image) ;
   tabD[i].pos.x=0 ;
   tabD[i].pos.y=0;
   tabD[0].vx=0 ;
  }
    for (i=0;i<7;i++)
  {
   sprintf(image,"persoG/%dwalk.png",i+1)  ;
   tabG[i].img=IMG_Load(image) ;
   tabG[i].pos.x=xwood ;
   tabG[i].pos.y=ywood ;
  }

  wood->img=IMG_Load("persoG/walk6.png") ;
  wood->pos.x=xwood ;
  wood->pos.y=ywood ;

  boat->img=IMG_Load("persoD/1.png") ; 
  boat->pos.x=xboat ;
  boat->pos.y=yboat ;

  if(save==1)
  {
  map->img= IMG_Load("mappppp3-01.jpg") ;
  map->pos.x=0 ;
  map->pos.y=0 ;
  }
  else if(save==2)
  {
   map->img= IMG_Load("level2.png") ;
  map->pos.x=0 ;
  map->pos.y=0 ;   
  }
  else if(save==3)
  {
  map->img= IMG_Load("level3.png") ;
  map->pos.x=0 ;
  map->pos.y=0 ;    
  }
  
  
  map->pos.w=width ;
  map->pos.h=height ;

}
void initialiser (Objet *newgame,Objet *loadgame ,Objet *settings,Objet *icon,Objet *in_sound ,Objet *in_sound25,Objet *in_sound50,Objet *in_sound75,Objet *in_sound100,Objet *in_settings,Objet *credits,Objet *main_menu ,Objet *quitter,Objet *wexit,Objet *nwexit ,Objet *exxit,Objet *game,Objet *map,Objet *wood,Objet *boat,Objet tabD [],Objet tabG [],Objet ennemi [],Objet ennemiD [],Objet vie [],Objet *mask,Objet *keyboard,Objet *mouse,Objet *controller,Objet *choose,int save)
{
  int i ;
    
  choose->img=IMG_Load("menu/Choose.png") ;
  choose->pos.x=0 ;
  choose->pos.y=0 ;


  mouse->img=IMG_Load("menu/Souris.png") ;
  mouse->pos.x=0 ;
  mouse->pos.y=0 ;
  mouse->pos_text.w=370 ;
  mouse->pos_text.h=320 ;
  mouse->pos_text.x=995 ;
  mouse->pos_text.y=220 ;

  controller->img=IMG_Load("menu/Manette.png") ;
  controller->pos.x=0 ;
  controller->pos.y=0 ;
  controller->pos_text.w=370 ;
  controller->pos_text.h=320 ;
  controller->pos_text.x=520 ;
  controller->pos_text.y=220 ;

  keyboard->img=IMG_Load("menu/Clavier.png") ;
  keyboard->pos.x=0 ;
  keyboard->pos.y=0 ;
  keyboard->pos_text.w=370 ;
  keyboard->pos_text.h=320 ;
  keyboard->pos_text.x=20 ;
  keyboard->pos_text.y=220 ;

  mask->img=IMG_Load("mask22.png") ; 
  mask->pos.x=0 ;
  mask->pos.y=0 ;
  mask->pos.w=width ;
  mask->pos.h=height ;


  char image [20] ;
  for (i=0;i<5;i++)
  {
    if(i<4)
    {
   sprintf(image,"Vie/coeur%d.png",i+1)  ;
      vie[i].img=IMG_Load(image) ;
   vie[i].pos.x=vie_w ;
   vie[i].pos.y=vie_h;
    }
   else if(i==4)
   {
   sprintf(image,"Vie/coeur%d.jpg",i+1)  ;
   vie[i].img=IMG_Load(image) ;
   vie[i].pos.x=150 ;
   vie[i].pos.y=200;
   }

  } 
  for (i=0;i<6;i++)
  {
   sprintf(image,"ennemiD/%d.png",i+1)  ;
   ennemiD[i].img=IMG_Load(image) ;
   ennemiD[i].pos.x=xboat ;
   ennemiD[i].pos.y=yboat;
  } 
  for (i=0;i<6;i++)
  {
   sprintf(image,"ennemi/%d.png",i+1)  ;
   ennemi[i].img=IMG_Load(image) ;
   ennemi[i].pos.x=(1386*2)-700 ;
   ennemi[i].pos.y=yboat;
  } 

   
  for (i=0;i<8;i++)
  {
   sprintf(image,"persoD/%d.png",i+1)  ;
   tabD[i].img=IMG_Load(image) ;
   tabD[i].pos.x=0 ;
   tabD[i].pos.y=0;
   tabD[0].vx=0 ;
  }
    for (i=0;i<7;i++)
  {
   sprintf(image,"persoG/%dwalk.png",i+1)  ;
   tabG[i].img=IMG_Load(image) ;
   tabG[i].pos.x=xwood ;
   tabG[i].pos.y=ywood ;
  }

  wood->img=IMG_Load("persoG/walk6.png") ;
  wood->pos.x=xwood ;
  wood->pos.y=ywood ;

  boat->img=IMG_Load("mini1.png") ; 
  boat->pos.x=xboat+240 ;
  boat->pos.y=yboat+10 ;

  if(save==1)
  {
  map->img= IMG_Load("mappppp3-01.jpg") ;
  map->pos.x=0 ;
  map->pos.y=0 ;
  }
  else if(save==2)
  {
   map->img= IMG_Load("level2.png") ;
  map->pos.x=0 ;
  map->pos.y=0 ;   
  }
  else if(save==3)
  {
  map->img= IMG_Load("level3.png") ;
  map->pos.x=0 ;
  map->pos.y=0 ;    
  }
  
  
  map->pos.w=width ;
  map->pos.h=height ;

  game->img = IMG_Load("game.png");
  game->pos.x=0 ;
  game->pos.y=0 ;
if(save==0)
{
  newgame->img=IMG_Load("newgame.png");
  newgame->pos.x=0 ;
  newgame->pos.y=0 ;
  newgame->pos_text.w=n_w ;
  newgame->pos_text.h=n_h ;
  newgame->pos_text.x=670 ;
  newgame->pos_text.y=185 ;
}
  else
  {
  i   
  newgame->img=IMG_Load("curseur.png");
  newgame->pos.x=xboat+240  ;
  newgame->pos.y=yboat+25 ;    
  }
  



  loadgame->img=IMG_Load("loadgame.png");
  loadgame->pos.x=0 ;
  loadgame->pos.y=0 ;
  loadgame->pos_text.w=n_w ;
  loadgame->pos_text.h=n_h ;
  loadgame->pos_text.x=670 ;
  loadgame->pos_text.y=225 ;
  

  settings->img=IMG_Load("settings.png");
  settings->pos.x=0 ;
  settings->pos.y=0 ;
  settings->pos_text.w=s_w ;
  settings->pos_text.h=s_h ;
  settings->pos_text.x=695 ;
  settings->pos_text.y=265 ;



  icon->img=IMG_Load("yes.png");
  icon->pos.x=495 ;
  icon->pos.y=77;
  icon->pos_text.w=sound_w ;
  icon->pos_text.h=sound_h ;
  icon->pos_text.x=495 ;
  icon->pos_text.y=77;
  
  in_sound->img=IMG_Load("asound0.png");
  in_sound->pos.x=0 ;
  in_sound->pos.y=0 ;
  in_sound->pos_text.w=i_s_w ;
  in_sound->pos_text.h=i_s_h ;
  in_sound->pos_text.x=685; 
  in_sound->pos_text.y=165 ;


  in_sound25->img=IMG_Load("asound25.png");
  in_sound25->pos.x=0 ;
  in_sound25->pos.y=0 ;

  in_sound50->img=IMG_Load("asound50.png") ;
  in_sound50->pos.x=0 ;
  in_sound50->pos.y=0 ;

  in_sound75->img=IMG_Load("asound75.png") ;
  in_sound75->pos.x=0 ;
  in_sound75->pos.y=0 ;

  in_sound100->img=IMG_Load("asound100.png");
  in_sound100->pos.x=0 ;
  in_sound100->pos.y=0 ;

  in_settings->img=IMG_Load("settings2.png") ;
  in_settings->pos.x=0 ;
  in_settings->pos.y=0 ;

  credits->img=IMG_Load("credits.png") ;
  credits->pos.x=0 ;
  credits->pos.y=0 ;
  credits->pos_text.w=i_s_w ;
  credits->pos_text.h=i_s_h ;
  credits->pos_text.x=675 ;
  credits->pos_text.y=214 ;



  main_menu->img=IMG_Load("main_menu.png");
  main_menu->pos.x=0 ;
  main_menu->pos.y=0 ;
  main_menu->pos_text.w=i_s_w ;
  main_menu->pos_text.h=i_s_h ;
  main_menu->pos_text.x=635 ;
  main_menu->pos_text.y=280 ;



  quitter->img=IMG_Load("exit.png");
  quitter->pos.x=0 ;
  quitter->pos.y=0 ;
  quitter->pos_text.w=e_w ;
  quitter->pos_text.h=e_h ;
  quitter->pos_text.x=715 ;
  quitter->pos_text.y=310 ;


  wexit->img=IMG_Load("ywexit.png") ;
  wexit->pos.x=0 ;
  wexit->pos.y=0 ;
  wexit->pos_text.w=yn_w ;
  wexit->pos_text.h=yn_h ;
  wexit->pos_text.x=765 ;
  wexit->pos_text.y=265 ;



  nwexit->img=IMG_Load("nwexit.png") ;
  nwexit->pos.x=0 ;
  nwexit->pos.y=0 ;
  nwexit->pos_text.w=yn_w  ;
  nwexit->pos_text.h=yn_h  ;
  nwexit->pos_text.x=630 ;
  nwexit->pos_text.y=265  ;


  exxit->img=IMG_Load("wexit.png") ;
  exxit->pos.x=0 ;
  exxit->pos.y=0 ;

}
void setup (SDL_Surface *screen ,Objet *game,Objet *icon)
{
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(game->img, NULL, screen, &(game->pos));
    SDL_BlitSurface(icon->img, NULL, screen, &(icon->pos));
    SDL_Flip(screen);
}
int verif_motion_surface (SDL_Event event,Objet surface)
{
  int pos=0 ;

  if (event.motion.x > surface.pos_text.x && event.motion.x < (surface.pos_text.w + surface.pos_text.x) && event.motion.y > surface.pos_text.y && event.motion.y < (surface.pos_text.h + surface.pos_text.y)) 
    pos=1 ;

    return pos ;
  
}
void update (SDL_Surface *screen , Objet *surface1,Objet *surface2)
{
  if(surface1!=NULL)
  SDL_BlitSurface(surface1->img, NULL, screen, &(surface1->pos));
  if(surface2!=NULL)
  SDL_BlitSurface(surface2->img, NULL, screen, &(surface2->pos));

  SDL_Flip (screen) ;
}
void liberate (Objet *newgame,Objet *loadgame ,Objet *settings,Objet *icon,Objet *in_sound ,Objet *in_sound25,Objet *in_sound50,Objet *in_sound75,Objet *in_sound100,Objet *in_settings,Objet *credits,Objet *main_menu ,Objet *quitter,Objet *wexit,Objet *nwexit ,Objet *exxit,Objet *game)
{
  SDL_FreeSurface (newgame->img);
  SDL_FreeSurface (loadgame->img);
  SDL_FreeSurface (settings->img);
  SDL_FreeSurface (icon->img);
  SDL_FreeSurface (in_sound->img);
  SDL_FreeSurface (in_sound25->img);
  SDL_FreeSurface (in_sound50->img);
  SDL_FreeSurface (in_sound75->img);
  SDL_FreeSurface (in_sound100->img);
  SDL_FreeSurface (in_settings->img);
  SDL_FreeSurface (credits->img);
  SDL_FreeSurface (main_menu->img);
  SDL_FreeSurface (quitter->img);
  SDL_FreeSurface (wexit->img);
  SDL_FreeSurface (nwexit->img);
  SDL_FreeSurface (exxit->img);
  SDL_FreeSurface (game->img);




}
void clic_souris_menu_principale (SDL_Surface *screen,SDL_Event event, int curseur ,Objet newgame,Objet loadgame,Objet settings,Objet in_settings,Objet *icon,Objet quitter,int *in,int *running,int *boolean_icon,int *quitt,Objet exxit,Objet tab [],int *transition,int *save)
{
            if (event.button.button == SDL_BUTTON_LEFT && (curseur)==1 )
           {
            if(verif_motion_surface (event,newgame)) 
            {
             *transition=1 ;

            } 
            else if(verif_motion_surface (event,*icon)) 
            {
             if((*boolean_icon==1))
             {
             icon->img=IMG_Load("no.png");
             update (screen ,&newgame,icon) ;
             Mix_Volume(1,0);
             Mix_VolumeMusic(0);
             (*boolean_icon)=0 ;
             }
             else if ((*boolean_icon==0))
             {
             icon->img=IMG_Load("yes.png");
             update (screen ,&newgame,icon) ;
             (*boolean_icon)=1 ;    
             Mix_Volume(1,MIX_MAX_VOLUME); 
             Mix_VolumeMusic(128);          
             }
            }     
           }
           if (event.button.button == SDL_BUTTON_LEFT && (curseur)==2 )
           {
            if(verif_motion_surface (event,loadgame)) 
            {
             *save=1 ;   
            } 
            else if(verif_motion_surface (event,*icon)) 
            {
             if((*boolean_icon==1))
             {
             icon->img=IMG_Load("no.png");
             update (screen ,&newgame,icon) ;
             (*boolean_icon)=0 ;
             Mix_Volume(1,0);
             Mix_VolumeMusic(0);
             }
             else if ((*boolean_icon==0))
             {
             icon->img=IMG_Load("yes.png");
             update (screen ,&newgame,icon) ;
             (*boolean_icon)=1 ;
             Mix_VolumeMusic(128);
             Mix_Volume(1,MIX_MAX_VOLUME);               
             }
            }                          
           }
           if (event.button.button == SDL_BUTTON_LEFT && (curseur)==3 )
           {
            if(verif_motion_surface (event,settings)) 
            {
             update (screen ,&in_settings,icon) ;
             *in=1 ;
            } 
            else if(verif_motion_surface (event,*icon)) 
            {
             if((*boolean_icon==1))
             {
             icon->img=IMG_Load("no.png");
             update (screen ,&newgame,icon) ;
             (*boolean_icon)=0 ;
             Mix_Volume(1,0);
             Mix_VolumeMusic(0);
             }
             else if ((*boolean_icon==0))
             {
             icon->img=IMG_Load("yes.png");
             update (screen ,&newgame,icon) ;
             (*boolean_icon)=1 ;
             Mix_Volume(1,MIX_MAX_VOLUME);   
             Mix_VolumeMusic(128);            
             }
            }                           
           }
           if (event.button.button == SDL_BUTTON_LEFT && (curseur)==4 )
           {
            if(verif_motion_surface (event,quitter)) 
            {
             update (screen ,&exxit,icon) ; 
             *quitt=1 ;  
            }
            else if(verif_motion_surface (event,*icon)) 
            {
             if((*boolean_icon==1))
             {
             icon->img=IMG_Load("no.png");

             update (screen ,&newgame,icon) ;
             (*boolean_icon)=0 ;
             Mix_Volume(1,0);
             Mix_VolumeMusic(0);
            
             }
             else if ((*boolean_icon==0))
             {
             icon->img=IMG_Load("yes.png");
             update (screen ,&newgame,icon) ;
             (*boolean_icon)=1 ; 
             Mix_Volume(1,MIX_MAX_VOLUME);  
             Mix_VolumeMusic(128);            
             }
            }                           
           }
 
}
void clic_entrer_menu_principale (SDL_Surface *screen ,Objet in_settings,Objet icon,Mix_Chunk *effect, int curseur,int *in,int *running,int *quitt,Objet exxit,int *transition,int *save )
{
               switch ((curseur))
             {
               case 1:
                *transition=1 ;
               break;
               case 2:
               *save=1 ;
               break;               
               case 3:
                   update (screen ,&in_settings,&icon) ;
                   Mix_PlayChannel(1,effect,0);  
                   *in=1 ;               
               break; 
               case 4:
                   update (screen ,&exxit,&icon) ;
                   *quitt=1 ;
                   Mix_PlayChannel(1,effect,0);  
                
               break;                           
             }
}
void mouse_motion_main_menu (SDL_Surface *screen ,SDL_Event event,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *quitt )
{
          if(verif_motion_surface (event,newgame)) 
            {
              if((*curseur)==1)
              return;
             *curseur=1 ;
              update (screen ,&newgame,&icon) ;
              Mix_PlayChannel(1,effect,0);              
            }
          if(verif_motion_surface (event,loadgame)) 
            {
              if((*curseur)==2)
              return;              
             *curseur=2 ;
              update (screen ,&loadgame,&icon) ;
              Mix_PlayChannel(1,effect,0);              
            }
          if(verif_motion_surface (event,settings)) 
            {
              if((*curseur)==3)
              return;              
             *curseur=3 ;
              update (screen ,&settings,&icon) ;
              Mix_PlayChannel(1,effect,0);              
            }                        
          if(verif_motion_surface (event,quitter)) 
            {
              if((*curseur)==4)
              return;              
             *curseur=4 ;
              update (screen ,&quitter,&icon) ;
              Mix_PlayChannel(1,effect,0);              
            }
}

void deplacementmenu_down (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *quitt )
{
               (*curseur)++ ;
               if((*curseur)<5)
                switch ((*curseur))
                  {
                    case 1:
                       update (screen ,&newgame,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break;
                    case 2 :
                       update (screen ,&loadgame,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break;
                    case 3 :
                       update (screen ,&settings,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break ;
                    case 4 : 
                       update (screen ,&quitter,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break ;    

                  }
                else
                {
                  update (screen ,&newgame,&icon) ;
                  Mix_PlayChannel(1,effect,0);
                  (*curseur)=1 ;
                }
}
void deplacementmenu_up (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *firsttime,int *quitt)
{
              if((*curseur)==0 && (*firsttime)==0)
               {
                 update (screen ,&newgame,&icon) ;
                 Mix_PlayChannel(1,effect,0);
                 (*curseur)=1 ;
                 (*firsttime)=1 ;
               }
             else
               {
                 (*curseur)-- ;
                 if((*curseur)!=0)
                 {
                  switch ((*curseur))
                  {
                    case 1:
                       update (screen ,&newgame,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break;
                    case 2 :
                       update (screen ,&loadgame,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break;
                    case 3 :
                       update (screen ,&settings,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break ;
                    case 4 : 
                       update (screen ,&quitter,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break ; 
                  }//fin switch (*curseur)
                 }
                 else 
                 {
                       update (screen ,&quitter,&icon) ;
                       Mix_PlayChannel(1,effect,0); 
                       (*curseur)=4 ;                  
                 }
                 
               } 
}
/**
* @brief choisir type de mouvement
* @param screen  the screen
* @param  curseur etat 
* @return nothing
*/
int deplacementmenu_up_down(SDL_Surface *screen, SDL_Event event ,int *firsttime,int *curseur,int *running,Objet newgame,Objet loadgame,Objet settings ,Objet quitter ,Objet *icon,Objet in_settings , Mix_Chunk *effect,int *boolean_icon,int *quitt,Objet exxit,Objet tab [],int *transition,int *save)
{

  int in=0 ;
  *transition=0 ;
  *quitt= 0 ;
      SDL_WaitEvent(&event);
    switch (event.type)
    {
      case SDL_QUIT:
      *running = 0;
      break ;
      case SDL_MOUSEBUTTONDOWN:
           clic_souris_menu_principale (screen,event, *curseur ,newgame,loadgame,settings,in_settings,icon,quitter,&in,running,boolean_icon,quitt,exxit,tab,transition,save) ;                   
      break;
      case SDL_MOUSEMOTION:
           mouse_motion_main_menu (screen , event,effect,curseur,newgame,*icon,loadgame,settings,quitter,quitt ) ;
      break;
      case SDL_KEYDOWN:
          switch (event.key.keysym.sym)
          {
           case SDLK_ESCAPE:
            
           *quitt=1 ;
           break ; 
           case SDLK_RETURN:
               clic_entrer_menu_principale (screen ,in_settings,*icon,effect,*curseur,&in,running,quitt,exxit,transition,save ) ;
           break ;
           case SDLK_DOWN :
               deplacementmenu_down (screen ,effect,curseur,newgame,*icon,loadgame,settings,quitter,quitt ) ;
           break ;
           case SDLK_UP :
               deplacementmenu_up (screen ,effect,curseur,newgame,*icon,loadgame,settings,quitter,firsttime,quitt ) ;
           break ;
     
          }//fin sswitch keydown
    }//fin switch 

     return in ;
}
void deplacement__sousmenu_down (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume,Objet icon,Objet credits,Objet main_menu)
{
                (*curseur)++ ;
               if((*curseur)<4)
                switch ((*curseur))
                  {
                    case 1:
                       update_volume_surface(screen,effect,in_sound ,in_sound25,in_sound50,in_sound75,in_sound100,position_volume) ;
                       
                    break;
                    case 2 :
                       update (screen ,&credits,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break;
                    case 3 :
                       update (screen ,&main_menu,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break ;
                  }
                else
                {
                  update_volume_surface(screen,effect,in_sound ,in_sound25,in_sound50,in_sound75,in_sound100,position_volume) ;
                  
                  (*curseur)=1 ;
                }
}
void deplacement__sousmenu_up (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume,Objet icon,Objet credits,Objet main_menu,int *firsttime)
{
               if((*curseur)==0 && (*firsttime)==0)
               {
                 update_volume_surface(screen,effect,in_sound ,in_sound25,in_sound50,in_sound75,in_sound100,position_volume) ;
                 
                 (*curseur)=1 ;
                 (*firsttime)=1 ;
               }
             else
               {
                 (*curseur)-- ;
                 if((*curseur)!=0)
                 {
                  switch ((*curseur))
                  {
                    case 1:
                       update_volume_surface(screen,effect,in_sound ,in_sound25,in_sound50,in_sound75,in_sound100,position_volume) ;
                       Mix_PlayChannel(1,effect,0);
                    break;
                    case 2 :
                       update (screen ,&credits,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break;
                    case 3 :
                       update (screen ,&main_menu,&icon) ;
                       Mix_PlayChannel(1,effect,0);
                    break ;
                  }//fin switch (*curseur)
                 }
                 else 
                 {
                       update (screen ,&main_menu,&icon) ;
                       Mix_PlayChannel(1,effect,0); 
                       (*curseur)=3 ;                  
                 }
                 
               } 
}
void update_volume_surface(SDL_Surface *screen,Mix_Chunk *effect,Objet in_sound ,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume)
{
 switch (position_volume)
 {
   case 1:
     update (screen ,&in_sound,NULL) ;
     Mix_PlayChannel(1,effect,0);
     break;
 
   case 2:
     update (screen ,&in_sound25,NULL) ;
     Mix_PlayChannel(1,effect,0);
     break;
   case 3:
     update (screen ,&in_sound50,NULL) ;
     Mix_PlayChannel(1,effect,0);
     break;
   case 4:
     update (screen ,&in_sound75,NULL) ;
     Mix_PlayChannel(1,effect,0);
     break;
   case 5:
     update (screen ,&in_sound100,NULL) ;
     Mix_PlayChannel(1,effect,0);
     break;               
 }
}
void motion_souris_sousmenu (SDL_Surface *screen ,SDL_Event event , Mix_Chunk *effect,int *curseur,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume,Objet icon,Objet credits,Objet main_menu)
{
           if(verif_motion_surface (event,in_sound)) 
            {
              if((*curseur)==1)
              return;
             *curseur=1 ;
              update_volume_surface(screen,effect,in_sound ,in_sound25,in_sound50,in_sound75,in_sound100,position_volume) ;
              Mix_PlayChannel(1,effect,0);              
            }
          if(verif_motion_surface (event,credits)) 
            {
              if((*curseur)==2)
              return;              
             *curseur=2 ;
              update (screen ,&credits,&icon) ;
              Mix_PlayChannel(1,effect,0);              
            }
          if(verif_motion_surface (event,main_menu)) 
            {
              if((*curseur)==3)
              return;              
             *curseur=3 ;
              update (screen ,&main_menu,&icon) ;
              Mix_PlayChannel(1,effect,0);              
            }  
                    
}
void clic_souris_sousmenu (SDL_Surface *screen,Objet *icon, SDL_Event event,int curseur,Objet in_sound,Objet credits, Objet main_menu,int *running2,Objet game,int *boolean_icon)
{
             if (event.button.button == SDL_BUTTON_LEFT && (curseur)==1 )
           {
            if(verif_motion_surface (event,in_sound)) 
            {
                
            }               
           }
           else if (event.button.button == SDL_BUTTON_LEFT && (curseur)==2 )
           {
            if(verif_motion_surface (event,credits)) 
            {
                
            }   
            else if(verif_motion_surface (event,*icon)) 
            {
             if((*boolean_icon==1))
             {
             icon->img=IMG_Load("no.png");
             update (screen ,&credits,icon) ;
             (*boolean_icon)=0 ;
             Mix_Volume(1,0);
             Mix_VolumeMusic(0);
             }
             else if ((*boolean_icon==0))
             {
             icon->img=IMG_Load("yes.png");
             update (screen ,&credits,icon) ;
             (*boolean_icon)=1 ; 
             Mix_Volume(1,MIX_MAX_VOLUME); 
             Mix_VolumeMusic(128);             
             }
            }             
           }
           else if (event.button.button == SDL_BUTTON_LEFT && (curseur)==3 )
           {
            if(verif_motion_surface (event,main_menu)) 
            {
              update(screen,&game,icon) ;
             *running2=0 ;
             
            }
            else if(verif_motion_surface (event,*icon)) 
            {
             if((*boolean_icon==1))
             {
             icon->img=IMG_Load("no.p ng");
             update (screen ,&main_menu,icon) ;
             (*boolean_icon)=0 ;
             Mix_Volume(1,0);
             Mix_VolumeMusic(0);
             }
             else if ((*boolean_icon==0))
             {
             icon->img=IMG_Load("yes.png");
             update (screen ,&main_menu,icon) ;
             (*boolean_icon)=1 ; 
              Mix_Volume(1,MIX_MAX_VOLUME); 
              Mix_VolumeMusic(128);             
             }
             
            }               
           }
 
}
void clic_entrer_sousmenu (SDL_Surface *screen,Objet icon, int *running2,int curseur,Objet game)
{
                switch ((curseur))
             {
               case 1:
               
               break;
               case 2:
               
               break;               
               case 3:
               update(screen,&game,&icon) ;
               *running2=0 ;              
               break; 

                      
             }
}
void deplacement_droit_gauche_volume (SDL_Surface *screen,Mix_Chunk *effect,Objet in_sound ,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int *position_volume) 
{
  if ((*position_volume)<1)
      (*position_volume)=1 ;      

  else if ((*position_volume)>5) 
      (*position_volume)=5 ;
  else
  {
    update_volume_surface(screen,effect,in_sound ,in_sound25,in_sound50,in_sound75,in_sound100,*position_volume) ;
  }
          
}
void deplacement_sous_menu (SDL_Surface *screen ,Mix_Chunk *effect,SDL_Event event , int *running2,Objet in_settings,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int *position_volume,Objet credits,Objet main_menu,Objet *icon, int *running,int *curseur,int *firsttime,Objet game,int *boolean_icon)
{
   

   SDL_WaitEvent(&event);
    switch (event.type)
    {
      case SDL_QUIT:
      *running = 0;
      *running2=0 ;
      break ;
      case SDL_MOUSEBUTTONDOWN:
            clic_souris_sousmenu (screen,icon,event,*curseur,in_sound,credits,main_menu,running2,game,boolean_icon)  ;                
      break;
      case SDL_MOUSEMOTION:
            motion_souris_sousmenu (screen ,event , effect,curseur,in_sound,in_sound25,in_sound50,in_sound75,in_sound100,*position_volume,*icon,credits,main_menu) ;
      break;
      case SDL_KEYDOWN:
          switch (event.key.keysym.sym)
          {
           case SDLK_ESCAPE:
           *running2=0 ;
           update(screen,&game,icon) ;
           break ; 
           case SDLK_RETURN:
               clic_entrer_sousmenu (screen,*icon,running2,*curseur,game) ;
           break ;
           case SDLK_DOWN :
               deplacement__sousmenu_down (screen ,effect,curseur,in_sound,in_sound25,in_sound50,in_sound75,in_sound100,*position_volume,*icon,credits,main_menu) ;
           break ;
           case SDLK_UP :
               deplacement__sousmenu_up (screen ,effect,curseur,in_sound,in_sound25,in_sound50,in_sound75,in_sound100,*position_volume,*icon,credits,main_menu,firsttime) ;
           break ; 
           case SDLK_RIGHT :
              (*position_volume)++ ;
             deplacement_droit_gauche_volume (screen,effect,in_sound ,in_sound25,in_sound50,in_sound75,in_sound100,position_volume);
           break ;
           case SDLK_LEFT :
              (*position_volume)-- ;
             deplacement_droit_gauche_volume (screen,effect,in_sound ,in_sound25,in_sound50,in_sound75,in_sound100,position_volume);
           break ;
     
          }//fin sswitch keydown
    }//fin switch 


}
void quitter_oui_non(SDL_Surface *screen ,SDL_Event event,int *running,int *running2,int *running3,Objet quitter,Objet icon,Objet wexit,Objet nwexit,int *test,int *test_s)
{
  
  SDL_WaitEvent(&event);
    switch (event.type)
    {
      case SDL_QUIT:
      *running = 0;
      *running2 = 0;
      *running3 = 0;
      break ;
      case SDL_MOUSEBUTTONDOWN:
      if (event.button.button == SDL_BUTTON_LEFT  )
      {
          if (verif_motion_surface(event,wexit))
           {
                   *running = 0;
                   *running3 = 0; 
              
           }  
           else if (verif_motion_surface(event,nwexit)) 
           {
                   update (screen,&quitter,&icon) ; 
                   *running3 = 0;        
           }
           
      }                 
      break;
      case SDL_MOUSEMOTION:
           if (verif_motion_surface(event,wexit))
           {
              update (screen,&wexit,&icon) ;
              (*test_s)=1 ;
              
           }
           else if (verif_motion_surface(event,nwexit)) 
           {
              update (screen,&nwexit,&icon) ;   
              (*test_s)=0 ;
           }
      break;
      case SDL_KEYDOWN:
          switch (event.key.keysym.sym)
          {
           case SDLK_ESCAPE:
           update(screen,&quitter,&icon) ;
           *running3=0 ;
           break ; 
           case SDLK_RETURN:
           if ((*test) % 2==0 || (*test_s)==1)
           {
                   *running = 0;
                   *running3 = 0; 
           }
              
             
           if ((*test) % 2!=0 || (*test_s)==0  )
           {
                   update (screen,&quitter,&icon) ; 
                   *running3 = 0;    
           }    
           
           break ;
           case SDLK_RIGHT :
               (*test )++ ;
               if ((*test) % 2==0)
               {
                  update (screen,&wexit,&icon) ;
                  (*test_s)=1 ;
               }


               else if ((*test) % 2!=0)
                {
                  update (screen,&nwexit,&icon) ;
                  (*test_s)=0 ;
                }

                 
           break ;
           case SDLK_LEFT :
                (*test )++ ;
               if ((*test) % 2==0)
               {
                  update (screen,&wexit,&icon) ;
                  (*test_s)=1 ;
               }
               else if ((*test) % 2!=0)
               {
                  update (screen,&nwexit,&icon) ;   
                  (*test_s)=0 ; 
               }
           break ;
     
          }//fin sswitch keydown
    }//fin switch 

}
void load_transition(Objet tab [] )
{
  int i ;
  char image [50] ;
  for(i=0;i<190;i++)
  {
    if(i<9)
    sprintf(image,"imageeffect/newgame_00%d.png",i+1) ;
    else if (i<99 && i>=9)
    sprintf(image,"imageeffect/newgame_0%d.png",i+1) ;
    else if (i>=99)
    sprintf(image,"imageeffect/newgame_%d.png",i+1) ;
    
    tab[i].img=IMG_Load(image) ;
    tab[i].pos.x=0 ;
    tab[i].pos.y=0 ;
  }
}
void update_transition(SDL_Surface *screen ,Objet tab [],int *i)
{
    
    update(screen,&tab[*i],NULL) ;

    if((*i)>=1)
    SDL_FreeSurface((tab[(*i)-1].img));
    (*i)++ ;
  
}
void update_fonts(int *tempsActuel,int *tempsPrecedent,int *compteurr,int *seconde,char temps [],char score [],int *score_finale,SDL_Surface **texte,SDL_Surface **gestion_score,TTF_Font *police,SDL_Color couleurBlanche )
{
                        (*tempsActuel) = SDL_GetTicks();
                       if ((*tempsActuel) -  (*tempsPrecedent) >= 1000) 
                      {

                            (*seconde)+=1 ;
                             if((*seconde) %10==0)
                              (*score_finale)-=10 ;
                         
                          sprintf(temps, "Temps : %d", *seconde); 
                          sprintf(score, "Score: %d", *score_finale); 
                          SDL_FreeSurface(*texte); 
                          SDL_FreeSurface(*gestion_score);    
                          (*gestion_score)=TTF_RenderText_Blended(police,score, couleurBlanche) ;  
                          (*texte) = TTF_RenderText_Blended(police, temps, couleurBlanche); 
                          (*tempsPrecedent) = (*tempsActuel); 

                      }
                      
}