#include"vie.h"
#define WIDTH 1000
#define HEIGHT 560


int main ( int argc, char* argv[] )
{
        SDL_Surface *ecran = NULL;
        
        SDL_Event event;
        int gameover = 1;
        int test;
	vie v;
        init_vie(&v);
        SDL_Init(SDL_INIT_VIDEO);
        ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        SDL_WM_SetCaption("vie", NULL);
        SDL_EnableKeyRepeat(.5,.5);
        while(gameover)
        {
	test=0;
                if(SDL_WaitEvent(&event))
                {
                        switch(event.type)
                        {
                        case SDL_QUIT:
                                gameover = 0;
                                break;
                        case SDL_KEYDOWN:

                                switch(event.key.keysym.sym)
                                {
                                
                                case SDLK_RIGHT:

					test=1;

                                        break;
                                }
                                break;
                        }
                        
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
			updatevie(&v,test);  
			displayvie(v ,ecran) ;	
                        SDL_Flip(ecran);
                }
        }
	vie_freevie(&v);
        SDL_Quit();
        return 0;
}
