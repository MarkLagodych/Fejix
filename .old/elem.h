/**
@file elem.h

@brief Implements a minimal drawable entity (called Elem)
*/

#ifndef FJH_ELEM
#define FJH_ELEM

#include "common.h"

typedef struct FJI_Elem
{
    FJ_Shape shape;
    FJ_Fill  fill;
} FJ_Elem;

#endif // FJH_ELEM
