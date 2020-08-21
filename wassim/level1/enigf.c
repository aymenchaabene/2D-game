#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "menu.h"

void init_enigme(Objet * e)
{
	e->pos.x=0;
	e->pos.y=0;	
	e->img=NULL;

}

 void generate_afficher (SDL_Surface * screen  , char image [],Objet *e,int *alea)
{ 
	int test=*alea ;
    srand(time(NULL));
do{
 *alea = 1+ rand()%6;
}while(*alea==test) ;
 sprintf(image ,"%d.png",*alea);
e->img = IMG_Load(image);

}
 
 int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"1.png")==0)
 	{
     		solution =1 ;
 	}
 	else  	if(strcmp(image,"2.png")==0)
 	{
 		solution =1;

 	}
 	else 	if(strcmp(image,"3.png")==0)
 	{
 		solution =3;	
 	}
	else  	if(strcmp(image,"4.png")==0)
 	{
 		solution =3;

 	}
 	else 	if(strcmp(image,"5.png")==0)
 	{
 		solution =3;	
 	}
	else  	if(strcmp(image,"6.png")==0)
 	{
 		solution =3;

 	}
 	

 	return solution;
 }

int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			   r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e: 
			   r=3 ;
			   break;
		          
			    }
       break ;

                 
	}
  return r ;
}
 
 void afficher_resultat (SDL_Surface * screen,int s,int r,Objet *en)
 {
 
 	if (r==s)
 	{
 		en->img=IMG_Load("00.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->pos)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
 		en->img=IMG_Load("11.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->pos)) ;
        SDL_Flip(screen);
 	}
 }
 
