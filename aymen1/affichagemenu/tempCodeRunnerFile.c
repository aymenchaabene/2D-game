SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(background, NULL, screen, &posback);

        SDL_Flip(screen);