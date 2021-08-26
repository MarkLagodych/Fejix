#include "fj_wm.h"

fj_window* fj_newWindow (
    const char *title,
    int x, int y, int w, int h,
    enum fj_wm_position pos,
    fj_wm_flags flags
) {
    int _x, _y;

    // Set _x, _y
    switch (pos)
    {
    case FJ_WM_POS_ANYWHERE:
        _x = SDL_WINDOWPOS_UNDEFINED;
        _y = SDL_WINDOWPOS_UNDEFINED;
        break;

    case FJ_WM_POS_CENTER:
        _x = SDL_WINDOWPOS_CENTERED;
        _y = SDL_WINDOWPOS_CENTERED;
        break;

    default:
        _x = x;
        _y = y;
        break;
    }

    if (flags == 0) flags = FJ_WM_FLAG_RESIZABLE;

    fj_window *win = (fj_window *) malloc(sizeof(fj_window));
    if (!win) return NULL;

    win->handle = SDL_CreateWindow(title, _x, _y, w, h, flags);
    win->title = title;

    return win;
}


void fj_delWindow(fj_window *win)
{
    SDL_DestroyWindow(win->handle);
    free(win);
}


void fj_wm_queryTitle(int set, fj_window* win, const char* title)
{
    if (!set) {
        title = win->title;
        return;
    }

    SDL_SetWindowTitle(win->handle, title);
    win->title = title;
}


void fj_wm_queryRect(int set, fj_window* win, fj_rect* rect)
{
    if (!set) {
        SDL_GetWindowPosition(win->handle, &rect->x, &rect->y);
        SDL_GetWindowSize(win->handle, &rect->w, &rect->h);
        return;
    }

    SDL_SetWindowPosition(win->handle, rect->x, rect->y);
    SDL_SetWindowSize(win->handle, rect->w, rect->h);
}

void fj_wm_queryFlags(int set, fj_window* win, fj_wm_flags* flags)
{
    fj_wm_flags current = SDL_GetWindowFlags(win->handle);

    if (!set) {
        *flags = current;
        return;
    }

    fj_wm_flags changed = current ^ *flags;

    if (changed & FJ_WM_FLAG_BORDERLESS)
        SDL_SetWindowBordered(win->handle,
            !(*flags & FJ_WM_FLAG_BORDERLESS));

    if (changed & FJ_WM_FLAG_FULLSCREEN)
        SDL_SetWindowFullscreen(win->handle,
            *flags & FJ_WM_FLAG_FULLSCREEN);

    if (changed & FJ_WM_FLAG_RESIZABLE)
        SDL_SetWindowResizable(win->handle,
            *flags & FJ_WM_FLAG_RESIZABLE);

    if (changed & FJ_WM_FLAG_MAXIMIZED)
        SDL_MaximizeWindow(win->handle);

    if (changed & FJ_WM_FLAG_MINIMIZED)
        SDL_MinimizeWindow(win->handle);

    SDL_UpdateWindowSurface(win->handle);   
}