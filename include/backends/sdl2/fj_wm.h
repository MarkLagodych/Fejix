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

typedef SDL_WindowFlags fj_wm_flags;
#define FJ_WM_FLAG_BORDERLESS SDL_WINDOW_BORDERLESS
#define FJ_WM_FLAG_FULLSCREEN SDL_WINDOW_FULLSCREEN
#define FJ_WM_FLAG_RESIZABLE  SDL_WINDOW_RESIZABLE
#define FJ_WM_FLAG_MAXIMIZED  SDL_WINDOW_MAXIMIZED
#define FJ_WM_FLAG_MINIMIZED  SDL_WINDOW_MINIMIZED

#define FJ_WM_FLAG_NORMAL     0

fj_window* fj_newWindow (
    const char *title,
    int x, int y, int w, int h,
    enum fj_wm_position position,
    fj_wm_flags flags
);

void fj_delWindow(fj_window *window);

/// @param set  if 0 then just gets the value, if 1 then sets the value
void fj_wm_queryTitle(int set, fj_window*, const char* title);

void fj_wm_queryRect(int set, fj_window*, fj_rect* rect);

/// Each flag is applied only if it is different
void fj_wm_queryFlags(int set, fj_window*, fj_wm_flags* flags);

#endif // _FJ_WINDOW_H