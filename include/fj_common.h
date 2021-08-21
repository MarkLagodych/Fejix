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

    // px (0), % (1) or em (2)
    unsigned x_unit: 2;
    unsigned y_unit: 2;
    unsigned w_unit: 2;
    unsigned h_unit: 2;

    unsigned anchor_x: 1; // 0 is left, 1 is right
    unsigned anchor_y: 1; // 0 is top, 1 is bottom
    unsigned _unused_: 6; 
} xrect;

#endif // _FJ_COMMON_H