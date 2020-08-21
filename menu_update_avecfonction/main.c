#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "menu.h"


int main ()
{
SDL_Surface *screen = NULL ;
Objet newgame,loadgame,settings,icon,in_sound,in_sound25,in_sound50,in_sound75,in_sound100 ;
Objet in_settings,credits,main_menu,quitter,wexit,nwexit,exxit,game ;
SDL_Event event, event2;
Mix_Music  *music_back=NULL;
 Mix_Chunk *effect ;

int running = 1,running2=1,running3=1;
int curseur = 0, firsttime = 0,in,s=0,position_volume=5,boolean_icon=1,quitt=0,test=1,test_s;


  SDL_Init(SDL_INIT_VIDEO);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }

  screen = SDL_SetVideoMode(width,height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  initialiser (&newgame,&loadgame ,&settings,&icon,&in_sound ,&in_sound25,&in_sound50,&in_sound75,&in_sound100,&in_settings,&credits,&main_menu ,&quitter,&wexit,&nwexit ,&exxit,&game) ;

  music_back = Mix_LoadMUS("soundtrack-jumanji-welcome-to-the-jungle-theme-song-epic-music-2017-musique-film-jumanji.wav");
  effect= Mix_LoadWAV("son1.wav");
  Mix_PlayMusic(music_back,-1) ;
  // Mix_PlayChannel(1,effect,0);
  

  setup (screen ,&game,&icon) ;
  SDL_EnableKeyRepeat(100, 100);
  while(running)
  {
   in=deplacementmenu_up_down(screen,event ,&firsttime,&curseur,&running,newgame,loadgame,settings ,quitter,&icon,in_settings,effect,&boolean_icon,&quitt,exxit) ;
        if(quitt)
     {
       running3=1 ;
       update (screen,&exxit,&icon) ; 
       {
         test= 1 ;
         while(running3)
         {
          quitter_oui_non(screen ,event,&running,&running2,&running3,quitter,icon,wexit,nwexit,&test,&test_s) ; 
         }
         
       }
     }
   if(in)
   {
     running2=1 ;
     update (screen,&in_settings,&icon) ; 
     curseur=0,firsttime=0 ;
    while(running2)
    {
     deplacement_sous_menu (screen ,effect,event ,&running2,in_settings,in_sound,in_sound25,in_sound50,in_sound75,in_sound100,&position_volume,credits,main_menu,&icon,&running,&curseur,&firsttime,settings,&boolean_icon) ; 

    }

     
   }

  }//fin running
  liberate (&newgame,&loadgame ,&settings,&icon,&in_sound ,&in_sound25,&in_sound50,&in_sound75,&in_sound100,&in_settings,&credits,&main_menu ,&quitter,&wexit,&nwexit ,&exxit,&game) ;


}