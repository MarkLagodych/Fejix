#include "fejix.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[])
{
    if (fj_init()) exit(1);

    puts("Hello world!");

    fj_quit();
}