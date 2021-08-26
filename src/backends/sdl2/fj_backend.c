#include "fj_backend.h"

#include <SDL2/SDL.h>

int fj_initBackend()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;

    return 0;
}

void fj_quitBackend()
{
    SDL_Quit();
}

void fj_runBackend(fj_eventHandlerFunc evh, fj_updaterFunc update)
{
    SDL_Event event;
    for (int run=1; run; )
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                run = 0;
            
        }

        update();
    }
}