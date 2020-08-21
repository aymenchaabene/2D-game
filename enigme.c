#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
//#include "enig.h"

int generatin_aleatoire(int nbalea)
{
srand(time(NULL));
nbalea=1+rand()%5;
return nbalea;
}


void resolution_enigme(char image[20])
{
char solution[20]="s";
strcat(solution,image);
strcpy(image,solution);
SDL_Surface *fenetreenigme=NULL,*enigme=NULL;
SDL_Rect positionenigme;
    positionenigme.x = 0;
    positionenigme.y = 0;
fenetreenigme = SDL_SetVideoMode(701, 698, 32, SDL_HWSURFACE);
enigme = IMG_Load(image);
SDL_BlitSurface(enigme, NULL, fenetreenigme, &positionenigme);
SDL_Flip(fenetreenigme);
}
