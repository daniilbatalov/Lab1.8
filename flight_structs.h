#ifndef FLIGHT_STRUCTS_H_INCLUDED
#define FLIGHT_STRUCTS_H_INCLUDED

#include "bool_type.h"
#include "limit.h"

typedef struct flight flight;
typedef struct time time;
typedef struct date date;

struct date
{
    int day;
    int month;
    int year;
};
struct time
{
    int hour;
    int minute;
};
struct flight
{
    date departure_date;
    time dep_time;
    time travel_time;
    bool breakfast;
    char airport_dest[STRING_LIMIT];
};
#endif // FLIGHT_STRUCTS_H_INCLUDED
