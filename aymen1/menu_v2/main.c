#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"

#define w 1213 // pos background
#define h 760    //

#define n_w 385  //pos load_newgame image 
#define n_h 55    //

#define s_w 295   // pos settings 
#define s_h 55      //

#define e_w 180  //pos exit
#define e_h 55     //

#define sound_w 55 //pos icon sound en haut a gauche
#define sound_h 55  //

#define i_s_w 500 //insound surface width
#define i_s_h 80  //insound surface high

#define yn_w 384    //yes or no width 
#define yn_h 151    //yes or no high

#define mp_w 40  //+ et - width
#define mp_h 40  //+et - high 



SDL_Surface *screen = NULL, *background = NULL, *newgame = NULL, *loadgame = NULL, *settings = NULL, *quitter = NULL,*sound=NULL ;
SDL_Surface *in_settings=NULL,*in_sound=NULL,*credits=NULL,*main_menu=NULL,*in_sound25=NULL,*in_sound50=NULL,*in_sound75=NULL,*in_sound100=NULL ;
SDL_Surface *wexit=NULL,*nwexit=NULL,*exxit=NULL ;
SDL_Rect position, posback, pos_new, pos_load, pos_settings, pos_quitter,pos_sound,pos_insound,pos_credits,pos_main_menu;
SDL_Rect pos_yes , pos_no,pos_moins,pos_plus ;
SDL_Event event, event2;
Mix_Music  *music,*music2;


int main()
{
  int running = 1,running2=1,running3=1;
  int i = 0, firsttime = 0,in,s=0,fleche=1;

  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen == NULL)
  {
    printf("unable to load screen=%s\n", SDL_GetError());
    return 1;
  }

  background = IMG_Load("game.png");

  if (background == NULL)
  {
    printf("unable to load image =%s\n", SDL_GetError());
    return 1;
  }

/*   newgame=SDL_CreateRGBSurface(SDL_HWSURFACE,n_w,n_h,32,0,0,0,0) ;
  loadgame=SDL_CreateRGBSurface(SDL_HWSURFACE,n_w,n_h,32,0,0,0,0) ;
  settings=SDL_CreateRGBSurface(SDL_HWSURFACE,s_w,s_h,32,0,0,0,0) ;
  quitter=SDL_CreateRGBSurface(SDL_HWSURFACE,e_w,e_h,32,0,0,0,0) ;

  SDL_FillRect(newgame, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  SDL_FillRect(loadgame, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  SDL_FillRect(settings, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  SDL_FillRect(quitter, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); */

  newgame=IMG_Load("newgame.png");
  loadgame=IMG_Load("loadgame.png");
  settings=IMG_Load("settings.png");
  sound=IMG_Load("yes.png");
  in_sound=IMG_Load("asound0.png");
  in_sound25=IMG_Load("asound25.png");
  in_sound50=IMG_Load("asound50.png") ;
  in_sound75=IMG_Load("asound75.png") ;
  in_sound100=IMG_Load("asound100.png");
  in_settings=IMG_Load("settings2.png") ;
  credits=IMG_Load("credits.png") ;
  main_menu=IMG_Load("main_menu.png");
  quitter=IMG_Load("exit.png");
  wexit=IMG_Load("ywexit.png") ;
  nwexit=IMG_Load("nwexit.png") ;
  exxit=IMG_Load("wexit.png") ;

 
  pos_new.x = 425;
  pos_new.y = 295;

  pos_load.x = 425;
  pos_load.y = 375;

  pos_settings.x = 475;
  pos_settings.y = 450;

  pos_sound.x=20 ;
  pos_sound.y=50 ;

  pos_quitter.x = 530;
  pos_quitter.y = 535;

  pos_insound.x=345 ;
  pos_insound.y=250 ;

  pos_credits.x=345 ;
  pos_credits.y=355 ;
  
  pos_main_menu.x=345 ;
  pos_main_menu.y=470 ;

  pos_yes.x=997 ;
  pos_yes.y=704 ;

  pos_no.x=549 ;
  pos_no.y=704 ;
  
  pos_moins.x=570 ;
  pos_moins.y=286 ;

  pos_plus.x=1027 ;
  pos_plus.y=268 ;


  posback.x = 0;
  posback.y = 0;
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }
  
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }
  music2 = Mix_LoadMUS("soundtrack-jumanji-welcome-to-the-jungle-theme-song-epic-music-2017-musique-film-jumanji.wav"); //music de fond
  Mix_PlayMusic(music2,-1) ;
  
  Mix_Chunk *music;
  music = Mix_LoadWAV("son1.wav"); //effet sonore
  


  FILE *f = fopen("test.txt", "a"); //fichier pour tester le code
  fprintf(f, "test");
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(background, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);
    SDL_Flip(screen);
  SDL_EnableKeyRepeat(100, 100); //activer le clic continure du fleche
  while (running)
  {
    SDL_WaitEvent(&event);
    switch (event.type)
    {
      case SDL_MOUSEBUTTONDOWN: 
       if (event.button.button == SDL_BUTTON_LEFT && i==4 ) // clic gauche souris avec la position du curseur en exit
       {
           SDL_BlitSurface(wexit, NULL, screen, &posback);
           SDL_Flip(screen);
          while(running3) // debuter un boucle infinie dans un boucle infinie 
          {
           SDL_PollEvent(&event);
            switch (event.type)
               {
                  case SDL_QUIT: // quitter le programme
                  running3=0 ;
                  running=0 ;
                  break ;
                  case SDL_MOUSEMOTION: //bliter un image lorsque le curseur de la souris dans cette conditon
                  if (event.motion.x > pos_no.x && event.motion.x < (yn_w + pos_no.x) && event.motion.y > pos_no.y && event.motion.y < (yn_h + pos_no.y))
                             {
                               SDL_BlitSurface(nwexit, NULL, screen, &posback); 
                               SDL_Flip(screen);

                             }
                    if (event.motion.x > pos_yes.x && event.motion.x < (yn_w + pos_yes.x) && event.motion.y > pos_yes.y && event.motion.y < (yn_h + pos_yes.y))
                             {
                               SDL_BlitSurface(wexit, NULL, screen, &posback); 
                               SDL_Flip(screen);

                             }           
                             

                     
                  break ;
                  case SDL_KEYDOWN: // echap por quitter
                      switch (event.key.keysym.sym)
                        {
                           case SDLK_ESCAPE:
                               running3=0 ;
                               running=0 ;
                                break ;
                        }
                } 
          }
          
           }
       else if (event.button.button == SDL_BUTTON_LEFT && in==1 ) // clic gauche de souris et le curseur  se trouve dans l icon de spon
       {
         if(s==0)  // si son activé le desactive
         {
            
            SDL_BlitSurface(background, NULL, screen, &posback);
            SDL_FreeSurface(sound);
            sound=IMG_Load("no.png");
            SDL_BlitSurface(sound, NULL, screen, &pos_sound);
       
            SDL_Flip(screen);
            s=1 ;
            in=0 ;
         }
         else if(s==1) //si son desactivé  l'active
         {
            
            SDL_BlitSurface(background, NULL, screen, &posback);
            SDL_FreeSurface(sound);
            sound=IMG_Load("yes.png");
            Mix_PauseMusic();
            SDL_BlitSurface(sound, NULL, screen, &pos_sound);
       
            SDL_Flip(screen);
            s=0 ;
            in=0 ;
         }

       }
       else if (event.button.button == SDL_BUTTON_LEFT && i==3 ) //clic gauche souris avec la position du curseur en settings
       {

            SDL_BlitSurface(in_settings, NULL, screen, &posback);
            SDL_Flip(screen);
            i=0;
            running2=1 ;
            while(running2) //entrer dans le sous menu de settings et debuter le boucle infinie
            {
              
               SDL_WaitEvent(&event);
                switch (event.type)
                 {
                      case SDL_MOUSEMOTION: 
      
                          if (event.motion.x > pos_insound.x && event.motion.x < (i_s_w + pos_insound.x) && event.motion.y > pos_insound.y && event.motion.y < (i_s_h + pos_insound.y))
                             {
                                if(i==1)
                                 {
                                   break ;
                                 }
                                   else
                                 {
                                   i=1 ;
                                   if(fleche==1)
                                   {
                                   SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                   }
                                   else if (fleche==2)
                                   {
                                     SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                   }
                                   else if (fleche==3)
                                   {
                                     SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                   }
                                   else if (fleche==4)
                                   {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                   }
                                   if (fleche>4)
                                    {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback); 
                                    }
                                    if (fleche<1)
                                    {
                                     SDL_BlitSurface(in_sound, NULL, screen, &posback); 
                                    }

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                                }
                             }
                           if (event.motion.x > pos_credits.x && event.motion.x < (i_s_w + pos_credits.x) && event.motion.y > pos_credits.y && event.motion.y < (i_s_h + pos_credits.y))
                             {
                                if(i==2)
                                  {
                                    break ;
                                  }
                                     else
                                  {
                               i=2 ; 
                               SDL_BlitSurface(credits, NULL, screen, &posback);
                                

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                                  } 
                             }
                             if (event.motion.x > pos_main_menu.x && event.motion.x < (i_s_w + pos_main_menu.x) && event.motion.y > pos_main_menu.y && event.motion.y < (i_s_h + pos_main_menu.y))
                             {
                                if(i==3)
                                 {
                                   break ;
                                 }
                                     else
                                 {
                               i=3 ;
                               SDL_BlitSurface(main_menu, NULL, screen, &posback);
                                

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0); 
                                 }
                             }
                              break ;
                      case SDL_MOUSEBUTTONDOWN:
                           if (event.button.button == SDL_BUTTON_LEFT && i==3 )
                            {
                              SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                              SDL_BlitSurface(background, NULL, screen, &posback);
                              sound=IMG_Load("yes.png");
                              SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                              SDL_Flip(screen);
                              running2=0 ;
                            }

                          break ;
                      case SDL_QUIT:
                      running2= 0;
                      running=0 ;
                         break;
                     case SDL_KEYDOWN:
                      switch (event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE:
                               running3=0 ;
                               running=0 ;
                                break ;
                          case SDLK_RIGHT :
                             fleche ++ ;
                             if(fleche>5)
                             fleche=1 ;
                            if(fleche<5)
                            {
                             switch (fleche)
                             {
                               case 1 :
                                  SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                  
                                  SDL_Flip(screen);
                                 break;
                             
                               case 2:
                                SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                  
                                  SDL_Flip(screen);
                                 break;
                                 case 3:
                                  SDL_BlitSurface(in_sound75, NULL, screen, &posback);
                                  
                                  SDL_Flip(screen);
                                 break ;
                                 case 4 :
                                  SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                  
                                  SDL_Flip(screen);
                                  break ;
                             }

                            }
                            break ;
                            case SDLK_LEFT:
                        
                            if(fleche!=4)
                            {
                            fleche-- ;
                              if(fleche>5)
                             fleche=3 ;
                            if(fleche<5)
                            {
                             switch (fleche)
                             {
                               case 1 :
                                  SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                  
                                  SDL_Flip(screen);
                                 break;
                             
                               case 2:
                                SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                  
                                  SDL_Flip(screen);
                                 break;
                                 case 3:
                                  SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                  
                                  SDL_Flip(screen);
                                 break ;
                                 
                             }

                            }
                            }

                            break ;
                          case SDLK_SPACE:
                          if(i==3)
                           {
                            
                              SDL_BlitSurface(background, NULL, screen, &posback);
                              SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                              SDL_Flip(screen);
                              running2=0 ;
                           }
                           break ;
                          case SDLK_DOWN :
                           i++ ;
                           if(i < 4)
                           {
                             switch(i)
                             {
                               case 1 :
                                 if(fleche==1)
                                   {
                                   SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                   }
                                   else if (fleche==2)
                                   {
                                     SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                   }
                                   else if (fleche==3)
                                   {
                                     SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                   }
                                   else if (fleche==4)
                                   {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                   }
                                   if (fleche>4)
                                    {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback); 
                                    }
                                    if (fleche<1)
                                    {
                                     SDL_BlitSurface(in_sound, NULL, screen, &posback); 
                                    }
                                

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                               break ;
                               case 2 :
                                SDL_BlitSurface(credits, NULL, screen, &posback);

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                               break ;
                               case 3 :
                                SDL_BlitSurface(main_menu, NULL, screen, &posback);
                                

                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                               break ;

                             }
                           }
                           if(i==4)
                           {
                                SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                                i=1 ;
                           }
                          break ;
                          case SDLK_UP :
                          if (i == 0 && firsttime == 0)
                                {
                                  
                                   if(fleche==1)
                                   {
                                   SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                   }
                                   else if (fleche==2)
                                   {
                                     SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                   }
                                   else if (fleche==3)
                                   {
                                     SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                   }
                                   else if (fleche==4)
                                   {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                   }
                                   if (fleche>4)
                                    {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback); 
                                    }
                                    if (fleche<1)
                                    {
                                     SDL_BlitSurface(in_sound, NULL, screen, &posback); 
                                    }
                                  

                                  SDL_Flip(screen);
                                 Mix_PlayChannel(1, music,0);

                                  i = 1;
                                  firsttime = 1;
                                }
                              else
                               {
                                  i--;
                             if (i != 0)
                                  {

                                    switch (i)
                                      {
                                        case 1:
                                          
                                   if(fleche==1)
                                   {
                                   SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                   }
                                   else if (fleche==2)
                                   {
                                     SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                   }
                                   else if (fleche==3)
                                   {
                                     SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                   }
                                   else if (fleche==4)
                                   {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                   }
                                   if (fleche>4)
                                    {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback); 
                                    }
                                    if (fleche<1)
                                    {
                                     SDL_BlitSurface(in_sound, NULL, screen, &posback); 
                                    }
                                             

                                              SDL_Flip(screen);
                                          Mix_PlayChannel(1, music,0);

                                          break;
                                        case 2:
                                         
                                         SDL_BlitSurface(credits, NULL, screen, &posback);
                                         

                                       SDL_Flip(screen);
                                      Mix_PlayChannel(1, music,0);

                                          break;
                                          case 3:
                                            
                                            SDL_BlitSurface(main_menu, NULL, screen, &posback);
                                            

                                            SDL_Flip(screen);
                                           Mix_PlayChannel(1, music,0);

              break;
            
            }
          }
          else if (i == 0)
          {
                
              SDL_BlitSurface(main_menu, NULL, screen, &posback);
    

              SDL_Flip(screen);
            Mix_PlayChannel(1, music,0);
            
            i = 3;
          }
        }
        break;

                        }
                     break ;
                          
                 }
            
            }
       }
       break ;
    case SDL_MOUSEMOTION:
      
       if (event.motion.x > pos_sound.x && event.motion.x < (sound_w + pos_sound.x) && event.motion.y > pos_sound.y && event.motion.y < (sound_h + pos_sound.y))
      {
        in=1 ;
      }
    
      if (event.motion.x > pos_new.x && event.motion.x < (n_w + pos_new.x) && event.motion.y > pos_new.y && event.motion.y < (n_h + pos_new.y))
      {
        if(i==1)
        {
          break ;
        }
        else
        {
           i = 1;
       
       SDL_BlitSurface(newgame, NULL, screen, &posback);
       SDL_BlitSurface(sound, NULL, screen, &pos_sound);
       
       SDL_Flip(screen);
        Mix_PlayChannel(1, music,0);   
        }
        
       
        
      }
      if (event.motion.x > pos_load.x && event.motion.x < (n_w + pos_load.x) && event.motion.y > pos_load.y && event.motion.y < (n_h + pos_load.y))
      {
         if(i==2)
        {
          break ;
        }
        else
        {
        i = 2;
        
    SDL_BlitSurface(loadgame, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);

       SDL_Flip(screen);
        Mix_PlayChannel(1, music,0);
        }
      }
      if (event.motion.x > pos_settings.x && event.motion.x < (s_w + pos_settings.x) && event.motion.y > pos_settings.y && event.motion.y < (s_h + pos_settings.y))
      {
         if(i==3)
        {
          break ;
        }
        else
        {
        i = 3;
       
       SDL_BlitSurface(settings, NULL, screen, &posback);
       SDL_BlitSurface(sound, NULL, screen, &pos_sound);

        SDL_Flip(screen);
        Mix_PlayChannel(1, music,0);
        }
        
      }
      if (event.motion.x > pos_quitter.x && event.motion.x < (e_w + pos_quitter.x) && event.motion.y > pos_quitter.y && event.motion.y < (e_h + pos_quitter.y))
      {
         if(i==4)
        {
          break ;
        }
        else
        {
        i = 4;
        
    SDL_BlitSurface(quitter, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);

    SDL_Flip(screen);
        Mix_PlayChannel(1, music,0);
        }
      }

      break;
    case SDL_QUIT:
      running = 0;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
         case SDLK_ESCAPE:
                               
                               running=0 ;
                                break ;
      case SDLK_SPACE:
       if(i==4)
       {
         running=0 ;
       }
         if (event.button.button == SDL_BUTTON_LEFT && i==3 )
       {
         SDL_BlitSurface(in_settings, NULL, screen, &posback);
            SDL_Flip(screen);
            i=0;
            running2=1 ;
            while(running2)
            {
              
               SDL_WaitEvent(&event);
                switch (event.type)
                 {
                      case SDL_MOUSEMOTION:
      
                          if (event.motion.x > pos_insound.x && event.motion.x < (i_s_w + pos_insound.x) && event.motion.y > pos_insound.y && event.motion.y < (i_s_h + pos_insound.y))
                             {
                                if(i==1)
                                 {
                                   break ;
                                 }
                                   else
                                 {
                                   i=1 ;
                                   if(fleche==1)
                                   {
                                   SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                   }
                                   else if (fleche==2)
                                   {
                                     SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                   }
                                   else if (fleche==3)
                                   {
                                     SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                   }
                                   else if (fleche==4)
                                   {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                   }
                                   if (fleche>4)
                                    {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback); 
                                    }
                                    if (fleche<1)
                                    {
                                     SDL_BlitSurface(in_sound, NULL, screen, &posback); 
                                    }

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                                }
                             }
                           if (event.motion.x > pos_credits.x && event.motion.x < (i_s_w + pos_credits.x) && event.motion.y > pos_credits.y && event.motion.y < (i_s_h + pos_credits.y))
                             {
                                if(i==2)
                                  {
                                    break ;
                                  }
                                     else
                                  {
                               i=2 ; 
                               SDL_BlitSurface(credits, NULL, screen, &posback);
                                

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                                  } 
                             }
                             if (event.motion.x > pos_main_menu.x && event.motion.x < (i_s_w + pos_main_menu.x) && event.motion.y > pos_main_menu.y && event.motion.y < (i_s_h + pos_main_menu.y))
                             {
                                if(i==3)
                                 {
                                   break ;
                                 }
                                     else
                                 {
                               i=3 ;
                               SDL_BlitSurface(main_menu, NULL, screen, &posback);
                                

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0); 
                                 }
                             }
                              break ;
                      case SDL_MOUSEBUTTONDOWN:
                           if (event.button.button == SDL_BUTTON_LEFT && i==3 )
                            {
                              SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                              SDL_BlitSurface(background, NULL, screen, &posback);
                              sound=IMG_Load("yes.png");
                              SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                              SDL_Flip(screen);
                              running2=0 ;
                            }

                          break ;
                      case SDL_QUIT:
                      running2= 0;
                      running=0 ;
                         break;
                     case SDL_KEYDOWN:
                      switch (event.key.keysym.sym)
                        {
                           case SDLK_ESCAPE:
                               running3=0 ;
                               running=0 ;
                                break ;
                          case SDLK_RIGHT :
                             fleche ++ ;
                             if(fleche<1)
                             fleche=1 ;
                            if(fleche<5)
                            {
                             switch (fleche)
                             {
                               case 1 :
                                  SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                  SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                                  SDL_Flip(screen);
                                 break;
                             
                               case 2:
                                SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                  SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                                  SDL_Flip(screen);
                                 break;
                                 case 3:
                                  SDL_BlitSurface(in_sound75, NULL, screen, &posback);
                                  SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                                  SDL_Flip(screen);
                                 break ;
                                 case 4 :
                                  SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                  SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                                  SDL_Flip(screen);
                                  break ;
                             }

                            }
                            break ;
                            case SDLK_LEFT:
                            fleche-- ;
                              if(fleche>5)
                             fleche=3 ;
                            if(fleche<5)
                            {
                             switch (fleche)
                             {
                               case 1 :
                                  SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                  SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                                  SDL_Flip(screen);
                                 break;
                             
                               case 2:
                                SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                  SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                                  SDL_Flip(screen);
                                 break;
                                 case 3:
                                  SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                  SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                                  SDL_Flip(screen);
                                 break ;
                                 case 4 :
                                  SDL_BlitSurface(in_sound75, NULL, screen, &posback);
                                  SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                                  SDL_Flip(screen);
                                  break ;
                             }

                            }

                            break ;
                          case SDLK_SPACE:
                          if(i==3)
                           {
                            
                              SDL_BlitSurface(background, NULL, screen, &posback);
                              SDL_BlitSurface(sound, NULL, screen, &pos_sound);
                              SDL_Flip(screen);
                              running2=0 ;
                           }
                           break ;
                          case SDLK_DOWN :
                           i++ ;
                           if(i < 4)
                           {
                             switch(i)
                             {
                               case 1 :
                                   if(fleche==1)
                                   {
                                   SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                   }
                                   else if (fleche==2)
                                   {
                                     SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                   }
                                   else if (fleche==3)
                                   {
                                     SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                   }
                                   else if (fleche==4)
                                   {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                   }
                                   if (fleche>4)
                                    {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback); 
                                    }
                                    if (fleche<1)
                                    {
                                     SDL_BlitSurface(in_sound, NULL, screen, &posback); 
                                    }
                                

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                               break ;
                               case 2 :
                                SDL_BlitSurface(credits, NULL, screen, &posback);

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                               break ;
                               case 3 :
                                SDL_BlitSurface(main_menu, NULL, screen, &posback);
                                

                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                               break ;

                             }
                           }
                           if(i==4)
                           {
                                SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                

                                SDL_Flip(screen);
                               Mix_PlayChannel(1, music,0);
                                i=1 ;
                           }
                          break ;
                          case SDLK_UP :
                          if (i == 0 && firsttime == 0)
                                {
                                  
                                      if(fleche==1)
                                   {
                                   SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                   }
                                   else if (fleche==2)
                                   {
                                     SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                   }
                                   else if (fleche==3)
                                   {
                                     SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                   }
                                   else if (fleche==4)
                                   {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                   }
                                   if (fleche>4)
                                    {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback); 
                                    }
                                    if (fleche<1)
                                    {
                                     SDL_BlitSurface(in_sound, NULL, screen, &posback); 
                                    }
                                  

                                  SDL_Flip(screen);
                                 Mix_PlayChannel(1, music,0);

                                  i = 1;
                                  firsttime = 1;
                                }
                              else
                               {
                                  i--;
                             if (i != 0)
                                  {

                                    switch (i)
                                      {
                                        case 1:
                                    if(fleche==1)
                                   {
                                   SDL_BlitSurface(in_sound, NULL, screen, &posback);
                                   }
                                   else if (fleche==2)
                                   {
                                     SDL_BlitSurface(in_sound25, NULL, screen, &posback);
                                   }
                                   else if (fleche==3)
                                   {
                                     SDL_BlitSurface(in_sound50, NULL, screen, &posback);
                                   }
                                   else if (fleche==4)
                                   {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback);
                                   }
                                   if (fleche>4)
                                    {
                                     SDL_BlitSurface(in_sound100, NULL, screen, &posback); 
                                    }
                                    if (fleche<1)
                                    {
                                     SDL_BlitSurface(in_sound, NULL, screen, &posback); 
                                    }
                                             

                                              SDL_Flip(screen);
                                          Mix_PlayChannel(1, music,0);

                                          break;
                                        case 2:
                                         
                                         SDL_BlitSurface(credits, NULL, screen, &posback);
                                         

                                       SDL_Flip(screen);
                                      Mix_PlayChannel(1, music,0);

                                          break;
                                          case 3:
                                            
                                            SDL_BlitSurface(main_menu, NULL, screen, &posback);
                                            

                                            SDL_Flip(screen);
                                           Mix_PlayChannel(1, music,0);

              break;
            
            }
          }
          else if (i == 0)
          {
                
              SDL_BlitSurface(main_menu, NULL, screen, &posback);
    

              SDL_Flip(screen);
            Mix_PlayChannel(1, music,0);
            
            i = 3;
          }
        }
        break;

                        }
                     break ;
                          
                 }
            
            }
       }
       
       break ;
      case SDLK_DOWN:

        fprintf(f, "%d :\n", i);
        i++;
        if (i < 5)
        {

          switch (i)
          {
          case 1:
             SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
             SDL_BlitSurface(newgame, NULL, screen, &posback);
             SDL_BlitSurface(sound, NULL, screen, &pos_sound);

             SDL_Flip(screen);
            Mix_PlayChannel(1, music,0);

            break;
          case 2:
       SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(loadgame, NULL, screen, &posback);
        SDL_BlitSurface(sound, NULL, screen, &pos_sound);

    SDL_Flip(screen);
            Mix_PlayChannel(1, music,0);

            break;
          case 3:
       SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(settings, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);

    SDL_Flip(screen);
            Mix_PlayChannel(1, music,0);

            break;
          case 4:
         SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(quitter, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);

    SDL_Flip(screen);
            Mix_PlayChannel(1, music,0);

            break;
          }
        }
        else if (i == 5)
        {
          SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(newgame, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);

    SDL_Flip(screen);
          Mix_PlayChannel(1, music,0);

          i = 1;
        }
        fprintf(f, "%d :\n", i);

        break;
      case SDLK_UP:
        if (i == 0 && firsttime == 0)
        {
              SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(newgame, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);

    SDL_Flip(screen);
          Mix_PlayChannel(1, music,0);

          i = 1;
          firsttime = 1;
        }
        else
        {
          i--;
          if (i != 0)
          {

            switch (i)
            {
            case 1:
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                SDL_BlitSurface(newgame, NULL, screen, &posback);
                SDL_BlitSurface(sound, NULL, screen, &pos_sound);

                SDL_Flip(screen);
              Mix_PlayChannel(1, music,0);

              break;
            case 2:
                  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                  SDL_BlitSurface(loadgame, NULL, screen, &posback);
                  SDL_BlitSurface(sound, NULL, screen, &pos_sound);

                  SDL_Flip(screen);
                 Mix_PlayChannel(1, music,0);

              break;
            case 3:
                  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(settings, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);

    SDL_Flip(screen);
              Mix_PlayChannel(1, music,0);

              break;
            case 4:
                 SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(quitter, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);

    SDL_Flip(screen);
              Mix_PlayChannel(1, music,0);

              break;
            }
          }
          else if (i == 0)
          {
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(quitter, NULL, screen, &posback);
    SDL_BlitSurface(sound, NULL, screen, &pos_sound);

    SDL_Flip(screen);
            Mix_PlayChannel(1, music,0);
            
            i = 4;
          }
        }
        break;
        break;
      }
    }

 
    
  }
  SDL_FreeSurface(background);
  SDL_FreeSurface(screen);
  SDL_FreeSurface(newgame) ;
  SDL_FreeSurface(loadgame);
  SDL_FreeSurface(settings) ;
  SDL_FreeSurface(quitter) ;
  Mix_FreeMusic(music2);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
