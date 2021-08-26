#include "fejix.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* args[])
{
    if (fj_init()) exit(1);

    fj_window *win = fj_newWindow("Hello world!", 0, 0, 800, 600, FJ_WM_POS_ANYWHERE, 0);

    usleep(2e6);

    fj_delWindow(win);

    fj_quit();
}