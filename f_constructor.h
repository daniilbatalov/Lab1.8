#ifndef F_CONSTRUCTOR_H_INCLUDED
#define F_CONSTRUCTOR_H_INCLUDED

#include "bool_type.h"
#include "flight_structs.h"

bool breakfast_check (const time);
flight flight_constructor (char*, const time, const time, const date);
flight flight_constructor_p (const int, const int, const int, const int, const int, const int, const int, char*);

#endif // F_CONSTRUCTOR_H_INCLUDED
