#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
  int x ;
  int y ;
  float rayon ;

}Circle;

typedef struct 
{

  SDL_Surface *img ;
  SDL_Rect pos ;
  Circle c ;
  SDL_Rect pos_text ;
  
}Objet ;

void initialiser (Objet tab []) ;
void deplacement_objet(SDL_Surface *screen , Objet tab [],int *running) ;