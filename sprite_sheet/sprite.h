/**
*@file sprite.h
*@struct Player 
*/
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct Player{

	int x,y,vx;
	float vy;
	SDL_Surface **screen,*image, *image2;
	SDL_Rect position;/*!<position rectangle*/
	SDL_Rect clips[9];/*!<tableau sprite droite*/
	SDL_Rect clips2[9];/*!<tableau sprite gauche*/
	float frame;/*!<position rect animation*/
} Player;

void init(Player *p, SDL_Surface **screen);
void render(Player *p,FILE **f);


