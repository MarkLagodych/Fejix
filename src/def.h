#ifndef FEJIX_H_DEF_
#define FEJIX_H_DEF_

typedef enum _FigureType
{
    FIGURE_RECTANGLE,
    FIGURE_ELLIPSE,
} FigureType;

typedef enum _Anchor {    
    ANCHOR_TOP          = 0b1000,
    ANCHOR_BOTTOM       = 0b0100,
    ANCHOR_LEFT         = 0b0010,
    ANCHOR_RIGHT        = 0b0001,
    
    ANCHOR_TOP_LEFT     = ANCHOR_TOP | ANCHOR_LEFT,
    ANCHOR_TOP_RIGHT    = ANCHOR_TOP | ANCHOR_RIGHT,
    ANCHOR_BOTTOM_LEFT  = ANCHOR_BOTTOM | ANCHOR_LEFT,
    ANCHOR_BOTTOM_RIGHT = ANCHOR_BOTTOM | ANCHOR_RIGHT,
    
    ANCHOR_VERTICAL     = ANCHOR_TOP | ANCHOR_BOTTOM,
    ANCHOR_HORIZONTAL   = ANCHOR_LEFT | ANCHOR_RIGHT,
    
    ANCHOR_CENTER       = ANCHOR_VERTICAL | ANCHOR_HORIZONTAL,
    
    ANCHOR_DEFAULT      = ANCHOR_TOP_LEFT,
} Anchor;

typedef struct _Layout
{
    int x;
    int y;
    int w;
    int h;
    Anchor anchor;
} Layout;

typedef struct _Figure
{
    FigureType type;
    Layout layout;
} Figure;

typedef struct _Visuals
{
    size_t length;
    Figure *data;
} Visuals;

typedef struct _Content
{
    size_t length;
    struct _Widget *data;
} Content;

typedef struct _Widget
{
    Layout layout;
    Visuals visuals;
    struct _Content content;
} Widget;

#endif // FEJIX_H_DEF_