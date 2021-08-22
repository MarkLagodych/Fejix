#ifndef _FJ_BACKEND_H
#define _FJ_BACKEND_H

#include <SDL2/SDL.h>

typedef struct {
    const char *title;
    SDL_Window *_win;
} fj_window;

int fj_init_backend();
void fj_quit_backend();

#endif // _FJ_BACKEND_H