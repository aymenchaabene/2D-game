#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"


int main()
{
SDL_Surface *ecran = NULL, *imageDeFond = NULL,*circle=NULL,*circle1=NULL;
int x=0,i;

    
    SDL_Rect *positionFond ;
    SDL_Rect *positioncir ;
    positionFond.x = 0;
    positionFond.y = 0;
    positionFond.h =1080;
    positionFond.w =1920;

    

    
    positioncir.x = 1920/ 2 - 100 / 2;
    positioncir.y = 1080;
     SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement Background", NULL);

    
    imageDeFond = IMG_Load("map.png");
    circle = IMG_Load("cirreau.png");

             SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                SDL_BlitSurface(circle,NULL, ecran, &positioncir);
                
    SDL_Flip(ecran);
    
 
   
    int continuer = 1;
    SDL_Event event;
    SDL_EnableKeyRepeat(10, 10);
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {

            case SDLK_RIGHT: // Flèche droite
            	
                if  (positioncir.x>=516 && positionFond.x<=5760)
        
            positionFond.x += 100;
        else if (positioncir.x<=750) 
            positioncir.x +=100;
            
       
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                SDL_BlitSurface(circle,NULL, ecran, &positioncir);
                
    SDL_Flip(ecran);

                break;

            case SDLK_LEFT: // Flèche gauche
            	if (positioncir.x<=258 && positionFond.x>=0)
        
            positionFond.x -= 100;
        
    else if (positioncir.x>=50)  
        positioncir.x -= 100;
         
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
				SDL_BlitSurface(circle,NULL, ecran, &positioncir);
                
    SDL_Flip(ecran);

                break;
              

        }

        break;    
        }

       
        
    SDL_Flip(ecran);
    }


    SDL_FreeSurface(imageDeFond); 
    SDL_Quit();

    return EXIT_SUCCESS;
}
