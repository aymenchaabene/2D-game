#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define w 1360
#define h 500

#define mapw 6838 
#define maph 613

#define xwood 300
#define ywood 200

#define xboat 1150
#define yboat 200

typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos ; 

}Objet;



void initialiser (Objet *map ,Objet *wood ,Objet *boat,Objet *perso ) ;
void setup (SDL_Surface *screen, Objet *map ,Objet *wood, Objet *boat,Objet *perso) ;
void affichage_objet (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,Objet *perso) ;
void scrolling_droit (SDL_Surface *screen , Objet *map) ;
void scrolling_gauche (SDL_Surface*screen , Objet *map) ;
void evenement (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,int *running ,Objet *perso ) ;
void free_memory (Objet *boat ,Objet *wood,Objet *map) ;
