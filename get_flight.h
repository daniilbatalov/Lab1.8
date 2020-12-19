#ifndef GET_FLIGHT_H_INCLUDED
#define GET_FLIGHT_H_INCLUDED

#include <stdio.h>

#include "flight_structs.h"

void enter_flight(flight*, const int);
int import_flight(FILE*, flight*, const int);

#endif // GET_FLIGHT_H_INCLUDED
