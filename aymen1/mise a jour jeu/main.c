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
 SDL_Surface *screen = NULL,*texte = NULL,*gestion_score = NULL ;
SDL_Rect position,position2,pos;
Objet newgame,loadgame,settings,icon,in_sound,in_sound25,in_sound50,in_sound75,in_sound100, ennemi [7], ennemiD [7],vie [6],mini_map ;
Objet in_settings,credits,main_menu,quitter,wexit,nwexit,exxit,game,map,wood,boat,e,en,mask,keyboard,mouse,controller,choose,sauvgarder ;
SDL_Event event, event2;
Mix_Music  *music_back=NULL;
Objet tab [190],tabD[20],tabG[20] ;
 Mix_Chunk *effect ;
 Saving S ;


 S.level=0 ;
int running = 1,running2=1,running3=1,transition=0, i=2,running4=0,running5=1,running6=1,running9=1,collision,collision2 ;
int curseur = 0, firsttime = 0,in,s=0,position_volume=5,boolean_icon=1,quitt=0,test=1,test_s;
int tempsPrecedent = 0, tempsActuel = 0,right=0,left=0,etat=0,saut=0,r,alea,enigme=0,valeur_vie=0,running7=1,firsttime1=0,compteurr  ;
int right_ennemi=0,left_ennemi=0,seconde=0 ,temp_prec=0,temp_actu=0,score_finale=1000,collision3=0;
int suivileft= 0, suiviright=1,temp_actu1=0,temp_prec1=0;
int controller1,mouse1,keyboard1,choose1,enablefast=0,enigme2=0,running10=1 ;  

float D,curseur_perso=0,compteur=4,running8=1 ;
Coordinate C ;
char image [20] ;
 char temps[20] = ""; 
  char score[20] = ""; 
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255,255,255 }; 
 int save =0 ;
/*    SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init(); */
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }

  screen = SDL_SetVideoMode(width,height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF /* |SDL_FULLSCREEN */  );
  
/*   if(police)
  fprintf(f,"%d",1) ;
  else 
   fprintf(f,"%d",2) ;

   fclose(f) ; */

  load_transition(tab ) ;
  init_enigme(&e) ;
  

  initialiser (&newgame,&loadgame ,&settings,&icon,&in_sound ,&in_sound25,&in_sound50,&in_sound75,&in_sound100,&in_settings,&credits,&main_menu ,&quitter,&wexit,&nwexit ,&exxit,&game,&map,&wood,&boat,tabD,tabG,ennemi,ennemiD,vie,&mask,&keyboard,&mouse,&controller,&choose,S.level) ;

  music_back = Mix_LoadMUS("soundtrack-jumanji-welcome-to-the-jungle-theme-song-epic-music-2017-musique-film-jumanji.wav");
  effect= Mix_LoadWAV("son1.wav");
  Mix_PlayMusic(music_back,-1) ;
  // Mix_PlayChannel(1,effect,0);
  
  position.x=1368-320 ;
  position.y=10 ;
  position2.x=1368-320 ;
  position2.y=60 ;


  setup (screen ,&game,&icon) ;
  SDL_EnableKeyRepeat(100, 100);
  while(running)
  {
  
   in=deplacementmenu_up_down(screen,event ,&firsttime,&curseur,&running,newgame,loadgame,settings ,quitter,&icon,in_settings,effect,&boolean_icon,&quitt,exxit,tab,&transition,&save) ;
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
   if(transition)
   {   
     firsttime1=0 ;
     running4=1 ;
    SDL_EnableKeyRepeat(100,100);
    while(running4){
                 

                  if (i<=189)   
                   { 
                     tempsActuel = SDL_GetTicks();
                      if (tempsActuel - tempsPrecedent > 50)
                         {
                           update_transition(screen ,tab,&i) ;
                           tempsPrecedent = tempsActuel;

                         }
                      else 
                         {
                           SDL_Delay(50 - (tempsActuel - tempsPrecedent));
                         }
                   }
             if ((i)==189)
             {
               running4=0 ;
               running=0 ;
             }
    }
   }
    if(save==1)
    {
      FILE *f=fopen("save_file","r") ;
      fscanf(f,"%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %d %d %d %d \n",&(S.map_pos.x),&(S.map_pos.y),&(S.perso_pos.x),&(S.perso_pos.y),&(S.ennemi_pos.x),&(S.ennemi_pos.y),&(S.box_pos.x),&(S.box_pos.y),&(S.pos.x),&(S.pos.y),&(S.valeur_vie),&(S.score_finale),&(S.seconde),&(S.level)) ; 
      fclose(f) ;
      running=0 ;
    }         
  }
  liberate (&newgame,&loadgame ,&settings,&icon,&in_sound ,&in_sound25,&in_sound50,&in_sound75,&in_sound100,&in_settings,&credits,&main_menu ,&quitter,&wexit,&nwexit ,&exxit,&game) ;
 FILE *file=fopen("txt","a") ;
 fprintf(file,"%d",save) ;
 fprintf(file,"level=%d  seconde=%d",S.level,S.seconde) ;
 
 S.level=1 ;
 if(save==1)
 {
  if(S.level==1)  
  S=level1(save,S) ;
  if(S.level==2)
  S=stage2(save,S) ;
  if(S.level==3)
  S=chapter3 (save,S) ; 
  else if(S.level >3 || S.level <1)
  {
    S=level1(save,S) ;
  if(S.level==2)
  S=stage2(save,S) ;
  if(S.level==3)
  S=chapter3 (save,S) ;
  }
  
 }
  else if(save==0)
  {
  fprintf(file,"\nsave=%d\n",save) ;  
  fclose(file) ;
  S=level1(save,S) ;
  if(S.level==2)
  S=stage2(save,S) ;
  if(S.level==3)
  S=chapter3 (save,S)  ;
  }

 
  sauvgarder.img=IMG_Load("Quit.png");
  sauvgarder.pos.x=0 ;
  sauvgarder.pos.y=0 ; 
  
   running3= 1 ;
  while(running3 || i!=3){
  // SDL_BlitSurface(mini_map.img,NULL,screen,&(mini_map.pos));      
    SDL_BlitSurface(sauvgarder.img,NULL,screen,&(sauvgarder.pos)) ;
                    SDL_Flip(screen) ;
                SDL_WaitEvent(&event) ;
                        switch(event.type)
               {
                case SDL_QUIT:
                running3 = 0 ;
                break;
               
                case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                 case SDLK_ESCAPE:
                    running3=0 ;
                  break ;
                 case SDLK_RIGHT :
                  i=0 ;
                 break ; 
                 case SDLK_LEFT :
                  i=1 ;
                 break ;
                    case SDLK_RETURN :
                    if (i==1)
                    {  
                     FILE *f=fopen("save_file","w") ; 
                     fprintf(f,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d \n",S.map_pos.x,S.map_pos.y,S.perso_pos.x,S.perso_pos.y,S.ennemi_pos.x,S.ennemi_pos.y,S.box_pos.x,S.box_pos.y,S.pos.x,S.pos.y,S.valeur_vie,S.score_finale,S.seconde,S.level) ;
                     fclose(f) ;
                     running3=0 ;
                    }
                    else 
                    running3=0 ; 

                    i=3 ;
                 break ;  
                } 
               }
  
              
               /*


                 case SDLK_RETURN :
                    if (i==1)
                    {
                      
                     fprintf(f,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d \n",map.pos.x,map.pos.y,tabD[0].pos.x,tabD[0].pos.y,ennemi[0].pos.x,ennemi[0].pos.y,wood.pos.x,wood.pos.y,wood.pos.x,wood.pos.y,valeur_vie,score_finale,seconde,save) ;
                     running3=0 ;
                    }
                    else 
                    running3=0 ;
                 break ; 
                }
                break ;
               } */
  }
 
  

}