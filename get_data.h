#ifndef GET_DATA_H_INCLUDED
#define GET_DATA_H_INCLUDED

#include "flight_structs.h"
#include "bool_type.h"

int get_int(const char*, const int, const int);
date get_date();
time get_time(const bool);
bool validate (const int, const int, const int);
void clear_stdin();
#endif // GET_DATA_H_INCLUDED
