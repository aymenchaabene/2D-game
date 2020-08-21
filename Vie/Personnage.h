typedef struct
{
    SDL_Rect pos;
    vie vie;
    SDL_Surface *image;
}Personnage;

void intialisePersonnage (Personnage *perso);
void AfficherPerso (Personnage perso, SDL_Surface *ecran);
void DeplacerClavier (Personnage *perso, SDL_Event Event);
void DeplacerSouris (Personnage *perso, SDL_Event Event);
void AnimationPerso (Personnage *perso);
int DetectionBoundingBox(Personnage perso, SDL_Surface ecran);
int DetectionTrigo(Personnage perso, SDL_Surface ecran);
int Collision(Personnage perso, SDL_Surface ecran);
int GestionVie (Personnage *perso);
