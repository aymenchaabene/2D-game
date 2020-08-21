#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"


#define width 1213
#define height 760

#define n_w 385
#define n_h 55

#define s_w 295
#define s_h 55

#define e_w 180
#define e_h 55

#define sound_w 55
#define sound_h 55

#define i_s_w 500 //insound surface width
#define i_s_h 80  //insound surface high

#define yn_w 384    //yes or no width 
#define yn_h 151    //yes or no high

#define mp_w 40  //+ et - width
#define mp_h 40  //+et - high 


typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos ;
  SDL_Rect pos_text ;
}Objet ;


void initialiser (Objet *newgame,Objet *loadgame ,Objet *settings,Objet *y_icon,Objet *in_sound ,Objet *in_sound25,Objet *in_sound50,Objet *in_sound75,Objet *in_sound100,Objet *in_settings,Objet *credits,Objet *main_menu ,Objet *quitter,Objet *wexit,Objet *nwexit ,Objet *exxit,Objet *game) ;
void setup (SDL_Surface *screen ,Objet *game,Objet *y_icon) ;
int verif_motion_surface (SDL_Event event,Objet surface) ;
void update (SDL_Surface *screen , Objet *surface1,Objet *surface2) ;
void liberate (Objet *newgame,Objet *loadgame ,Objet *settings,Objet *y_icon,Objet *in_sound ,Objet *in_sound25,Objet *in_sound50,Objet *in_sound75,Objet *in_sound100,Objet *in_settings,Objet *credits,Objet *main_menu ,Objet *quitter,Objet *wexit,Objet *nwexit ,Objet *exxit,Objet *game) ;
void clic_souris_menu_principale (SDL_Surface *screen,SDL_Event event, int curseur ,Objet newgame,Objet loadgame,Objet settings,Objet in_settings,Objet *icon,Objet quitter,int *in,int *running,int *boolean_icon,int *quitt,Objet exxit) ;
void clic_entrer_menu_principale (SDL_Surface *screen ,Objet in_settings,Objet icon,Mix_Chunk *effect, int curseur,int *in,int *running,int *quitt,Objet exxit ) ;
void mouse_motion_main_menu (SDL_Surface *screen ,SDL_Event event,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *quitt ) ;
void deplacementmenu_down (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *quitt ) ;
void deplacementmenu_up (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *firsttime,int *quitt) ;
int  deplacementmenu_up_down(SDL_Surface *screen, SDL_Event event ,int *firsttime,int *curseur,int *running,Objet newgame,Objet loadgame,Objet settings ,Objet quitter ,Objet *icon,Objet game , Mix_Chunk *effect,int *boolean_icon,int *quitt,Objet exxit ) ;
void deplacement__sousmenu_down (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume,Objet icon,Objet credits,Objet main_menu) ;
void deplacement__sousmenu_up (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume,Objet icon,Objet credits,Objet main_menu,int *firsttime) ;
void update_volume_surface(SDL_Surface *screen,Mix_Chunk *effect,Objet in_sound ,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume) ;
void motion_souris_sousmenu (SDL_Surface *screen ,SDL_Event event , Mix_Chunk *effect,int *curseur,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int position_volume,Objet icon,Objet credits,Objet main_menu) ;
void clic_souris_sousmenu (SDL_Surface *screen,Objet *icon, SDL_Event event,int curseur,Objet in_sound,Objet credits, Objet main_menu,int *running2,Objet game,int *boolean_icon);
void clic_entrer_sousmenu (SDL_Surface *screen,Objet icon, int *running2,int curseur,Objet game) ;
void deplacement_droit_gauche_volume (SDL_Surface *screen,Mix_Chunk *effect,Objet in_sound ,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int *position_volume) ;
void deplacement_sous_menu (SDL_Surface *screen ,Mix_Chunk *effect,SDL_Event event , int *running2,Objet in_settings,Objet in_sound,Objet in_sound25,Objet in_sound50,Objet in_sound75,Objet in_sound100,int *position_volume,Objet credits,Objet main_menu,Objet *icon, int *running,int *curseur,int *firsttime,Objet game,int *boolean_icon ) ;
void quitter_oui_non(SDL_Surface *screen ,SDL_Event event,int *running,int *running2,int *running3,Objet quitter,Objet icon,Objet wexit,Objet nwexit,int *test,int *test_s);