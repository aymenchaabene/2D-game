#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

 void pause() ;
int main ( int argc, char** argv  )
{
    int continuer=1 ;
    SDL_Surface *ecran=NULL,*zozor=NULL,*sapin ;
    SDL_Rect positionZozor,positinsapin ;
    SDL_Event event ;



    SDL_Init(SDL_INIT_VIDEO) ;
   

    ecran=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF) ;

  
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_WM_SetCaption("deplacement image",NULL) ;




    zozor=IMG_Load ("detective.png");
    sapin=IMG_Load("sapin.png") ;
    
    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;
        positinsapin.x = ecran->w / 2 - sapin->w / 2;
    positinsapin.y = ecran->h / 2 - sapin->h / 2;
    SDL_SetColorKey(zozor,SDL_SRCCOLORKEY,SDL_MapRGB(ecran->format,0,0,255));

    SDL_BlitSurface(zozor,NULL,ecran,&positionZozor);
    SDL_BlitSurface(sapin,NULL,ecran,&positinsapin);
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
                    case SDLK_UP: // Flèche haut
                        positionZozor.y--;
                        break;
                    case SDLK_DOWN: // Flèche bas
                        positionZozor.y++;
                        break;
                    case SDLK_RIGHT: // Flèche droite
                        positionZozor.x++;
                        break;
                    case SDLK_LEFT: // Flèche gauche
                        positionZozor.x--;
                        break;
                }
                break;

         case SDL_MOUSEBUTTONUP:
             if(event.button.button==SDL_BUTTON_LEFT)
              {
              positionZozor.x = event.button.x;
             positionZozor.y = event.button.y;
              }
              else if (event.button.button==SDL_BUTTON_RIGHT)
              continuer=0 ;

              break ;



        }

       
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
        SDL_BlitSurface(sapin,NULL,ecran,&positinsapin);
        
        SDL_Flip(ecran);
    }

 SDL_BlitSurface(sapin,NULL,ecran,&positinsapin);
 SDL_Flip(ecran);



    SDL_FreeSurface(zozor);
    SDL_FreeSurface(sapin);
    SDL_Quit();
    return 0;
}
void pause()
{
 int continuer = 1 ;
 SDL_Event event ;

 while(continuer)
  {
   SDL_WaitEvent(&event) ;
   switch(event.type)
   {
    case SDL_QUIT :
        continuer=0 ;
        break ;
   }
  }
}
