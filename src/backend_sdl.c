#include <malloc.h>

#include "backend.h"
#include "backend_sdl.h"


int FJ_BackendInit(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        FJ_SetError("Cannot initialize SDL backend");
        return 1;
    }

    return 0;
}


void FJ_BackendQuit(void)
{
    SDL_Quit();
}


FJ_Window* FJ_NewWindow(const char *title, int width, int height)
{
    SDL_Window *sdl_win = SDL_CreateWindow (
        title,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height,
        0 /*flags*/
    );
    FJ_ASSERT(sdl_win != NULL, "Cannot create SDL window");

    SDL_Renderer *sdl_renderer = SDL_CreateRenderer(sdl_win, -1, 0);
    FJ_ASSERT(sdl_renderer != NULL, "Cannot create SDL renderer");

    FJ_Window *fj_win = malloc(sizeof(FJ_Window));
    FJ_ASSERT(fj_win != NULL, "Cannot create Fejix window");
    fj_win->window = sdl_win;
    fj_win->renderer = sdl_renderer;

    return fj_win;
}


void FJ_DelWindow(FJ_Window *win)
{
    SDL_DestroyRenderer(win->renderer);
    SDL_DestroyWindow(win->window);

    win->renderer = NULL;
    win->window = NULL;
}
/*
void MainLoop(Window *win, RunFunction runFunction)
{
    for (int _continue = 1; _continue; ) {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    _continue = 0;
                    break;
            }
        }

        WindowContext ctx;
        ctx.renderer = win->renderer;
        SDL_SetRenderDrawColor(win->renderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(win->renderer);
        runFunction(&ctx);
        SDL_RenderPresent(win->renderer);

        SDL_Delay(1000. / 60);

    }
}

void SetColor(int clr)
{
    color = clr;
    color_a = clr & 0xFF000000 >> 030;
    color_r = clr & 0x00FF0000 >> 020;
    color_g = clr & 0x0000FF00 >> 010;
    color_b = clr & 0x000000FF;
}

void DrawRectangle(WindowContext *ctx, int x, int y, int w, int h, int r)
{
    if (r == 0)
    {
        rectangleRGBA(ctx->renderer, x, y, x+w, y+h, color_r, color_g, color_b, color_a);
    }
}*/
