#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"fonction.h"

void setrects_up(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=0;
clip[0].w=100;
clip[0].h=100;

clip[1].x=100;
clip[1].y=0;
clip[1].w=100;
clip[1].h=100;

clip[2].x=200;
clip[2].y=0;
clip[2].w=100;
clip[2].h=100;

clip[3].x=300;
clip[3].y=0;
clip[3].w=100;
clip[3].h=100;

clip[4].x=400;
clip[4].y=0;
clip[4].w=100;
clip[4].h=100;

clip[5].x=500;
clip[5].y=0;
clip[5].w=100;
clip[5].h=100;

}
void setrects_right(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=100;
clip[0].w=100;
clip[0].h=100;

clip[1].x=100;
clip[1].y=100;
clip[1].w=100;
clip[1].h=100;

clip[2].x=200;
clip[2].y=100;
clip[2].w=100;
clip[2].h=100;

clip[3].x=300;
clip[3].y=100;
clip[3].w=100;
clip[3].h=100;

clip[4].x=400;
clip[4].y=100;
clip[4].w=100;
clip[4].h=100;

clip[5].x=500;
clip[5].y=100;
clip[5].w=100;
clip[5].h=100;

}
void setrects_down(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=200;
clip[0].w=100;
clip[0].h=100;

clip[1].x=100;
clip[1].y=200;
clip[1].w=100;
clip[1].h=100;

clip[2].x=200;
clip[2].y=200;
clip[2].w=100;
clip[2].h=100;

clip[3].x=300;
clip[3].y=200;
clip[3].w=100;
clip[3].h=100;

clip[4].x=400;
clip[4].y=200;
clip[4].w=100;
clip[4].h=100;

clip[5].x=500;
clip[5].y=200;
clip[5].w=100;
clip[5].h=100;

}
void setrects_left(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=300;
clip[0].w=100;
clip[0].h=100;

clip[1].x=100;
clip[1].y=300;
clip[1].w=100;
clip[1].h=100;

clip[2].x=200;
clip[2].y=300;
clip[2].w=100;
clip[2].h=100;

clip[3].x=300;
clip[3].y=300;
clip[3].w=100;
clip[3].h=100;

clip[4].x=400;
clip[4].y=300;
clip[4].w=100;
clip[4].h=100;

clip[5].x=500;
clip[5].y=300;
clip[5].w=100;
clip[5].h=100;

}

void animation(acteur *acteur){
int tempsPrecedent = 0, tempsActuel = 0;
char temps[20];
SDL_Init(SDL_INIT_VIDEO);
acteur->screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
acteur->frame=0;
acteur->running=1;
acteur->image=IMG_Load("image.png");
SDL_FillRect(acteur->screen,&acteur->screen->clip_rect,0x00);
acteur->rect.x=200;
acteur->rect.y=100;
SDL_EnableKeyRepeat(100,100);

while (acteur->running)
    {
       		 SDL_PollEvent(&acteur->event);    
			switch(acteur->event.type)
			{
				case SDL_QUIT:
					acteur->running = 0;
					break;
		}

            
                 do
                    {				 
   tempsActuel = SDL_GetTicks();
   if (tempsActuel - tempsPrecedent >100){
                        acteur->rect.x=20+acteur->rect.x;
   setrects_right(acteur->rects);
  acteur->frame++;
  if(acteur->frame==5){
  acteur->frame=0;
  }	
  tempsPrecedent = tempsActuel;
  }
  SDL_FillRect(acteur->screen, NULL, SDL_MapRGB(acteur->screen->format, 0, 0, 0));
  SDL_BlitSurface(acteur->image,&acteur->rects[acteur->frame],acteur->screen,&acteur->rect);
  SDL_Flip(acteur->screen) ;
					}while(acteur->rect.x<=500);
					
					do
                    {

tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >100){
                        acteur->rect.x=-20+acteur->rect.x;
setrects_left(acteur->rects);
acteur->frame++;
if(acteur->frame==5){
acteur->frame=0	;
}
tempsPrecedent = tempsActuel;
}
SDL_FillRect(acteur->screen, NULL, SDL_MapRGB(acteur->screen->format, 0, 0, 0));
SDL_BlitSurface(acteur->image,&acteur->rects[acteur->frame],acteur->screen,&acteur->rect);
SDL_Flip(acteur->screen);

					}while(acteur->rect.x!=0);
                
                


}

}
