#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


int main()
{
SDL_Surface *ecran = NULL, *imageDeFond = NULL,*wood=NULL,*boat=NULL;
int x=0,i;


    SDL_Rect positionFond ;
    SDL_Rect positionwood,positionboat ;
    positionFond.x = 0;
    positionFond.y = 0;
    positionFond.h =560;
    positionFond.w =1360;

    positionboat.x=50 ;
    positionboat.y=400 ;

    positionwood.x =300 ;
    positionwood.y=  360;

    
    
     SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1360, 560, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement Background", NULL);

    
    imageDeFond = IMG_Load("map.png");
    wood = IMG_Load("wood.png");
    boat = IMG_Load("boatt.png");

  SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
  SDL_BlitSurface(boat,NULL, ecran, &positionboat);
  SDL_BlitSurface(wood,NULL, ecran, &positionwood);
                
                
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
            	
                if  ( positionFond.x<=6000)
        
                       positionFond.x += 20;
                       SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                     if(positionFond.x<=4000 && positionFond.x>=3000)
                     {
                      SDL_BlitSurface(boat,NULL, ecran, &positionboat);
                      SDL_BlitSurface(wood,NULL, ecran, &positionwood);
                     }
                
                 
            
                
                SDL_Flip(ecran);

                break;

            case SDLK_LEFT: // Flèche gauche
            	if (positionFond.x>=0)
        
            positionFond.x -= 20;
        
    
         
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
				    if(positionFond.x<=4000 && positionFond.x>=3000)
                     {
                      SDL_BlitSurface(boat,NULL, ecran, &positionboat);
                      SDL_BlitSurface(wood,NULL, ecran, &positionwood);
                     }
                
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
