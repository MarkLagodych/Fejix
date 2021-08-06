#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <SDL2/SDL.h>
#include "common.h"
#include "backend.h"

int main(int argc, char *argv[])
{
    FJ_Window *win = FJ_NewWindow("hi", 800, 600);
    if (!win) printf("%s\n", FJ_GetLastError());
    SDL_Delay(2000);
    FJ_DelWindow(win);

    return EXIT_SUCCESS;
}
