/**
* @file main.c
* @brief main pour vie
* @author Unisix
* @version 0.1
* @date may 07, 2019
*
* gestion de vie 
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"fonction.h"
int main(){
int vie= 3;
gestion_vie(vie);
return 0;
}
