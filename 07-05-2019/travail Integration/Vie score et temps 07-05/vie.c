/**
* @file vie.c
* @brief Vie du perso 
* @author Unisix
* @version 0.1
* @date May 07, 2019
*
* Gestion et Affichage de vie
*
*/
#include "Vie Score Temps.h"
/**
 * @brief  Gestion de vie 
 * @param  int *valeur_vie le nombre de coeur 
 * @param  Objet tabD le tableau du déplacement perso
 * @param  Objet vie 
 * @return nothing
*/
void gestion_vie(Objet vie [],int *valeur_vie,Objet tabD [])
{
  if(*valeur_vie<4)
  (*valeur_vie)++ ;

  tabD[0].pos.x+=40;
  
}
/**
 * @brief  Affichage de vie 
 * @param  int *valeur_vie le nombre de coeur 
 * @param  Objet vie[]
 * @return nothing
*/
void affiche_vie(SDL_Surface *screen , Objet vie [] ,int valeur_vie)
{
  if(valeur_vie<4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[0].pos)) ;
  SDL_Flip(screen) ;
  }
  if(valeur_vie==4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[4].pos)) ;
  SDL_Flip(screen) ;
  }

}