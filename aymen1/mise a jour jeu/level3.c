#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "menu.h"



Saving chapter3 (int save,Saving S)
{
SDL_Surface *screen = NULL,*texte = NULL,*gestion_score = NULL ;
SDL_Rect position,position2,pos;
Objet newgame,loadgame,settings,icon,in_sound,in_sound25,in_sound50,in_sound75,in_sound100, ennemi [7], ennemiD [7],vie [6] ;
Objet in_settings,credits,main_menu,quitter,wexit,nwexit,exxit,game,map,wood,boat,e,en,mask,keyboard,mouse,controller,choose,sauvgarder,mini_map ;
SDL_Event event, event2;
Mix_Music  *music_back=NULL;
Objet tabD[20],tabG[20] ;
 Mix_Chunk *effect ;

 
 

int running = 1,running2=1,running3=1,transition=0, i=0,running4=0,running5=1,running6=1,running9=1,collision,collision2 ;
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


   SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init(); 
  screen=SDL_SetVideoMode(width,height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF /* |SDL_FULLSCREEN */  );
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }

  
  police = TTF_OpenFont("angelina.TTF", 65);


  
  init_enigme(&e) ;
  init_enigme(&en) ;
  initialiser (&newgame,&loadgame ,&settings,&icon,&in_sound ,&in_sound25,&in_sound50,&in_sound75,&in_sound100,&in_settings,&credits,&main_menu ,&quitter,&wexit,&nwexit ,&exxit,&game,&map,&wood,&boat,tabD,tabG,ennemi,ennemiD,vie,&mask,&keyboard,&mouse,&controller,&choose,S.level) ;
    if(save==1)
 {
     mask.pos.x=S.map_pos.x ;
     map.pos.x=S.map_pos.x ;
     tabD[0].pos=S.perso_pos ;
     ennemi[0].pos=S.ennemi_pos ;
     wood.pos=S.box_pos ;
     pos=S.pos ;
     valeur_vie=S.valeur_vie ;
     score_finale=S.score_finale ; 
     seconde=S.seconde ;
     tabD[0].jump =0 ;
 } 
     
  //initiial (&map,&wood,&boat,tabD,tabG,ennemi,ennemiD,vie,&mask,&keyboard,&mouse,&controller,&choose,save) ;
  music_back = Mix_LoadMUS("soundtrack-jumanji-welcome-to-the-jungle-theme-song-epic-music-2017-musique-film-jumanji.wav");
  effect= Mix_LoadWAV("son1.wav");
  Mix_PlayMusic(music_back,-1) ;
  // Mix_PlayChannel(1,effect,0);
  
  position.x=1368-320 ;
  position.y=10 ;
  position2.x=1368-320 ;
  position2.y=60 ;


  
  SDL_EnableKeyRepeat(100, 100);


                renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat ) ;
                  SDL_BlitSurface(choose.img,NULL,screen,&(choose.pos));
                  SDL_BlitSurface(newgame.img,NULL,screen,&(newgame.pos));
                  SDL_Flip(screen) ;

   while(running)
  {
  


               
               
     if(save==0)
     {
              while(running9){

                SDL_WaitEvent(&event) ;
                switch(event.type)
               {
                case SDL_QUIT:
                running9 = 0 ;
                break;
                case SDL_MOUSEMOTION :

                 if(verif_motion_surface(event,controller))
                 {
                   if(controller1!=1)
                   {
                   controller1=1 ;
                   mouse1=0 ;
                   keyboard1=0 ;
                   choose1=0 ;
                   renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat) ;
                   SDL_BlitSurface(controller.img,NULL,screen,&(controller.pos));
                   }
                 }
                 else if(verif_motion_surface(event,mouse))
                 {
                   if(mouse1!=1)
                   {
                   controller1=0 ;
                   mouse1=1 ;
                   keyboard1=0 ; 
                   choose1=0 ;
              renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat) ;

                   SDL_BlitSurface(mouse.img,NULL,screen,&(mouse.pos));
                   }
                 }
                 else  if(verif_motion_surface(event,keyboard))
                 {
                    if(keyboard1!=1)
                   {
                   controller1=0 ;
                   mouse1=0 ;
                   keyboard1=1 ; 
                   choose1=0 ;
                   renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat ) ;
                   SDL_BlitSurface(keyboard.img,NULL,screen,&(keyboard.pos));
                   }
                 }
                 else
                 {
                  if(choose1!=1)
                   {
                  controller1=0 ;
                   mouse1=0 ;
                   keyboard1=0 ; 
                   choose1=1 ;
                   renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat ) ;

                   SDL_BlitSurface(choose.img,NULL,screen,&(choose.pos));
                   }
                 }

                break ;
                case SDL_MOUSEBUTTONDOWN :
                
                running9=0 ;
                break ;
                case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                 case SDLK_ESCAPE:
                    running9=0 ;
                  break ;
                }
                break ;
                
               }
               
               SDL_Flip(screen) ;
                
              }
     } 
          if(map.pos.x<=0 )
         {
             
           curseur_perso=deplacement_objet(tabD,&map,&wood,&running,&curseur_perso,&right,&left,&saut,ennemi,&mask) ;
           
          if(tabD[0].pos.x>=500)
          {
            
            tabD[0].vx=0 ;
            pos=tabD[0].pos ;
           running=evenement (&pos,&wood,&map,&enablefast ,&right,&left,&curseur_perso,ennemi,&mask,tabD) ;
                if(right)
                newgame.pos.x+=1 ;
                if(left)
                newgame.pos.x-=1 ;

          }
         }
         
          else if(map.pos.x>=mapw-1368)
          {

             curseur_perso=deplacement_objet(tabD,&map,&wood,&running,&curseur_perso,&right,&left,&saut,ennemi,&mask) ;
            if(tabD[0].pos.x<=500)
            {
              tabD[0].vx=0 ;
              pos.x -=70 ;
              running=evenement (&pos,&wood,&map,&enablefast ,&right,&left,&curseur_perso,ennemi,&mask,tabD ) ;
            	//newgame.pos.x=(float)0.32*(newgame.pos.x);

                if(right)
                newgame.pos.x+=1 ;
                if(left)
                newgame.pos.x-=1 ;

 
            }
          } 
        else
          {             
            running=evenement (&pos ,&wood,&map,&enablefast ,&right,&left,&curseur_perso,ennemi,&mask,tabD) ;
          	//newgame.pos.x=(float)0.32*(newgame.pos.x);
           	
                if(right)
                newgame.pos.x+=1 ;
                if(left)
                newgame.pos.x-=1 ;
            
          } 

             if(tabD[0].pos.x>1200)  
             {
               running=0 ;
               S.level=3 ;
             }
                                
             calculer_centre_rayon (&wood,tabD) ;
             D=calculer_distance (&wood,tabD) ;
             collision=verif_collision (&wood,tabD,D ) ;
             collision2=collisionBB(tabD,ennemi) ;
             
             C.X=pos.x+100 ;
             C.Y=pos.y +(tabD[0].img->h/2)  ;
             SDL_LockSurface(mask.img) ;
             collision3=Collision_Parfaite(mask.img,C) ;
             SDL_UnlockSurface(mask.img) ;
              if(collision3 && enigme2==0) //collision parfaite
              {
 /*                running8= 1 ;
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
                    */  tabD[0].vx=0 ;
                        enigme2=1 ;
		                    running6=1,r=0 ;	
                        renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat ) ;
                       SDL_BlitSurface(newgame.img,NULL,screen,&(newgame.pos));
                       SDL_Flip(screen) ;                         
                        generate_afficher ( screen, image ,&e,&alea) ;
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
                    
                                    
               
               renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat ) ;                     
                  SDL_BlitSurface(newgame.img,NULL,screen,&(newgame.pos));
                  SDL_Flip(screen) ;
                  
              }

                
                if(collision2  && firsttime1!=1)//ennemi collision
                { 
                  firsttime1=1 ;

                }
                   temp_prec=SDL_GetTicks();
                   temp_prec1=SDL_GetTicks();
                if(firsttime1 && temp_prec-temp_actu>10)
                {
                  temp_actu=SDL_GetTicks() ;
                  if(abs(ennemi[0].pos.x-tabD[0].pos.x)<=300)
                  {
                   if (abs(tabD[0].pos.x-ennemi[0].pos.x)<10 && temp_prec1-temp_actu1>3000 && (tabD[0].pos.y+tabD[0].img->h)>=ennemi[0].pos.y )
                   {
                     temp_actu1=SDL_GetTicks();
                     gestion_vie(vie,&valeur_vie,tabD) ;
                     score_finale-=50 ;
                   }
                   if(tabD[0].pos.x>ennemi[0].pos.x && abs(tabD[0].pos.x-ennemi[0].pos.x)>10)
                  {
                    if(compteur>=3.9)
                    compteur=0 ;
                    else
                    compteur+=0.3  ;
                           ennemi[0].pos.x+=3 ;
                           right_ennemi=1 ;
                           left_ennemi=0 ;
                  }
                   if(tabD[0].pos.x<ennemi[0].pos.x && abs(tabD[0].pos.x-ennemi[0].pos.x)>10)
                  {
                   if(compteur>=3.9)
                    compteur=0 ;
                    else
                    compteur+=0.3  ;
                           ennemi[0].pos.x-=3 ;
                           right_ennemi=0;
                           left_ennemi=1;
                  }
                  }
                   else
                  {
                    firsttime1=0 ;
                  }
                  
                }
                else if(firsttime1!=1)
                {
                  if((map.pos.x > 1368-500 && map.pos.x < (1368*2)+500 ))
                  deplacement_ennemi(ennemi,&compteur,&right_ennemi,&left_ennemi) ;
                }

                   if(collision && enigme==0)//enigme collision
                    { 
                      
                        tabD[0].vx=0 ;
                        enigme=1 ;
		                    running6=1,r=0 ;	
                        renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat ) ;
                  SDL_BlitSurface(newgame.img,NULL,screen,&(newgame.pos));
                  SDL_Flip(screen) ;
                                           
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
                   if(valeur_vie==4 || score_finale<=0)//gameover
                   {
                     while(running7){
                      renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat)  ; 
                  SDL_BlitSurface(newgame.img,NULL,screen,&(newgame.pos));
                  SDL_Flip(screen) ;
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
                                              running= 0 ;
                                          break ; 
                                        }
                                    break ;
                                 }
                                     }
                  
                    
                   }
                    if (left)
                    {
                                         suivileft=1 ;
                      suiviright=0 ;  
                        update_fonts(&tempsActuel,&tempsPrecedent,&compteurr,&seconde,temps,score,&score_finale,&texte,&gestion_score,police,couleurBlanche ) ;
                             renderG (screen,&map ,NULL,tabD,tabG,&curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat ) ;   
                                               SDL_BlitSurface(newgame.img,NULL,screen,&(newgame.pos));
                  SDL_Flip(screen) ;                     
                    }
                    else if(right)
                    {
                      suivileft=0;
                      suiviright=1 ;                      
                        update_fonts(&tempsActuel,&tempsPrecedent,&compteurr,&seconde,temps,score,&score_finale,&texte,&gestion_score,police,couleurBlanche ) ;
                       renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat ) ;
                                         SDL_BlitSurface(newgame.img,NULL,screen,&(newgame.pos));
                  SDL_Flip(screen) ;
                    }
                    else
                    {                    
                        update_fonts(&tempsActuel,&tempsPrecedent,&compteurr,&seconde,temps,score,&score_finale,&texte,&gestion_score,police,couleurBlanche ) ;
                      if(suivileft)
                          renderG (screen,&map ,NULL,tabD,tabG,&curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat) ;  
                                            SDL_BlitSurface(newgame.img,NULL,screen,&(newgame.pos));
                  SDL_Flip(screen) ;                      
                      if(suiviright)  
                          renderD (screen,&map ,NULL,tabD,curseur_perso,ennemi,compteur,right_ennemi,left_ennemi,ennemiD,vie,valeur_vie,texte,position,gestion_score,position2,&mask,&boat ) ;
                                            SDL_BlitSurface(newgame.img,NULL,screen,&(newgame.pos));
                  SDL_Flip(screen) ;
                          
                    }                   
                  
    
     
   if(running==0)
   {
    
    S.map_pos=map.pos ;
    S.perso_pos=tabD[0].pos ;
    S.ennemi_pos=ennemi[0].pos ;
    S.box_pos=wood.pos ;
    S.pos=pos ;
    S.valeur_vie=valeur_vie ;
    S.score_finale=score_finale ;
    S.seconde=seconde ;
    
   }

  }//fin running

      TTF_CloseFont(police);
    TTF_Quit();
  //fclose(f) ;
  
  
 //SDL_Quit( ) ;
 return S ;
}