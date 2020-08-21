#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sprite.h"

SDL_Surface *screen,*back;
int running = 1,a=0,jump=0;

Player p;


void gameLoop() {
	FILE *f=fopen("test","w") ;
	
while(running)
{
	

                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = 0;
                                        break;
                                
				case SDL_KEYDOWN:
				    if(event.key.keysym.sym==SDLK_ESCAPE)
				    running = 0;
                    if(event.key.keysym.sym==SDLK_LSHIFT)
                    {
                    if(p.vx == 5 )
                    {
					    p.vx += 4;
					}
					else
					if(p.vx ==-5 )
                    {
					    p.vx -= 4;
					}
					else
					p.vx=0;
					}    
					if(event.key.keysym.sym==SDLK_RIGHT)
					if((p.position.y==500-249) || (p.position.y!=500-249 && p.vx >= 0))
					    p.vx = 5;
					if(event.key.keysym.sym==SDLK_LEFT)
					if((p.position.y==500-249) || (p.position.y!=500-249 && p.vx <= 0))
						p.vx = -5;
				    if(p.position.y==500-249)
				    jump=0;
					if(event.key.keysym.sym==SDLK_UP)
					{
						if(jump ==0 && p.position.y==500-249)
						{
							p.vy = -8;
						    jump=1 ;
						} 
						else
						if(jump ==1)
					{
						p.vy = -8;
						jump =0 ;
					}
						
					}
					if(event.key.keysym.sym==SDLK_DOWN)
					p.vy = 10;
				break;
				case SDL_KEYUP:
				    if(event.key.keysym.sym==SDLK_LSHIFT)
                    {
                    if(p.vx ==9)
                    {
					    p.vx -= 4;
					}
					else
					if(p.vx == -9)
                    {
					    p.vx += 4;
					}
					else
					break;
					} 
					
					if(event.key.keysym.sym==SDLK_RIGHT)
					{
					if(p.position.y==500-249)
					{
					  if(p.vx > 0)
				        p.vx = 0;
					
				    }
					else
					{
						a=1;
						
					}
				    }
				    
				   
				      
					if(event.key.keysym.sym==SDLK_LEFT)
				    {
					if(p.position.y==500-249)
					{
					  if(p.vx < 0)
				        p.vx = 0;
					
				    }
					else
					{
						
						a=1;
					}
				    }
						
					
				break;
						}
					}
					 if(a==1 && p.position.y==500-249)
				    {
						
				        p.vx = 0;
						a=0;
				    }

//image et position du background

SDL_BlitSurface(back,960,560,screen,NULL);


// dessine l'image couper selon le rectangle clip a la position du rectangle position
render(&p,&f);

// redessine l'ecran
SDL_Flip(screen);

//SDL_Delay(16);

}
fclose(f) ;
}

int main()
{

SDL_Init(SDL_INIT_EVERYTHING);
screen=SDL_SetVideoMode(1920,560,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN );
back=IMG_Load("back.png");
init(&p,&screen);
gameLoop();
SDL_Quit();

return 0;
}
