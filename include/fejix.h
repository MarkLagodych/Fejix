#ifndef _FJ_FEJIX_H
#define _FJ_FEJIX_H

#include "fj_common.h"
#include "fj_backend.h"

int fj_init();
void fj_quit();

/// Enters main loop where everything is processed by Fejix
void fj_loop();

#endif // _FJ_FEJIX_H