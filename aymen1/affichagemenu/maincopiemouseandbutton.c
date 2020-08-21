#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"

#define w 1213
#define h 760

#define n_w 385
#define n_h 55

#define s_w 295
#define s_h 55

#define e_w 180
#define e_h 55

SDL_Surface *screen = NULL, *background = NULL, *newgame = NULL, *loadgame = NULL, *settings = NULL, *quitter = NULL;
SDL_Rect position, posback, pos_new, pos_load, pos_settings, pos_quitter;
SDL_Event event, event2;
Mix_Music *music, *music;
int i = 0, firsttime = 0;

int main()
{
  int running = 1;
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
  quitter=IMG_Load("exit.png");


  pos_new.x = 425;
  pos_new.y = 295;

  pos_load.x = 425;
  pos_load.y = 375;

  pos_settings.x = 475;
  pos_settings.y = 450;

  pos_quitter.x = 530;
  pos_quitter.y = 535;

  position.x = 0;
  position.y = 0;
  posback.x = 0;
  posback.y = 0;
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }
  music = Mix_LoadMUS("Kingdom Hearts Sound Effects  Cursor Move.mp3");
  Mix_PlayMusic(music,1) ;

  FILE *f = fopen("test.txt", "a");
  fprintf(f, "test");
  SDL_EnableKeyRepeat(100, 100);
  while (running)
  {
    SDL_WaitEvent(&event);
    switch (event.type)
    {
    case SDL_MOUSEMOTION:

      if (event.motion.x > pos_new.x && event.motion.x < (n_w + pos_new.x) && event.motion.y > pos_new.y && event.motion.y < (n_h + pos_new.y))
      {

        i = 1;
        SDL_FreeSurface(background);
        background = IMG_Load("newgame.png");
         Mix_PlayMusic(music,1) ;
        
      }
      if (event.motion.x > pos_load.x && event.motion.x < (n_w + pos_load.x) && event.motion.y > pos_load.y && event.motion.y < (n_h + pos_load.y))
      {

        i = 2;
        SDL_FreeSurface(background);
        background = IMG_Load("loadgame.png");
         Mix_PlayMusic(music,1) ;
        
      }
      if (event.motion.x > pos_settings.x && event.motion.x < (s_w + pos_settings.x) && event.motion.y > pos_settings.y && event.motion.y < (s_h + pos_settings.y))
      {

        i = 3;
        SDL_FreeSurface(background);
        background = IMG_Load("settings.png");
         Mix_PlayMusic(music,1) ;

        
      }
      if (event.motion.x > pos_quitter.x && event.motion.x < (e_w + pos_quitter.x) && event.motion.y > pos_quitter.y && event.motion.y < (e_h + pos_quitter.y))
      {

        i = 4;
        SDL_FreeSurface(background);
        background = IMG_Load("exit.png");
         Mix_PlayMusic(music,1) ;
        
      }

      break;
    case SDL_QUIT:
      running = 0;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
      case SDLK_DOWN:

        fprintf(f, "%d :\n", i);
        i++;
        if (i < 5)
        {

          switch (i)
          {
          case 1:
            SDL_FreeSurface(background);
            background = IMG_Load("newgame.png");
             Mix_PlayMusic(music,1) ;

            break;
          case 2:
            SDL_FreeSurface(background);
            background = IMG_Load("loadgame.png");
             Mix_PlayMusic(music,1) ;

            break;
          case 3:
            SDL_FreeSurface(background);
            background = IMG_Load("settings.png");
             Mix_PlayMusic(music,1) ;

            break;
          case 4:
            SDL_FreeSurface(background);
            background = IMG_Load("exit.png");
             Mix_PlayMusic(music,1) ;

            break;
          }
        }
        else if (i == 5)
        {
          SDL_FreeSurface(background);
          background = IMG_Load("newgame.png");
           Mix_PlayMusic(music,1) ;

          i = 1;
        }
        fprintf(f, "%d :\n", i);

        break;
      case SDLK_UP:
        if (i == 0 && firsttime == 0)
        {
          background = IMG_Load("newgame.png");
           Mix_PlayMusic(music,1) ;

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
              SDL_FreeSurface(background);
              background = IMG_Load("newgame.png");
               Mix_PlayMusic(music,1) ;

              break;
            case 2:
              SDL_FreeSurface(background);
              background = IMG_Load("loadgame.png");
               Mix_PlayMusic(music,1) ;

              break;
            case 3:
              SDL_FreeSurface(background);
              background = IMG_Load("settings.png");
               Mix_PlayMusic(music,1) ;

              break;
            case 4:
              SDL_FreeSurface(background);
              background = IMG_Load("exit.png");
               Mix_PlayMusic(music,1) ;

              break;
            }
          }
          else if (i == 0)
          {
            SDL_FreeSurface(background);
            background = IMG_Load("exit.png");
             Mix_PlayMusic(music,1) ;

            i = 4;
          }
        }
        break;
        break;
      }
    }

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(background, NULL, screen, &posback);
     SDL_FillRect(newgame, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  SDL_FillRect(loadgame, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  SDL_FillRect(settings, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  SDL_FillRect(quitter, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  
    SDL_Flip(screen);
    
  }
  SDL_FreeSurface(background);
  SDL_FreeSurface(screen);
  Mix_FreeMusic(music);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
