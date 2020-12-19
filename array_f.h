#ifndef ARRAY_F_H_INCLUDED
#define ARRAY_F_H_INCLUDED

#include <stdlib.h>
#include <malloc.h>

#include "flight_structs.h"

flight* alloc_array_f (const size_t);
flight* append_array_f (flight*, const size_t);
char* alloc_c_string (const size_t);
char* append_c_string (char*, const size_t);
#endif // ARRAY_F_H_INCLUDED
