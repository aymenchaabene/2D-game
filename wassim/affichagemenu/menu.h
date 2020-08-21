#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"


#define width 1366
#define height 768

#define n_w 185
#define n_h 27

#define s_w 145
#define s_h 35

#define e_w 90
#define e_h 30

#define sound_w 55
#define sound_h 55

#define i_s_w 225 //insound surface width
#define i_s_h 30  //insound surface high

#define yn_w 117    //yes or no width 
#define yn_h 50    //yes or no high

#define mp_w 40  //+ et - width
#define mp_h 40  //+et - high 

#define mapw 8000 
#define maph 768

#define xwood 900
#define ywood 360

#define xboat 50
#define yboat 400

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


void initialiser (Objet *newgame,Objet *loadgame ,Objet *settings,Objet *y_icon,Objet *in_sound ,Objet *in_sound25,Objet *in_sound50,Objet *in_sound75,Objet *in_sound100,Objet *in_settings,Objet *credits,Objet *main_menu ,Objet *quitter,Objet *wexit,Objet *nwexit ,Objet *exxit,Objet *game,Objet *map,Objet *wood,Objet *boat) ;
void setup (SDL_Surface *screen ,Objet *game,Objet *y_icon) ;
int verif_motion_surface (SDL_Event event,Objet surface) ;
void update (SDL_Surface *screen , Objet *surface1,Objet *surface2) ;
void liberate (Objet *newgame,Objet *loadgame ,Objet *settings,Objet *y_icon,Objet *in_sound ,Objet *in_sound25,Objet *in_sound50,Objet *in_sound75,Objet *in_sound100,Objet *in_settings,Objet *credits,Objet *main_menu ,Objet *quitter,Objet *wexit,Objet *nwexit ,Objet *exxit,Objet *game) ;
void clic_souris_menu_principale (SDL_Surface *screen,SDL_Event event, int curseur ,Objet newgame,Objet loadgame,Objet settings,Objet in_settings,Objet *icon,Objet quitter,int *in,int *running,int *boolean_icon,int *quitt,Objet exxit,Objet tab [],int *transition) ;
void clic_entrer_menu_principale (SDL_Surface *screen ,Objet in_settings,Objet icon,Mix_Chunk *effect, int curseur,int *in,int *running,int *quitt,Objet exxit ) ;
void mouse_motion_main_menu (SDL_Surface *screen ,SDL_Event event,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *quitt ) ;
void deplacementmenu_down (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *quitt ) ;
void deplacementmenu_up (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *firsttime,int *quitt) ;
int  deplacementmenu_up_down(SDL_Surface *screen, SDL_Event event ,int *firsttime,int *curseur,int *running,Objet newgame,Objet loadgame,Objet settings ,Objet quitter ,Objet *icon,Objet game , Mix_Chunk *effect,int *boolean_icon,int *quitt,Objet exxit,Objet tab [],int *transition ) ;
void deplacement__sousmenu_down (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume,Objet icon,Objet credits,Objet main_menu) ;
void deplacement__sousmenu_up (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume,Objet icon,Objet credits,Objet main_menu,int *firsttime) ;
void update_volume_surface(SDL_Surface *screen,Mix_Chunk *effect,Objet in_sound ,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume) ;
void motion_souris_sousmenu (SDL_Surface *screen ,SDL_Event event , Mix_Chunk *effect,int *curseur,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume,Objet icon,Objet credits,Objet main_menu) ;
void clic_souris_sousmenu (SDL_Surface *screen,Objet *icon, SDL_Event event,int curseur,Objet in_sound,Objet credits, Objet main_menu,int *running2,Objet game,int *boolean_icon);
void clic_entrer_sousmenu (SDL_Surface *screen,Objet icon, int *running2,int curseur,Objet game) ;
void deplacement_droit_gauche_volume (SDL_Surface *screen,Mix_Chunk *effect,Objet in_sound ,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int *position_volume) ;
void deplacement_sous_menu (SDL_Surface *screen ,Mix_Chunk *effect,SDL_Event event , int *running2,Objet in_settings,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int *position_volume,Objet credits,Objet main_menu,Objet *icon, int *running,int *curseur,int *firsttime,Objet game,int *boolean_icon ) ;
void quitter_oui_non(SDL_Surface *screen ,SDL_Event event,int *running,int *running2,int *running3,Objet quitter,Objet icon,Objet wexit,Objet nwexit,int *test,int *test_s);
void load_transition(Objet tab [] ) ;
void update_transition(SDL_Surface *screen ,Objet tab [],int *i) ;
void affichage_objet (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map) ;
void scrolling_droit (SDL_Surface *screen , Objet *map) ;
void scrolling_gauche (SDL_Surface*screen , Objet *map) ;
void scrolling (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,int *running4  ) ;
void calculer_centre_rayon (Objet *objet1,Objet *objet2) ;
float calculer_distance (Objet *objet1,Objet *objet2)  ;
int verif_collision ( Objet *objet1,Objet *objet2,float D1 ) ;
void deplacement_objet(Objet *objet,Objet *map,Objet *wood,int *running) ;
