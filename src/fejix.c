#include "fejix.h"

#include "fj_backend.h"

int fj_init()
{
    return fj_init_backend();
}

void fj_quit()
{
    fj_quit_backend();
}