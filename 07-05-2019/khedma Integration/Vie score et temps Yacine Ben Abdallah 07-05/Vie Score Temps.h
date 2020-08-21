
/**
* @struct Coordinate
* @brief struct pour coordonnées
*/
typedef struct 
{

int X;
int Y;

}Coordinate;

/**
* @struct Circle
* @brief struct le circle
*/
typedef struct 
{
  int x ;
  int y ;
  float rayon ;

}Circle;

/**
* @struct Objet	
* @brief struct pour Objet
*/
typedef struct 
{

  SDL_Surface *img ;
  SDL_Rect pos ;
  Circle c ;
  SDL_Rect pos_text ;
  
}Objet ;

void gestion_vie(Objet vie [],int *valeur_vie,Objet tabD []) ;
float deplacement_objet(Objet tab[],Objet *map,Objet *wood,int *running,float *curseur_perso,int *right,int *left,int *saut,Objet ennemi [],Objet *mask) ;
void affiche_vie(SDL_Surface *screen , Objet vie [] ,int valeur_vie) ;

