#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void initialiser_enigme(int *x1,int *y1,int *x2,int *y2,int *x3,int *y3);
int generatin_aleatoire(int nbalea);
void afficher_enigme(char image[20]);
void resolution_enigme(char image[20]);
