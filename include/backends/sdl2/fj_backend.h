#ifndef _FJ_BACKEND_H
#define _FJ_BACKEND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "fj_wm.h"
#include "fj_common.h"

int fj_initBackend();
void fj_quitBackend();

typedef void (*fj_eventHandlerFunc) ();
typedef void (*fj_updaterFunc) ();
void fj_runBackend(fj_eventHandlerFunc, fj_updaterFunc);

void fj_updateWindow(fj_window*);

void fj_drawRectColor(
    fj_window *win,
    fj_rect *rect,
    fj_simpleShape *simple,
    fj_color *color
);

//void fj_drawLine(fj_xrect*, fj_fill*);

#endif // _FJ_BACKEND_H