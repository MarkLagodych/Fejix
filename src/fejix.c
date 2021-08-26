#include "fejix.h"

#include "fj_backend.h"

void _handleEvent();
void _update();


int fj_init()
{
    return fj_initBackend();
}


void fj_quit()
{
    fj_quitBackend();
}


void fj_loop()
{
    fj_runBackend(&_handleEvent, &_update);
}


void _handleEvent()
{

}


void _update()
{

}