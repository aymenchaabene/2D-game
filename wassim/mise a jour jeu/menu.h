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

#define xwood 2770
#define ywood 510

#define xboat 920
#define yboat 768-175

#define vie_w 0
#define vie_h 10
typedef struct 
{
 SDL_Rect map_pos ;  
 SDL_Rect perso_pos ;
 SDL_Rect ennemi_pos ;
 SDL_Rect box_pos ;
 SDL_Rect pos ;
 int valeur_vie ;
 int score_finale ;
 int seconde ;
 int minute ;
 int level ;

}Saving;

typedef struct 
{

int X;
int Y;

}Coordinate;

typedef struct 
{
  int x ;
  int y ;
  float rayon ;

}Circle;

typedef struct 
{
  int vx ;
  float vy ;
  int jump ;
  int stop ;
  SDL_Surface *img ;
  SDL_Rect pos ;
  Circle c ;
  SDL_Rect pos_text ;

  
}Objet ;

void initiial (Objet *map,Objet *wood,Objet *boat,Objet tabD [],Objet tabG [],Objet ennemi [],Objet ennemiD [],Objet vie [],Objet *mask,Objet *keyboard,Objet *mouse,Objet *controller,Objet *choose,int save) ;
void initialiser (Objet *newgame,Objet *loadgame ,Objet *settings,Objet *icon,Objet *in_sound ,Objet *in_sound25,Objet *in_sound50,Objet *in_sound75,Objet *in_sound100,Objet *in_settings,Objet *credits,Objet *main_menu ,Objet *quitter,Objet *wexit,Objet *nwexit ,Objet *exxit,Objet *game,Objet *map,Objet *wood,Objet *boat,Objet tabD [],Objet tabG [],Objet ennemi [],Objet ennemiD [],Objet vie [],Objet *mask,Objet *keyboard,Objet *mouse,Objet *controller,Objet *choose,int save) ;
void setup (SDL_Surface *screen ,Objet *game,Objet *y_icon) ;
int verif_motion_surface (SDL_Event event,Objet surface) ;
void update (SDL_Surface *screen , Objet *surface1,Objet *surface2) ;
void liberate (Objet *newgame,Objet *loadgame ,Objet *settings,Objet *y_icon,Objet *in_sound ,Objet *in_sound25,Objet *in_sound50,Objet *in_sound75,Objet *in_sound100,Objet *in_settings,Objet *credits,Objet *main_menu ,Objet *quitter,Objet *wexit,Objet *nwexit ,Objet *exxit,Objet *game) ;
void clic_souris_menu_principale (SDL_Surface *screen,SDL_Event event, int curseur ,Objet newgame,Objet loadgame,Objet settings,Objet in_settings,Objet *icon,Objet quitter,int *in,int *running,int *boolean_icon,int *quitt,Objet exxit,Objet tab [],int *transition,int *save) ;
void clic_entrer_menu_principale (SDL_Surface *screen ,Objet in_settings,Objet icon,Mix_Chunk *effect, int curseur,int *in,int *running,int *quitt,Objet exxit,int *transition,int *save ) ;
void mouse_motion_main_menu (SDL_Surface *screen ,SDL_Event event,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *quitt ) ;
void deplacementmenu_down (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *quitt ) ;
void deplacementmenu_up (SDL_Surface *screen ,Mix_Chunk *effect,int *curseur,Objet newgame,Objet icon,Objet loadgame,Objet settings,Objet quitter,int *firsttime,int *quitt) ;
int  deplacementmenu_up_down(SDL_Surface *screen, SDL_Event event ,int *firsttime,int *curseur,int *running,Objet newgame,Objet loadgame,Objet settings ,Objet quitter ,Objet *icon,Objet game , Mix_Chunk *effect,int *boolean_icon,int *quitt,Objet exxit,Objet tab [],int *transition,int *save ) ;
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
void renderD (SDL_Surface *screen, Objet *map ,Objet *wood, Objet tabD [],float curseur_perso,Objet ennemi [],float compteur,int right_ennemi,int left_ennemi,Objet ennemiD [],Objet vie [] ,int valeur_vie,SDL_Surface *texte ,SDL_Rect position,SDL_Surface *gestion_score ,SDL_Rect position2,Objet *mask,Objet *mini_map ) ;
void renderG (SDL_Surface *screen, Objet *map ,Objet *wood, Objet tabD [],Objet tabG [],float *curseur_perso,Objet ennemi [],float compteur,int right_ennemi,int left_ennemi,Objet ennemiD [],Objet vie [] ,int valeur_vie,SDL_Surface *texte ,SDL_Rect position,SDL_Surface *gestion_score ,SDL_Rect position2,Objet *mask,Objet *mini_map  ) ;
void affichage (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map) ;
void scrolling_droit ( Objet *map,Objet *mask,SDL_Rect *pos,int enablefast) ;
void scrolling_gauche ( Objet *map,Objet *mask,SDL_Rect *pos,int enablefast) ;
int evenement (SDL_Rect *pos ,Objet *wood,Objet *map,int *enablefast,int *right,int*left,float *curseur_perso ,Objet ennemi [],Objet *mask,Objet tab [] ) ;
int collisionBB(Objet perso [],Objet ennemi []) ;
void calculer_centre_rayon (Objet *perso,Objet tab []) ;
float calculer_distance (Objet *perso,Objet tab []) ;
int verif_collision ( Objet *perso,Objet tab [],float D1 ) ;
float deplacement_objet(Objet tab[],Objet *map,Objet *wood,int *running,float *curseur_perso,int *right,int *left,int *saut,Objet ennemi [],Objet *mask) ;
void init_enigme(Objet* e) ;
void  generate_afficher (SDL_Surface * screen  , char image [],Objet *e,int *alea) ;
int solution_e (char image []) ;
int resolution (int * running,int *run);
void afficher_resultat (SDL_Surface * screen,int s,int r,Objet *en) ;
void deplacement_ennemi(Objet ennemi [],float *compteur,int *right_ennemi,int *left_ennemi) ;
void gestion_vie(Objet vie [],int *valeur_vie,Objet tabD []) ;
void affiche_vie(SDL_Surface *screen , Objet vie [] ,int valeur_vie) ;
int Collision_Parfaite(SDL_Surface *Background,Coordinate C) ;
Uint32 getpixel(SDL_Surface *surface,Coordinate C) ;
void update_fonts(int *tempsActuel,int *tempsPrecedent,int *compteurr,int *seconde,char temps [],char score [],int *score_finale,SDL_Surface **texte,SDL_Surface **gestion_score,TTF_Font *police,SDL_Color couleurBlanche ) ;
Saving level1 (int save,Saving S) ;
Saving stage2 (int save,Saving S) ;
Saving chapter3 (int save,Saving S) ;

