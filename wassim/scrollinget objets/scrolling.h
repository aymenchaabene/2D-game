#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define w 1360
#define h 560

#define mapw 6838 
#define maph 613

#define xwood 300
#define ywood 360

#define xboat 50
#define yboat 400

typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos ; 

}Objet;



void initialiser (Objet *map ,Objet *wood ,Objet *boat )  ;
void setup (SDL_Surface *screen, Objet *map ,Objet *wood, Objet *boat) ;
void affichage_objet (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map) ;
void scrolling_droit (SDL_Surface *screen , Objet *map) ;
void scrolling_gauche (SDL_Surface*screen , Objet *map) ;
void evenement (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,int *running  ) ;
void free_memory (Objet *boat ,Objet *wood,Objet *map) ;