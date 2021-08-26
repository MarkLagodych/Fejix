#ifndef _FJ_BACKEND_H
#define _FJ_BACKEND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "fj_wm.h"

int fj_initBackend();
void fj_quitBackend();

typedef void (*fj_eventHandlerFunc) ();
typedef void (*fj_updaterFunc) ();
void fj_runBackend(fj_eventHandlerFunc, fj_updaterFunc);

void fj_drawLine(fj_xrect*, fj_fill*);

#endif // _FJ_BACKEND_H