#include <stdio.h>
#include <stdlib.h>

#include "exception.h"

void exept (const char* error_message, const int code)
{
    printf(error_message);
    exit(code);
}
