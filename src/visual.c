#include "visual.h"

#include <malloc.h>

FJ_Visual* FJ_NewVisual(size_t length)
{
    FJ_Visual *v = (FJ_Visual*) calloc(length, sizeof(FJ_Visual));
    FJ_ASSERT(v != NULL, "Memory allocation failed for FJ_Visual");
    v->length = 0;
    v->elems = NULL;
    return v;
}


void FJ_DelVisual(FJ_Visual *v)
{
    free(v->elems);
    v->length = 0;
    v->elems = NULL;
}