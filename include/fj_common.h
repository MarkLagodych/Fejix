#ifndef _FJ_COMMON_H
#define _FJ_COMMON_H

#include <stdint.h>

typedef uint8_t fj_chan; /// Signle color channel

/// RGBA color
typedef struct {
    fj_chan r;
    fj_chan g;
    fj_chan b;
    fj_chan a;
} fj_color;

/// Rectangle with real (pixel) dimensions
typedef struct {
    int x;
    int y;
    int w;
    int h;
} fj_rect;

typedef struct {
    int x;
    int y;
    int w;
    int h;

    // Units: px (0), % (1) or em (2)
    unsigned ux: 2;
    unsigned uy: 2;
    unsigned uw: 2;
    unsigned uh: 2;

    // Anchors
    unsigned ax: 1; // 0 is left, 1 is right
    unsigned ay: 1; // 0 is top, 1 is bottom
    unsigned aw: 1; // 0 is w, 1 is area.w - w
    unsigned ah: 1; // 0 is h, 1 is area.h - h
    unsigned _unused: 4; 
} fj_xrect;

enum fj_fillType
{
    FJ_FILL_NONE,
    FJ_FILL_COLOR,
};

typedef struct {
    enum fj_fillType type;
    void *data;
} fj_fill;

#endif // _FJ_COMMON_H