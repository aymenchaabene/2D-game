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
Objet newgame,loadgame,settings,icon,in_sound,in_sound25,in_sound50,in_sound75,in_sound100, ennemi [7], ennemiD [7],vie [6] ;
Objet in_settings,credits,main_menu,quitter,wexit,nwexit,exxit,game,map,box,boat,e,en,mask ;
SDL_Event event, event2;
Mix_Music  *music_back=NULL;
Objet tab [190],tabD[20],tabG[20] ;
 Mix_Chunk *effect ;
 FILE *f ;
 f=fopen("test.txt","a");

int running = 1,running2=1,running3=1,transition=0, i=0,running4=0,running5=1,running6=1,collision,collision2 ;
int curseur = 0, firsttime = 0,in,s=0,position_volume=5,boolean_icon=1,quitt=0,test=1,test_s;
int tempsPrecedent = 0, tempsActuel = 0,right=0,left=0,etat=0,saut=0,r,alea,enigme=0,valeur_vie=0,running7=1,firsttime1=0,compteurr  ;
int right_ennemi=0,left_ennemi=0,seconde=0 ,temp_prec=0,temp_actu=0,score_finale=100,collision3=0;
float D,curseur_perso=0,compteur=4,running8=1 ;
Coordinate C ;
char image [20] ;
 char temps[20] = ""; 
  char score[20] = ""; 
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255,255,255 };

  pos.x=0 ;
  pos.y=0 ;
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }

  screen = SDL_SetVideoMode(width,height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
  police = TTF_OpenFont("angelina.TTF", 65);
  load_transition(tab ) ;
  init_enigme(&e) ;
  initialiser (&newgame,&loadgame ,&settings,&icon,&in_sound ,&in_sound25,&in_sound50,&in_sound75,&in_sound100,&in_settings,&credits,&main_menu ,&quitter,&wexit,&nwexit ,&exxit,&game,&map,&box,&boat,tabD,tabG,ennemi,ennemiD,vie,&mask) ;

  music_back = Mix_LoadMUS("soundtrack-jumanji-welcome-to-the-jungle-theme-song-epic-music-2017-musique-film-jumanji.wav");
  effect= Mix_LoadWAV("son1.wav");
  //Mix_PlayMusic(music_back,-1) ;
  // Mix_PlayChannel(1,effect,0);
  
  position.x=1368-320 ;
  position.y=10 ;
  position2.x=1368-320 ;
  position2.y=60 ;
  

  setup (screen ,&game,&icon) ;
  SDL_EnableKeyRepeat(100, 100);
  while(running)
  {
   in=deplacementmenu_up_down(screen,event ,&firsttime,&curseur,&running,newgame,loadgame,settings ,quitter,&icon,in_settings,effect,&boolean_icon,&quitt,exxit,tab,&transition) ;
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
   {    tempsActuel = SDL_GetTicks();
   sprintf(temps, "Time : %d", seconde);
   sprintf(score, "Score: %d", score_finale);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche) ;
    gestion_score=TTF_RenderText_Blended(police, temps, couleurBlanche) ; 
     firsttime1=0 ;
     running4=1 ;
     SDL_EnableKeyRepeat(10, 10);
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
               i=190 ;
               screen = SDL_SetVideoMode(width,height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
              renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,pos ) ;
              
             }
             if ((i)==190)



             {

 
             //scrolling (screen ,&boat,&box,&map,&running4  ) ;
          if(map.pos.x<=0 )
         {
               
           curseur_perso=deplacement_objet(tabD,&map,&box,&running4,&curseur_perso,&right,&left,&saut,ennemi,&mask) ;
          if(tabD[0].pos.x>=500)
          {
           pos=tabD[0].pos ; 
           curseur_perso=evenement (screen ,&boat ,&box,&map,&running4,&right,&left,&curseur_perso,ennemi,&mask) ;

          }
         }

          else if(map.pos.x>=mapw-1368)
          {
           
             curseur_perso=deplacement_objet(tabD,&map,&box,&running4,&curseur_perso,&right,&left,&saut,ennemi,&mask) ;
            if(tabD[0].pos.x<=500)
            {
              curseur_perso=evenement (screen ,&boat ,&box,&map,&running4,&right,&left,&curseur_perso,ennemi,&mask) ;
            }
          } 
        else
          {             
            curseur_perso=evenement (screen ,&boat ,&box,&map,&running4,&right,&left,&curseur_perso,ennemi,&mask ) ;
             
          } 
            deplacement_ennemi(ennemi,&compteur,&right_ennemi,&left_ennemi) ;
                      
                    
                    if (left)
                    {
                        tempsActuel = SDL_GetTicks();
                   if (tempsActuel - tempsPrecedent >= 100) 
        {
            compteurr += 100; 
            if(compteurr % 1000==0)
             seconde+=1 ;
            sprintf(temps, "Temps : %d", seconde); 
              if(compteurr % 1000==0)
              {
                seconde+=1 ;
                         if(seconde %10==0)
               score_finale-=10 ;
              }
            sprintf(score, "Score: %d", score_finale);
            SDL_FreeSurface(texte); 
            SDL_FreeSurface(gestion_score);   
            gestion_score=TTF_RenderText_Blended(police, score, couleurBlanche) ; 
            texte = TTF_RenderText_Blended(police, temps, couleurBlanche); 
            tempsPrecedent = tempsActuel; 
        }
                       renderG (screen,&map ,NULL,tabD,tabG,&curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,pos ) ;                        
                    }
                    else 
                    {
                                                  tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100) 
        {
            compteurr += 100; 
              if(compteurr % 1000==0)
              {
                seconde+=1 ;
                         if(seconde %10==0)
               score_finale-=10 ;
              }
            sprintf(temps, "Temps : %d", seconde); 

            sprintf(score, "Score: %d", score_finale);
            SDL_FreeSurface(texte); 
            SDL_FreeSurface(gestion_score);   
            gestion_score=TTF_RenderText_Blended(police,score, couleurBlanche) ; 
            texte = TTF_RenderText_Blended(police, temps, couleurBlanche); 
            tempsPrecedent = tempsActuel; 

        }
                    renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,pos ) ;
                    }


       
        
             
                    
             calculer_centre_rayon (&box,tabD) ;
             D=calculer_distance (&box,tabD) ;
             collision=verif_collision (&box,tabD,D ) ;
             collision2=collisionBB(tabD,ennemi) ;

             C.X=pos.x+20 ;
             C.Y=pos.y+(tabD[0].img->h /2) ;
             
             collision3=Collision_Parfaite(mask.img,C) ;
             
              if(collision3)
              {
                running8=1 ;
                while(running8){
                SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
                SDL_Flip(screen) ;
                SDL_WaitEvent(&event) ;
                        switch(event.type)
              {
                case SDL_QUIT:
                running8 = 0 ;
                break;
                case SDL_KEYDOWN :
              switch(event.key.keysym.sym)
               {
                 case SDLK_ESCAPE:
                    running8=0 ;
                  break ;
               }
               break ;
              }
               }
              }
                if(collision2 && firsttime1==0)
                {
                  firsttime1=1 ;
                  gestion_vie(vie,&valeur_vie,tabD) ;
                    score_finale-=50 ;

                }
                
                   if(collision && enigme==0)
                    { 
                        enigme=1 ;
		                    running6=1,r=0 ;	
                        renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,pos ) ;
                         
                        generate_afficher ( screen  , image ,&e,&alea) ;
                        s=solution_e (image );
                        do{
                          running6 = 1;
                          SDL_BlitSurface(map.img,&(map.pos),screen,NULL) ;
                          SDL_BlitSurface(e.img,NULL,screen,&(e.pos)) ;
                          SDL_Flip(screen) ;
			                   do{
			                      r=resolution (&running5,&running6);
			                     }while((r>3 || r<1) && running5!=0) ;
                            afficher_resultat (screen,s,r,&en) ;
                           while(running6)
                          {  
				                    
			                      SDL_WaitEvent(&event);
                            switch(event.type)
                            {
					                   case SDL_QUIT :
                             running5 =0 ;
					                	 running6=0 ;
					                   break ;
                             case SDL_KEYDOWN :
						    
                              switch( event.key.keysym.sym )
                                 {
			                            case  SDLK_RETURN: 
                                       running6=0 ;

              			              break ;
                                  case SDLK_SPACE:
                                       running6=0;
                                  break;
			                          }
						                break ;
                           }
			                   }            
                         if(r!=s)
                           score_finale-=50 ;
                         else 
                           score_finale+=500 ;
                        
                        }while(r!=s) ;
                    
                     
                    }
                    else
                    {
                      
                   if(right)
                    {
                      renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,pos ) ;                     
                    }
                  else if (left)
                    {

                      renderG (screen,&map ,NULL,tabD,tabG,&curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,pos ) ; 
                      
                    } 
                    else 
                    {

                    renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,pos )  ;   
                    }
                    }
                      
                   SDL_Flip(screen); 
                   if(valeur_vie==4 || score_finale<=0)
                   {
                     while(running7){
                      renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,pos )  ; 
                      //SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
                      SDL_BlitSurface (vie[4].img,NULL,screen,&(vie[4].pos)) ;
                      SDL_Flip(screen) ;
                       SDL_WaitEvent(&event) ;
                               switch(event.type)
                                 { 
                                   case SDL_KEYDOWN:

                                    switch(event.key.keysym.sym)

                                       {
                                          case SDLK_ESCAPE:
                                              running7 = 0;
                                              running4= 0 ;
                                          break ; 
                                        }
                                    break ;
                                 }
                                     }
                  
                    
                   }
                  }
    }//fin running4
     SDL_EnableKeyRepeat(100, 100);
   }//fin if transition

  }//fin running
      TTF_CloseFont(police);
    TTF_Quit();
  fclose(f) ;
  liberate (&newgame,&loadgame ,&settings,&icon,&in_sound ,&in_sound25,&in_sound50,&in_sound75,&in_sound100,&in_settings,&credits,&main_menu ,&quitter,&wexit,&nwexit ,&exxit,&game) ;
  SDL_Quit( ) ;


}