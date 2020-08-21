/**
*@file sprite.c
*@author morsi
*@version 1.0
*@date 23/4/2019
*/
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sprite.h"
/**
*@brief init player
*@param p player
*@param screen l'ecran 
*
*/
void init(Player *p, SDL_Surface **screen){
	p->image = IMG_Load("ss.png");
	p->image2 = IMG_Load("ss2.png");
	p->position.x = 5;
	p->position.y = 0;
	
	for (int i = 0; i < 5; i++ ){
		p->clips[i].x = 846-141 -i*141;
		p->clips[i].y = 0;
		p->clips[i].w = 141;
		p->clips[i].h = 249;
	}
	for (int i = 0; i < 5; i++ ){
		p->clips2[i].x =i*141 ;
		p->clips2[i].y = 0;
		p->clips2[i].w = 141;
		p->clips2[i].h = 249;
	}
	
	p->screen = screen;
	
	p->frame = 0;
}

void render(Player *p,FILE **f){
	
	
	if(p->vx >=0){
		SDL_BlitSurface(p->image,&p->clips[(int) p->frame],*p->screen,&p->position);
	}else
	if(p->vx <0)
	{
		SDL_BlitSurface(p->image2,&p->clips2[(int) p->frame],*p->screen,&p->position);

	}

	if(p->vx != 0)
	{
		p->frame += 0.1f;
		if(p->frame >5) 
		p->frame = 1;
		
		p->position.x +=p->vx;
	}else
	{
		p->frame = 0;
	}
	p->vy += 0.2;
	p->position.y +=(int)p->vy;
		
	if(p->position.y + 249 > 500){
		p->position.y =500-249;
		p->vy = 0;
	}
	fprintf(*f,"pos y: %d  vel y : %f vel x : %d \n",p->position.y,p->vy,p->vx) ;	
	
}



