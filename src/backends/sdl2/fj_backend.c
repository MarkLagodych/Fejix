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