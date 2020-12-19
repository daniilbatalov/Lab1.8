#include "flight_structs.h"
#include "copy.h"
#include "array_f.h"

void delete_flight (flight* fl, int* amount, const int to_delete)
{
    for(int i = to_delete; i < *amount - 1; i++)
    {
        copy_flight(&fl[i], &fl[i + 1]);
    }
    append_array_f(fl, -1);
    (*amount)--;
}
