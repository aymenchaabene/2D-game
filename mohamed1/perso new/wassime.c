#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main (int argc, char **argv)
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *perso[13] = {NULL};
    SDL_Event event;
    SDL_Rect positionperso;
    int i = 0, continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(900, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Animation", NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    perso[0] = IMG_Load("0.png");
    perso[1] = IMG_Load("1.png");
    perso[2] = IMG_Load("2.png");
    perso[3] = IMG_Load("3.png");
    perso[4] = IMG_Load("4.png");
    perso[5] = IMG_Load("5.png");
    perso[6] = IMG_Load("6.png");
    perso[7] = IMG_Load("7.png");
    perso[8] = IMG_Load("8.png");
    perso[9] = IMG_Load("9.png");
    perso[10] = IMG_Load("10.png");
    perso[11] =IMG_Load ("11.png");
    perso[12] =IMG_Load ("12.png");
    perso[13] =IMG_Load ("13.png");

     

    positionperso.x = 0;
    positionperso.y = 0;
    SDL_BlitSurface(perso[i], NULL, ecran, &positionperso);
    SDL_EnableKeyRepeat(100,100);
    while(continuer)
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
                case SDLK_LEFT:
                if(i >= 13)
                i = 0;
                positionperso.x -= 20;
                i++; 
                break;

                case SDLK_RIGHT:
                if(i >= 13)
                i = 0;
                positionperso.x += 20;
                i++;
                break;
                  
                case SDLK_DOWN:
                if(i >= 13)
                i = 0;
                positionperso.y += 20;
                i++;
                break;
             
                case SDLK_UP:
                if(i >= 13)
                i = 0;
                positionperso.y -= 20;
                i++;
                break;
}


               


                


            

        
      




        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(perso[i], NULL, ecran, &positionperso);
        SDL_Flip(ecran);
    
}
}


    for(i = 0; i < 2; i++)
    SDL_FreeSurface(perso[i]);
    SDL_Quit();

    return EXIT_SUCCESS;
}


