/**
 * @file depsouris.c
 * @brief  Deplacement perso 
 * @param  Objet tab[]
 * @param  Objet *map pointeur
 * @param  Objet *wood
 * @param  int *running
 * @param  float *curseur_perso
 * @param  int *right 
 * @param  int *left 
 * @param  int *saut
 * @param  Objet ennemi[] 
 * @param  Objet *mask
 * @return *curseur_perso
*/
float deplacement_objet(Objet tab[],Objet *map,Objet *wood,int *running,float *curseur_perso,int *right,int *left,int *saut,Objet ennemi [],Objet *mask)
{
  SDL_Event event ;
 *left=0 ;
 *right=0 ;

  SDL_PollEvent(&event);
     switch(event.type)
      {
         case SDL_QUIT:
              *running=0;
         break;
               case SDL_MOUSEBUTTONDOWN:
             if(event.button.button==(SDL_BUTTON_LEFT ||SDL_BUTTON_RIGHT))
              {
                if(event.button.x<(1368/2))
                  {
                    *left=1;
                    if(*curseur_perso >= 6.9)
                     *curseur_perso = 1;

                      tab[0].pos.x-= 7 ;
                    
                          
                 
                  (*curseur_perso) +=0.5 ;
                  }
               if(event.button.x>=(1368/2)) 
             {
                *right=1 ;
              if(*curseur_perso >= 6.9)
                *curseur_perso = 1;
                 tab[0].pos.x+= 7 ;
              
               (*curseur_perso) +=0.5 ;
                       
                          
               
             }
              }  

            break ;
      }
  return (*curseur_perso) ;   
}
