#ifndef FJH_BACKEND_SDL
#define FJH_BACKEND_SDL

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "common.h"

struct FJI_Window {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

struct FJI_WindowContext {
    SDL_Renderer *renderer;
};

#endif // FJH_BACKEND_SDL
