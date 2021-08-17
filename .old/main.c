#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "common.h"
#include "backend.h"

int run(FJ_WindowContext*);

int main(int argc, char *argv[])
{
    if (FJ_InitBackend())
        return 1;

    FJ_Window *win = FJ_NewWindow("hi", 800, 600);
    if (!win) {
        printf("%s\n", FJ_GetLastError());
        return 2;
    }

    printf("%zd\n", sizeof(FJ_Elem));

    FJ_RunBackend(win, &run);

    FJ_DelWindow(win);

    FJ_QuitBackend();

    return EXIT_SUCCESS;
}


int run(FJ_WindowContext *ctx)
{
    FJ_Elem elem = {
        .shape = FJ_SHAPE_ELLIPSE(100, 200, 250, 170, 1),
        .fill = FJ_FILL_COLOR(200, 100, 50),
    };

    FJ_DrawClear(ctx, NULL);

    FJ_DrawElem(ctx, &elem);

    FJ_DrawRelease(ctx);
    FJ_Delay(1000. / 60);
    return 1;
}
