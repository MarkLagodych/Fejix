#include "fj_backend.h"

#include <SDL2/SDL.h>

int fj_init_backend()
{
    return SDL_Init(SDL_INIT_EVERYTHING) < 0;
}

void fj_quit_backend()
{
    SDL_Quit();
}