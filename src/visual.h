#ifndef FJH_VISUAL
#define FJH_VISUAL

#include "common.h"

enum FJ_FillType
{
    FJ_FILL_NONE,
    FJ_FILL_COLOR,
    FJ_FILL_GRADIENT,
    FJ_FILL_IMAGE,
};

typedef struct FJI_Fill
{
    enum FJ_FillType type;
    union {
        FJ_Color color;
    } data;
} FJ_Fill;

/// The simplest drawable entity
typedef struct FJI_Elem
{
    FJ_Fill fill;
    FJ_Shape shape;
} FJ_Elem;

/// A group of FJ_Elem's
typedef struct FJI_Visual
{
    size_t length;
    FJ_Elem *elems;
} FJ_Visual;

FJ_Visual* FJ_NewVisual(size_t length);
void FJ_DelVisual(FJ_Visual*);

#endif // FJH_VISUAL