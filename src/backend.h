/**
@file backend.h

@brief Basic functions for drawing and managing windows
*/

#ifndef FJH_BACKEND
#define FJH_BACKEND

// All supported backends
#define FJ_BACKEND_SDL 0

#ifndef FJF_BACKEND
#   define FJF_BACKEND FJ_BACKEND_SDL
#endif

#ifdef FJF_BACKEND_SDL
#   include "backend_sdl.h"
#endif

/* All function implementations or FJI_ structures must be present in backend
   implementation
*/

/** @return Exit status */
int FJ_BackendInit(void);

void FJ_BackendQuit(void);

typedef struct FJI_Window FJ_Window;

FJ_Window* FJ_NewWindow(const char *title, int width, int height);

void FJ_DelWindow(FJ_Window *win);

typedef struct FJI_WindowContext FJ_WindowContext;

void DrawRectangle(FJ_WindowContext *ctx, int x, int y, int w, int h, int r);


#endif // FJH_BACKEND
