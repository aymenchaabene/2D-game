/**
* @file Sauvegarde.c
* @brief Saving the game
* @author Unisix
* @version 0.1
* @date Apr 23, 2019
*
* Saving the game 
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"


/**
 * @brief  prendre x et y 
 * @param  int x l'abscisse de la position du personnage
 * @param  int y l'ordonné de la position du personnage
 * @param  char nomficher[] le fichier
 * @return nothing
*/
void fichier(char nomfichier[],int *x,  short int *y , int *running)
{
FILE*f=NULL;

f=fopen(nomfichier,"w+");

                    if ((f != NULL )||(*running==0))
        {
            fprintf(f,"%d ;%d",*x,*y);


        }
fclose(f);
        }

/** 
 * @brief  Enregistrer dans un fichier x et y 
 * @param  int x l'abscisse de la position du personnage
 * @param  int y l'ordonné de la position du personnage
 * @param  char nomficher[] le fichier
 * @return nothing 
*/
 void extraire(char nomfichier[],int *x, short int *y )
 {
 FILE*f=NULL;

f=fopen(nomfichier,"r");
if(f!=NULL)
{
fscanf(f,"%d ; %hd", x , y ) ;

}
fclose(f);
 }
