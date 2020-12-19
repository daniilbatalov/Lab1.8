#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "flight_structs.h"

void swap_flights (flight*, const int, const int);
void sort_b (flight*, const int, const int, int (*)(const flight*, const flight*));

#endif // SORT_H_INCLUDED
