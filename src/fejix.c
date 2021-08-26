#include "fejix.h"

#include "fj_backend.h"

int fj_init()
{
    return fj_initBackend();
}

void fj_quit()
{
    fj_quitBackend();
}