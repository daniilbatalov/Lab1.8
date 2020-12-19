#include <stdlib.h>
#include <malloc.h>

#include "array_f.h"
#include "flight_structs.h"

flight* alloc_array_f (const size_t arr_size)
{
    return (flight*)malloc(arr_size * sizeof(flight));
}
flight* append_array_f (flight* arr, const size_t by_size)
{
    size_t prev_size = _msize(arr);
    size_t new_size = prev_size + (sizeof(flight) * by_size);
    return (flight*)realloc(arr, new_size);
}
char* alloc_c_string (const size_t strl)
{
    return (char*)malloc(strl * sizeof(char));
}
char* append_c_string (char* str, const size_t by_size)
{
    size_t prev_size = _msize(str);
    size_t new_size = prev_size + (sizeof(char) * by_size);
    return (char*)realloc(str, new_size);
}
