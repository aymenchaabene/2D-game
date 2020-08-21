#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

#define W_Screen 800
#define H_Screen 600


#define SPEED 5


#define SPRITE_H 96
#define SPRITE_W  111
#define MAX_FRAMES 8



           #define W_BackgImg 259
           #define H_BackgImg 194


typedef struct 
{

SDL_Rect position_entite;
SDL_Rect position_map;
SDL_Rect frame;
SDL_Rect dst;


SDL_Surface * image_entite;
SDL_Surface * spriteleft;
SDL_Surface * spriteright;

int pos_alea_max_x;
int pos_alea_min_x;

int pos_alea_max_y;
int pos_alea_min_y;

int pos_max_x;
int pos_min_x;

int pos_max_y;
int pos_min_y;



}ent;


void initialiser_entite(ent *E);

//ent animation_entite(ent E, SDL_Surface* screen,SDL_Surface* backg);
int position_aleatoire(int positionmax,int positionmin);
void deplacement_aleatoire_animation(ent E,SDL_Surface *screen,SDL_Surface* backg);













#endif /* FONCTIONS_H_ */
