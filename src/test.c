#include "fejix.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* args[])
{
    if (fj_init()) exit(1);

    fj_window *win = fj_newWindow(
        "Hello, world!",
        0, 0, 800, 600,
        FJ_WM_POS_ANYWHERE, 0
    );

    fj_rect r = {.x = 0, .y = 0, .w = 200, .h = 100};
    fj_simpleShape s = {.r = 20, .t = -1};
    fj_color c = {.r = 255, .g = 0x77, .b = 0, .a = 0};
    fj_drawRectColor(win, &r, &s, &c);
    fj_updateWindow(win);

    fj_loop();

    fj_delWindow(win);

    fj_quit();
}