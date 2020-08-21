	
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
/** 
 * @struct enigme
* @brief struct for enigmas
 */
typedef struct 
{
 SDL_Surface * img; /*!< Surface. */ 
 SDL_Rect 	p; /*!< rectangle. */ 
}enigme;

void init_enigme(enigme * e) ;
void  generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea) ;
 int solution_e2 (char image []);
int resolution1 (int * running,int *run );
int resolution2 (int * running,int *run );
void solution_e1 (char image [],float *x1,float *x2) ;
 void afficher_resultat (SDL_Surface * screen,int r2,int r1,enigme *en,float x1,float x2);
