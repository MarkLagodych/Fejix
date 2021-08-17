#include "error.h"

static const char *last_error_message = NULL;


const char* FJ_GetLastError(void)
{
    return last_error_message;
}


void FJ_ClearLastError(void)
{
    last_error_message = NULL;
}


void FJ_SetError(const char *error_description)
{
    last_error_message = error_description;
}
