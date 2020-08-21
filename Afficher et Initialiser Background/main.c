#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "jeux.h"

int main()
{
int continuer=1;
SDL_Surface *screen= NULL;
SDL_Surface *imagedefond =NULL;
SDL_Rect image ;
int x,y;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 if(screen==NULL){
printf("unable = %s\n",SDL_GetError());
return 1;
}
  x=0;
  y=0;
    
imagedefond=Init_imagedefond( imagedefond ,&image , x , y );

while(continuer==1)
{

SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
 Show_imagedefond (imagedefond , screen , image ) ;
SDL_Flip(screen);

}
SDL_FreeSurface(imagedefond); 
 
    SDL_Quit();
return 0;
}

