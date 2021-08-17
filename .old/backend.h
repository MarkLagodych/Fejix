/**
@file backend.h

@brief Basic functions for drawing and managing windows
*/

#ifndef FJH_BACKEND
#define FJH_BACKEND

#include "common.h"

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
int FJ_InitBackend(void);

void FJ_QuitBackend(void);

typedef struct FJI_Window FJ_Window;

FJ_Window* FJ_NewWindow(const char *title, int width, int height);

void FJ_DelWindow(FJ_Window *win);

typedef struct FJI_WindowContext FJ_WindowContext;

void FJ_RunBackend(FJ_Window *win, int (*runFunction)(FJ_WindowContext *));

void FJ_Delay(int ms);

void FJ_DrawRelease(FJ_WindowContext *ctx);
void FJ_DrawClear(FJ_WindowContext *ctx, FJ_Fill *fill);

void FJ_DrawLine(FJ_WindowContext *ctx, FJ_Line *line, FJ_Fill *fill);

void FJ_DrawRect(FJ_WindowContext *ctx, FJ_Rect *rect, FJ_Fill *fill);
void FJ_DrawRectFilled(FJ_WindowContext *ctx, FJ_Rect *rect, FJ_Fill *fill);

void FJ_DrawEllipse(FJ_WindowContext *ctx, FJ_Ellipse *e, FJ_Fill *fill);
void FJ_DrawEllipseFilled(FJ_WindowContext *ctx, FJ_Ellipse *e, FJ_Fill *fill);

void FJ_DrawPolygon(FJ_WindowContext *ctx, FJ_Polygon *p, FJ_Fill *fill);
void FJ_DrawPolygonFilled(FJ_WindowContext *ctx, FJ_Polygon *p, FJ_Fill *fill);

void FJ_DrawShape(FJ_WindowContext *ctx, FJ_Shape *shape, FJ_Fill *fill);

void FJ_DrawElem(FJ_WindowContext *ctx, FJ_Elem *elem);

#endif // FJH_BACKEND
