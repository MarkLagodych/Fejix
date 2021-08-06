#ifndef FJH_SHAPE
#define FJH_SHAPE

enum FJ_ShapeType
{
    FJ_SHAPE_LINE,
    FJ_SHAPE_RECT,
    FJ_SHAPE_ELLIPSE,
};


/// Line drawn from (x, y) to (x+offset_x, y+offset_y)
typedef struct FJI_Line
{
    int x;
    int y;
    int offset_x;
    int offset_y;
    int width;
} FJ_Line;


typedef struct FJI_Rect
{
    int x;
    int y;
    int width;
    int height;
    int radius;
    int filled;
} FJ_Rect;


typedef struct FJI_Ellipse
{
    int x;
    int y;
    int width;
    int height;
    int filled;
} FJ_Ellipse;


typedef struct FJI_Shape
{
    enum FJ_ShapeType type;
    union {
        FJ_Line line;
        FJ_Rect rect;
        FJ_Ellipse ellipse;
    } data;
} FJ_Shape;

#endif // FJH_SHAPE
