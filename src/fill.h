/**
@file fill.h

@brief Fill is an entity that describes how a particular shape should be painted
*/

#ifndef FJH_FILL
#define FJH_FILL

#include "color.h"

enum FJ_FillType
{
    FJ_FILL_T_NONE,
    FJ_FILL_T_COLOR,
    FJ_FILL_T_GRADIENT_LINEAR,
    FJ_FILL_T_GRADIENT_RADIAL,
};

typedef struct FJI_Gradient
{
    FJ_Color dummy;
} FJ_Gradient;

typedef struct FJI_Fill
{
    enum FJ_FillType type;
    union FJI_FillData {
        FJ_Color color;
        FJ_Gradient *gradient;
    } data;
} FJ_Fill;

#define FJ_FILL_NONE \
    ( (FJ_Fill) { FJ_FILL_T_NONE, { {0} } } )

#define FJ_FILL_COLORA(r, g, b, a)  \
    ( (FJ_Fill) {                   \
        FJ_FILL_T_COLOR,            \
        {                           \
            (FJ_Color) {            \
                (r), (g), (b), (a)  \
            }                       \
        }                           \
    } )

#define FJ_FILL_COLOR(r, g, b)  FJ_FILL_COLORA( (r), (g), (b), 0xff )

#endif // FJH_FILL
