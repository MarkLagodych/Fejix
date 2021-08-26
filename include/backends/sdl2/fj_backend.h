#ifndef _FJ_BACKEND_H
#define _FJ_BACKEND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "fj_wm.h"

int fj_initBackend();
void fj_quitBackend();

#endif // _FJ_BACKEND_H