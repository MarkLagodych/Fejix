#include "fj_wm.h"

fj_window* fj_wm_queryNewWindow()
{
    fj_window *win = (fj_window *) malloc(sizeof(fj_window));
    if (!win) return NULL;

    win->handle = SDL_CreateWindow(
        "",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        300, 250, 0
    );

    win->title = "";

    return win;
}



void fj_wm_queryDelWindow(fj_window *win)
{
    SDL_DestroyWindow(win->handle);
    free(win);
}



fj_window* fj_newWindow (
    const char *title,
    int x, int y, int w, int h,
    enum fj_wm_position pos,
    int flags
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

    int _flags = 0;
    // Process one flag
#   define F(x) if (flags & FJ_WM_FLAG_##x) _flags |= SDL_WINDOW_##x;
    F(BORDERLESS)
    F(FULLSCREEN)
    F(RESIZABLE)
    F(MAXIMIZED)
    F(MINIMIZED)
#   undef F

    fj_window *win = (fj_window *) malloc(sizeof(fj_window));
    if (!win) return NULL;

    win->handle = SDL_CreateWindow(title, _x, _y, w, h, _flags);
    win->title = title;

    return win;
}

static
void _queryWinTitle(fj_window *win, int set, const char *strData)
{
    if (!set) {
        strData = win->title;
        return;
    }

    win->title = strData;
    SDL_SetWindowTitle(win->handle, strData);
}

static
void _queryCursor(int set, int *x, int *y)
{
    if (!set)
        SDL_GetMouseState(x, y);
}

static
void _queryWinPos(fj_window *win, int set, int *x, int *y)
{
    if (!set)
        SDL_GetWindowPosition(win->handle, x, y);
    else
        SDL_SetWindowPosition(win->handle, *x, *y);
}

static
void _queryWinSize(fj_window *win, int set, int *w, int *h)
{
    if (!set)
        SDL_GetWindowSize(win->handle, w, h);
    else
        SDL_SetWindowSize(win->handle, *w, *h);
}

static
void _queryWinFlag(fj_window *win, int set, int flag, int *value)
{
    if (!set) {
        int current = SDL_GetWindowFlags(win->handle);

        switch (flag) {
        case FJ_WM_FLAG_BORDERLESS:
            *value = current & SDL_WINDOW_BORDERLESS;
            return;

        case FJ_WM_FLAG_FULLSCREEN:
            *value = current & SDL_WINDOW_FULLSCREEN;
            return;

        case FJ_WM_FLAG_RESIZABLE:
            *value = current & SDL_WINDOW_RESIZABLE;
            return;

        case FJ_WM_FLAG_MAXIMIZED:
            *value = current & SDL_WINDOW_MAXIMIZED;
            return;

        case FJ_WM_FLAG_MINIMIZED:
            *value = current & SDL_WINDOW_MINIMIZED;
            return;

        default:
            return;
        }
    } // !set

#   define v *value
#   define h win->handle

    switch (flag) {
    case FJ_WM_FLAG_BORDERLESS:
        SDL_SetWindowBordered(h, v);
        return;

    case FJ_WM_FLAG_FULLSCREEN:
        SDL_SetWindowFullscreen(h, v ? SDL_WINDOW_FULLSCREEN : 0);
        return;

    case FJ_WM_FLAG_RESIZABLE:
        SDL_SetWindowResizable(h, v);
        return;

    case FJ_WM_FLAG_MAXIMIZED:
        if (v) SDL_MaximizeWindow(h);
        else SDL_RestoreWindow(h);
        return;

    case FJ_WM_FLAG_MINIMIZED:
        if (v) SDL_MinimizeWindow(h);
        else SDL_RestoreWindow(h);
        return;

    default:
        return;
    }

#   undef v h

}

void fj_wm_queryInt2 (
    fj_window *win,
    int set, enum fj_wm_queryType type,
    int *A, int *B
) {
    switch (type) {
    case FJ_WM_QUERY_CURSOR_POS:
        _queryCursor(set, A, B);
        break;
    
    case FJ_WM_QUERY_WINDOW_POS:
        _queryWinPos(win, set, A, B);
        break;
    
    case FJ_WM_QUERY_WINDOW_SIZE:
        _queryWinSize(win, set, A, B);
        break;
    
    case FJ_WM_QUERY_WINDOW_FLAG:
        _queryWinFlag(win, set, *A, B);
        break;
    
    default:
        break;
    }
}



void fj_wm_queryStr (
    fj_window *win,
    int set, enum fj_wm_queryType type,
    const char *strData
) {
    switch (type) {
    case FJ_WM_QUERY_WINDOW_TITLE:
        _queryWinTitle(win, set, strData);
        break;
    }
}