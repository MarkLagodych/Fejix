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

typedef struct {
    int x;
    int y;
} fj_point;

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

typedef struct {
    int r; // Corner radius
    int t; // Line thickness (-1 if the shape is filled)
} fj_simpleShape; /// Additional fields for simple shapes

enum fj_fillType
{
    FJ_FILL_NONE,
    FJ_FILL_COLOR,
};

enum fj_shapeType {
    FJ_SHAPE_LINE,
    FJ_SHAPE_RECT,
    FJ_SHAPE_ELLIPSE,
};

typedef struct {
    union {
        fj_color color;
        void *data;
    } fill;

    fj_xrect shapeArea;

    union {
        fj_simpleShape simple;
        void *data;
    } shape;

    enum fj_fillType fillType;

    enum fj_shapeType shapeType;

} fj_elem;

#endif // _FJ_COMMON_H