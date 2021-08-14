#ifndef FJH_COLOR
#define FJH_COLOR

#include <stdint.h>

typedef uint8_t FJ_Chan; // Single color channel

typedef struct FJI_Color
{
    FJ_Chan r;
    FJ_Chan g;
    FJ_Chan b;
    FJ_Chan a;
} FJ_Color;

#endif // FJH_COLOR
