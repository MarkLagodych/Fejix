/**
@file shape.h

@brief Basic primitives that the backend can draw
*/

#ifndef FJH_SHAPE
#define FJH_SHAPE

#include "common.h"

enum FJ_ShapeType
{
    FJ_SHAPE_T_LINE,
    FJ_SHAPE_T_RECT,
    FJ_SHAPE_T_ELLIPSE,
    FJ_SHAPE_T_POLYGON,
};


/// Line drawn from (x, y) to (x+ox, y+oy)
typedef struct FJI_Line
{
    uint16_t x;
    uint16_t y;
    uint16_t ox; // Offset X
    uint16_t oy; // Offset Y
    uint16_t w;  // Width
} FJ_Line;


typedef struct FJI_Rect
{
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
    uint16_t r; // Radius
} FJ_Rect;


typedef struct FJI_Ellipse
{
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
} FJ_Ellipse;


// Not a shape but a pouint16_t of the polygon
typedef struct FJI_Point
{
    uint16_t x;
    uint16_t y;
} FJ_Point;


typedef struct FJI_Polygon
{
    uint16_t length;
    FJ_Point *points;
} FJ_Polygon;


typedef struct FJI_Shape
{
    enum FJ_ShapeType type;
    union FJI_ShapeData {
        FJ_Line line;
        FJ_Rect rect;
        FJ_Ellipse ellipse;
        FJ_Polygon polygon;
    } data;
    uint8_t filled; /// If 0, the shape is drawn as ouline
} FJ_Shape;

#define FJ_SHAPE_LINE(x, y, ox, oy, w)            \
    ( (FJ_Shape) {                                \
        .type = FJ_SHAPE_T_LINE,                  \
        .data.line = (FJ_Line) {                  \
            x, y, ox, oy, w                       \
        },                                        \
        .filled = 0,                              \
    } )

#define FJ_SHAPE_RECT(x, y, w, h, r, _filled)     \
    ( (FJ_Shape) {                                \
        .type = FJ_SHAPE_T_RECT,                  \
        .data.rect = (FJ_Rect) {                  \
            x, y, w, h, r,                        \
        },                                        \
        .filled = _filled,                        \
    } )

#define FJ_SHAPE_ELLIPSE(x, y, w, h, _filled)     \
    ( (FJ_Shape) {                                \
        .type = FJ_SHAPE_T_ELLIPSE,               \
        .data.ellipse = (FJ_Ellipse) {            \
            x, y, w, h,                           \
        },                                        \
        .filled = _filled,                        \
    } )

#define FJ_SHAPE_POLYGON(length, points, _filled) \
    ( (FJ_Shape) {                                \
        .type = FJ_SHAPE_T_POLYGON,               \
        .data.polygon = (FJ_Polygon) {            \
            length, points                        \
        },                                        \
        .filled = _filled,                        \
    } )

#endif // FJH_SHAPE
