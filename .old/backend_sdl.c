/**
@file backend_sdl.c

@brief Fejix backend implemented with SDL2 and SDL_gfx

xxxRGBA functions are preferred over the xxxColor functions because of bugs that
xxxColor functions have (or, at least, because Fejix stores colors separately)
*/

#include <malloc.h>
#include <math.h>

#include "backend.h"
#include "backend_sdl.h"

#define FILL_RGBA   fill->data.color.r, \
                    fill->data.color.g, \
                    fill->data.color.b, \
                    fill->data.color.a


int FJ_InitBackend(void)
{
    FJ_ASSERT1(SDL_Init(SDL_INIT_EVERYTHING) >= 0,
        "Cannot initialize SDL backend");

    return 0;
}



void FJ_QuitBackend(void)
{
    SDL_Quit();
}



FJ_Window* FJ_NewWindow(const char *title, int width, int height)
{
    SDL_Window *sdl_win = SDL_CreateWindow (
        title,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
    );
    FJ_ASSERTN(sdl_win != NULL, "Cannot create SDL window");

    SDL_Renderer *sdl_renderer = SDL_CreateRenderer(sdl_win, -1, 0);
    FJ_ASSERTN(sdl_renderer != NULL, "Cannot create SDL renderer");

    FJ_Window *fj_win = malloc(sizeof(FJ_Window));
    FJ_ASSERTN(fj_win != NULL, "Cannot create Fejix window");
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



void FJ_Delay(int ms)
{
    SDL_Delay(ms);
}



void FJ_RunBackend(FJ_Window *win, int (*runFunction)(FJ_WindowContext *))
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

        FJ_WindowContext ctx;
        ctx.renderer = win->renderer;
        _continue &= runFunction(&ctx);

    }
}



void FJ_DrawRelease(FJ_WindowContext *ctx)
{
    SDL_RenderPresent(ctx->renderer);
}



void FJ_DrawClear(FJ_WindowContext *ctx, FJ_Fill *fill)
{
    if (!fill)
    {
        SDL_SetRenderDrawColor(ctx->renderer, 0, 0, 0, 0);
        SDL_RenderClear(ctx->renderer);
        return;
    }

    if (fill->type == FJ_FILL_T_NONE)
        return;

    if (fill->type == FJ_FILL_T_COLOR)
        SDL_SetRenderDrawColor(ctx->renderer, FILL_RGBA);

    SDL_RenderClear(ctx->renderer);
}



void FJ_DrawRectFilled(FJ_WindowContext *ctx, FJ_Rect *rect, FJ_Fill *fill)
{
    if (fill->type == FJ_FILL_T_NONE)
        return;

    if (fill->type == FJ_FILL_T_COLOR)
        roundedBoxRGBA(ctx->renderer,
            rect->x, rect->y, rect->x + rect->w, rect->y + rect->h,
            rect -> r,
            FILL_RGBA);
}

void FJ_DrawRect(FJ_WindowContext *ctx, FJ_Rect *rect, FJ_Fill *fill)
{
    if (fill->type == FJ_FILL_T_NONE)
        return;

    if (fill->type == FJ_FILL_T_COLOR)
        roundedRectangleRGBA(ctx->renderer,
            rect->x, rect->y, rect->x + rect->w, rect->y + rect->h,
            rect -> r,
            FILL_RGBA);
}



void FJ_DrawLine(FJ_WindowContext *ctx, FJ_Line *line, FJ_Fill *fill)
{
    if (fill->type == FJ_FILL_T_NONE)
        return;

    thickLineRGBA(ctx->renderer,
        line->x, line->y, line->x + line->ox, line->y + line->oy,
        line->w,
        FILL_RGBA);
}



void FJ_DrawEllipseFilled(FJ_WindowContext *ctx, FJ_Ellipse *e, FJ_Fill *fill)
{
    if (fill->type == FJ_FILL_T_NONE)
        return;

    int rx = e->w / 2;
    int ry = e->h / 2;
    filledEllipseRGBA(ctx->renderer,
        e->x + rx,  e->y + ry,  rx-1,  ry-1,
        FILL_RGBA);
}

void FJ_DrawEllipse(FJ_WindowContext *ctx, FJ_Ellipse *e, FJ_Fill *fill)
{
    if (fill->type == FJ_FILL_T_NONE)
        return;

    int rx = e->w / 2;
    int ry = e->h / 2;
    ellipseRGBA(ctx->renderer,
        e->x + rx,  e->y + ry,  rx-1,  ry-1,
        FILL_RGBA);
}



void FJ_DrawPolygonFilled(FJ_WindowContext *ctx, FJ_Polygon *p, FJ_Fill *fill)
{
    if (fill->type == FJ_FILL_T_NONE)
        return;

    // SDL_gfx requires x and y coordinates to be in two separate arrays
    Sint16 vx[p->length];
    Sint16 vy[p->length];

    for (int i = 0; i < p->length; i++)
    {
        vx[i] = p->points[i].x;
        vy[i] = p->points[i].y;
    }

    filledPolygonRGBA(ctx->renderer,
        vx, vy,
        p->length,
        FILL_RGBA);
}

void FJ_DrawPolygon(FJ_WindowContext *ctx, FJ_Polygon *p, FJ_Fill *fill)
{
    if (fill->type == FJ_FILL_T_NONE)
        return;

    // SDL_gfx requires x and y coordinates to be in two separate arrays
    Sint16 vx[p->length];
    Sint16 vy[p->length];

    for (int i = 0; i < p->length; i++)
    {
        vx[i] = p->points[i].x;
        vy[i] = p->points[i].y;
    }

    polygonRGBA(ctx->renderer,
        vx, vy,
        p->length,
        FILL_RGBA);
}



void FJ_DrawShape(FJ_WindowContext *ctx, FJ_Shape *shape, FJ_Fill *fill)
{
    switch (shape->type)
    {
    case FJ_SHAPE_T_LINE:
        FJ_DrawLine(ctx, &shape->data.line, fill);
        break;

    case FJ_SHAPE_T_RECT:
        if (shape->filled)
            FJ_DrawRectFilled(ctx, &shape->data.rect, fill);
        else
            FJ_DrawRect(ctx, &shape->data.rect, fill);
        break;

    case FJ_SHAPE_T_ELLIPSE:
        if (shape->filled)
            FJ_DrawEllipseFilled(ctx, &shape->data.ellipse, fill);
        else
            FJ_DrawEllipse(ctx, &shape->data.ellipse, fill);
        break;

    case FJ_SHAPE_T_POLYGON:
        if (shape->filled)
            FJ_DrawPolygonFilled(ctx, &shape->data.polygon, fill);
        else
            FJ_DrawPolygon(ctx, &shape->data.polygon, fill);
        break;
    }
}


void FJ_DrawElem(FJ_WindowContext *ctx, FJ_Elem *elem)
{
    FJ_DrawShape(ctx, &elem->shape, &elem->fill);
}
