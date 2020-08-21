#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>

/**
* @file jeux.h
*/
SDL_Surface* Init_imagedefond( SDL_Surface *imagedefond ,SDL_Rect *image ,  int x , int y) ;
void Show_imagedefond (SDL_Surface *imagedefond , SDL_Surface *screen ,  SDL_Rect image  ) ;


#endif // JEU_H_INCLUDED
