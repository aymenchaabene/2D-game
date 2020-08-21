#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


int main (   )
{
    int continuer=1 ;
    SDL_Surface *ecran=NULL,*detective=NULL,*sapin ;
    SDL_Rect positiondetective,positinsapin ;
    SDL_Event event ;



    SDL_Init(SDL_INIT_VIDEO) ;
   

    ecran=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF) ;

  
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_WM_SetCaption("deplacement image",NULL) ;




    detective=IMG_Load ("detective.png");
    sapin=IMG_Load("sapin.png") ;
    /* On centre detective à l'écran */
    positiondetective.x = ecran->w / 2 - detective->w / 2;
    positiondetective.y = ecran->h / 2 - detective->h / 2;
    positinsapin.x = ecran->w / 2 - sapin->w / 2;
    positinsapin.y = ecran->h / 2 - sapin->h / 2;
    

    SDL_BlitSurface(detective,NULL,ecran,&positiondetective);
    SDL_BlitSurface(sapin,NULL,ecran,&positinsapin);
    
        while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
         case SDL_MOUSEBUTTONUP:
             if(event.button.button==SDL_BUTTON_LEFT)
              {
              positiondetective.x = event.button.x;
             positiondetective.y = event.button.y;
              }
              else if (event.button.button==SDL_BUTTON_RIGHT)
              continuer=0 ;

              break ;


        }

        /* On efface l'écran */
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        /* On place detective à sa nouvelle position */
        SDL_BlitSurface(detective, NULL, ecran, &positiondetective);
        SDL_BlitSurface(sapin,NULL,ecran,&positinsapin);
        /* On met à jour l'affichage */
        SDL_Flip(ecran);
    }






    SDL_FreeSurface(detective);
    SDL_FreeSurface(sapin);
    SDL_Quit();
    return 0;
}


