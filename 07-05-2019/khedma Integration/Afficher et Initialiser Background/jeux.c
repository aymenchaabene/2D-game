/**
 * @file jeux.c
 */ 
#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jeux.h"
/**
 * @brief  load image de fond
 * @param  SDL_Surface *imagedefond
 * @param  SDL_Rect *image
 * @param  int x
 * @param  int y
 * @return imagedefond
*/
SDL_Surface * Init_imagedefond( SDL_Surface *imagedefond ,SDL_Rect *image ,  int x , int y) 
 {
	       imagedefond =  IMG_Load("map.png"); 

	      if  ( imagedefond ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     else 
     {
 
     image->x  =  x ; 
     image->y  = y ;
     image->h= imagedefond->h ;
     image->w= imagedefond->w ;  
 }
     
     return (imagedefond) ; 
}

