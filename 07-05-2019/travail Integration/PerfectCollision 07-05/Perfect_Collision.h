#ifndef PERFECT_COLLISION_H_DEFINED
#define PERFECT_COLLISION_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

/**
* @struct Coordinate
* @brief struct pour les coordonnées du perso 
*/
typedef struct 
{

int X;
int Y;

}Coordinate;


int Collision_Parfaite();
//SDL_Color GetPixel(SDL_Surface *background ,Coordinate C);
Uint32 getpixel(SDL_Surface *surface,Coordinate C);


#endif
