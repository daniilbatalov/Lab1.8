#include "flight_structs.h"
#include "copy.h"

void swap_flights (flight* fl, const int to_swap1, const int to_swap2)
{
    flight temp;
    copy_flight(&temp, &fl[to_swap1]);
    copy_flight(&fl[to_swap1], &fl[to_swap2]);
    copy_flight(&fl[to_swap2], &temp);
}
void sort_b (flight* fl, const int amount, const int order, int (*cmp)(const flight*, const flight*))
{
    for(int i = 0 ; i < amount - 1; i++)
    {
        for(int j = 0 ; j < amount - i - 1 ; j++)
        {
            if(cmp(&fl[j], &fl[j + 1]) == order)
            {
                swap_flights(fl, j, j + 1);
            }
        }
    }
}
