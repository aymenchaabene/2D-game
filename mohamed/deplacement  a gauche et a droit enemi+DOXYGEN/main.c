#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 20, 2019
*
* Testing program for move enemy left and right
*
*/


int main(int argc, char *argv[])
{

    SDL_Surface *fond = NULL, *pelouse = NULL, *vache = NULL;
    SDL_Rect positionPelouse, positionVache;
    int continuer = 1, droite = 1;
    SDL_Event event;
 

    SDL_Init(SDL_INIT_VIDEO);
  

    fond = SDL_SetVideoMode(1280,640,32,SDL_HWSURFACE);
    pelouse = SDL_LoadBMP("Flat_Game_Background_1.bmp");
    vache = SDL_LoadBMP("robot.bmp");

    SDL_SetColorKey(vache, SDL_SRCCOLORKEY,SDL_MapRGB(vache->format,0,0,255));
 

    SDL_WM_SetCaption("Mouvement",NULL);
 

    SDL_FillRect(fond,NULL,SDL_MapRGB(fond->format,255,0,0));
 

    positionPelouse.x = 0;
    positionPelouse.y = 0;
    positionVache.x = 720;
    positionVache.y = 415;
 

    SDL_BlitSurface(pelouse,NULL,fond,&positionPelouse);
    SDL_BlitSurface(vache,NULL,fond,&positionVache);
 

    while(continuer) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT :
                continuer = 0;
                 break;   
        }
   
        if (positionVache.x > 900) droite = 0;
        if (positionVache.x <= 600) droite = 1;
   

        if (droite) positionVache.x=positionVache.x+2;
        else positionVache.x=positionVache.x-5;
   
        SDL_Delay(10); 
        SDL_FillRect(fond,NULL,SDL_MapRGB(fond->format,255,255,255));
        SDL_BlitSurface(pelouse,NULL,fond,&positionPelouse);
        SDL_BlitSurface(vache,NULL,fond,&positionVache); 

        SDL_Flip(fond);
    }
 

    SDL_FreeSurface(pelouse); 
    SDL_FreeSurface(vache);
    SDL_Quit();
 
    return EXIT_SUCCESS;
 
}

