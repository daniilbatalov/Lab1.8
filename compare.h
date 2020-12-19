#ifndef COMPARE_H_INCLUDED
#define COMPARE_H_INCLUDED

#include "flight_structs.h"

int signum(const int);
int compare_time (const flight*, const flight*);
int compare_date_time (const flight*, const flight*);
int compare_by_airport (const flight*, const flight*);

#endif // COMPARE_H_INCLUDED
