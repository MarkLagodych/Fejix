#ifndef _FJ_FEJIX_H
#define _FJ_FEJIX_H

#include "fj_common.h"

#if defined(FJ_OPT_BACKEND_SDL)
#   include "backends/sdl2/fj_backend.h"
#else
#   error Fejix backend is not specified
#endif

int fj_init();
void fj_quit();

#endif // _FJ_FEJIX_H