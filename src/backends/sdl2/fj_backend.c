#include "fj_backend.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

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


void fj_updateWindow(fj_window* win)
{
    SDL_RenderPresent(win->_handle);
}


void fj_drawRectColor(
    fj_window *win,
    fj_rect *r,
    fj_simpleShape *simple,
    fj_color *c
)
{
    if (simple->t == -1)
        roundedRectangleRGBA(
            win->_renderer,
            r->x, r->y, r->w, r->h, simple->r, c->r, c->g, c->b, c->a
        );

    else
        roundedBoxRGBA(
            win->_renderer,
            r->x, r->y, r->w, r->h, simple->r, c->r, c->g, c->b, c->a
        );
}