/**
* @file Score.c
* @brief Ajout du score ou enlévement
* @author Unisix
* @version 0.1
* @date May 07, 2019
*
* Score et temps
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Vie Score Temps.h"

/**
 * @brief  prendre x et y 
 * @param  int argc 
 * @param  char *argv[]
 * @return nothing
*/
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *texte = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    int continuer = 1;
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
    char score[20] = ""; 

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);


    police = TTF_OpenFont("angelina.TTF", 65);

    /* Initialisation du temps et du texte */
    tempsActuel = SDL_GetTicks();
    sprintf(score, "score : %d", compteur);
    texte = TTF_RenderText_Shaded(police, score, couleurNoire, couleurBlanche);

    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
                
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    /* 1er cas */
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100) 
        {
            compteur += 100; 
            sprintf(score, "score : %d", compteur); 
            SDL_FreeSurface(texte); 
            texte = TTF_RenderText_Shaded(police, score, couleurNoire, couleurBlanche); 
            tempsPrecedent = tempsActuel; 
        }
                else
        SDL_Delay(100-(tempsActuel - tempsPrecedent)) ;

        position.x = 180;
        position.y = 210;
        SDL_BlitSurface(texte, NULL, ecran, &position); 
        SDL_Flip(ecran);

    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();

    return EXIT_SUCCESS;
}
