/**
 @file Perfect_Collision.c
*/ 
#include "Perfect_Collision.h"


/**
 * @brief  SDL_Surface *mask Mask for the map  
 * @param  Coordinate C
 * @return Collision
*/
int Collision_Parfaite(SDL_Surface *mask,Coordinate C)
{int collision=0;
SDL_Color color ;


SDL_GetRGB(getpixel(Background,C),Background->format,&color.r,&color.g,&color.b);
/* detection de la couleur rose en arriere plan */
if (color.r==183 && color.g==41 && color.b==183)
{collision=1;}

return collision;

}


Uint32 getpixel(SDL_Surface *surface,Coordinate C)
{
    int bpp = surface->format->BytesPerPixel;

    Uint8 *p = (Uint8 *)surface->pixels + C.Y * surface->pitch + C.X * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;
    }
}
