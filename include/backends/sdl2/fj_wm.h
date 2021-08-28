/**
 * Some things to do with the window manager
 */

#ifndef _FJ_WINDOW_H
#define _FJ_WINDOW_H

#include "fj_backend.h"
#include "fj_common.h"

typedef struct {
    const char *title;
    SDL_Window *handle;
} fj_window;

enum fj_wm_position
{
    FJ_WM_POS_ANYWHERE = 0, /// Place anywhere on the screen
    FJ_WM_POS_EXACT,    /// Place exactly at the specified (x;y) point
    FJ_WM_POS_CENTER,   /// Center on the screen
};

enum fj_wm_windowFlags {
    FJ_WM_FLAG_BORDERLESS = 1 << 0,
    FJ_WM_FLAG_FULLSCREEN = 1 << 1,
    FJ_WM_FLAG_RESIZABLE  = 1 << 2,
    FJ_WM_FLAG_MAXIMIZED  = 1 << 3,
    FJ_WM_FLAG_MINIMIZED  = 1 << 4,
};

enum fj_wm_queryType {
    FJ_WM_QUERY_CURSOR_POS,
    FJ_WM_QUERY_WINDOW_POS,
    FJ_WM_QUERY_WINDOW_SIZE,
    FJ_WM_QUERY_WINDOW_TITLE,
    FJ_WM_QUERY_WINDOW_FLAG,
};

fj_window* fj_wm_queryNewWindow();
void fj_wm_queryDelWindow(fj_window*);

fj_window* fj_newWindow (
    const char *title,
    int x, int y, int w, int h,
    enum fj_wm_position position,
    int flags
);
#define fj_delWindow fj_wm_queryDelWindow

/**
 * @param set   Get (0) or set(1) the queried parameter
 * 
 * @example examples/window_manipulation/wm_queries.c
 */
void fj_wm_queryInt2 (
    fj_window *win,
    int set, enum fj_wm_queryType type,
    int *intData1, int *intData2
);

/**
 * @param set   Get (0) or set(1) the queried parameter
 * 
 * @example examples/window_manipulation/wm_queries.c
 */
void fj_wm_queryStr (
    fj_window *win,
    int set, enum fj_wm_queryType type,
    const char *strData
);



#endif // _FJ_WINDOW_H