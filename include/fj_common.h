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

/// Rectangle with pixel/percent dimensions
typedef struct {
    int x;
    int y;
    int w;
    int h;
} fj_urect;

typedef struct {
    fj_rect area;
} fj_layout;

typedef struct {
    enum {
        FJ_SHAPE_LINE,
        FJ_SHAPE_RECT,
    } shape_type;

    float 
} fj_shape;

#endif // _FJ_COMMON_H