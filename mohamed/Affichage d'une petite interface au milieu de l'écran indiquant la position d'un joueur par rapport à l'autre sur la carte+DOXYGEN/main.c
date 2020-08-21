#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 20, 2019
*
* Testing program for Display of a small interface in the middle of the screen indicating the position of a player relative to the other in the Map
*
*
*/

int main(int argc, char *argv[])
{
SDL_Event event;
 
int run=1;

 
    SDL_Surface *ecran = NULL, *imageDeFond = NULL ,*detective =NULL, *imageDeFond1 = NULL ,*detective1 =NULL;;

    SDL_Rect positionFond;
    SDL_Rect positionFond1;
SDL_Rect positiondetective;
SDL_Rect positiondetective1;
   
 
    ecran = SDL_SetVideoMode(1300, 400, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("", NULL);
//INITI
positionFond.x =1200;
    positionFond.y =350 ;
positiondetective.x = 1200;
    positiondetective.y =370;

positionFond1.x =0;
    positionFond1.y =0 ;
positiondetective1.x = 100;
    positiondetective1.y =0;
    SDL_Init(SDL_INIT_VIDEO);


   
    imageDeFond = SDL_LoadBMP("background.bmp");
    imageDeFond1 = SDL_LoadBMP("Flat_Game_Background_1.bmp");
detective = IMG_Load("detective.png");
detective1 = IMG_Load("1.png");
SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond1);
   SDL_BlitSurface(detective1, NULL, ecran, &positiondetective1);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
   SDL_BlitSurface(detective, NULL, ecran, &positiondetective);
 


    SDL_Flip(ecran);
 while(run)
{


while (SDL_PollEvent(&event))
       {//while event
 switch(event.type)
        {//switch event
            case SDL_QUIT:
		{// case sdl quit
            run = 0;
            
		}
case SDL_KEYDOWN:
                {
 switch (event.key.keysym.sym)
            {
				case SDLK_RIGHT:
				{
positiondetective.x+=25;
positiondetective1.x+= 300;
SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond1);
SDL_BlitSurface(detective1, NULL, ecran, &positiondetective1);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
SDL_BlitSurface(detective, NULL, ecran, &positiondetective);
  


    SDL_Flip(ecran);

}
                                 case SDLK_LEFT:
{

 positiondetective.x-=20;
positiondetective1.x-=250;
 

SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond1);
SDL_BlitSurface(detective1, NULL, ecran, &positiondetective1);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
SDL_BlitSurface(detective, NULL, ecran, &positiondetective);


    SDL_Flip(ecran);
}
}


}
}

}
}

    SDL_FreeSurface(imageDeFond);
SDL_FreeSurface(detective);
 SDL_FreeSurface(imageDeFond1);
SDL_FreeSurface(detective1);
    SDL_Quit();

    return EXIT_SUCCESS;
}
