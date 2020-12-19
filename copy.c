#include <string.h>
#include <stdio.h>

#include "copy.h"
#include "flight_structs.h"

void copy_date (date* to, const date* from)
{
    to->day = from->day;
    to->month = from->month;
    to->year = from->year;
}
void copy_time (time* to, const time* from)
{
    to->hour = from->hour;
    to->minute = from->minute;
}
void copy_flight (flight* to, const flight* from)
{
    strcpy(to->airport_dest, from->airport_dest);
    to->breakfast = from->breakfast;
    copy_date(&to->departure_date, &from->departure_date);
    copy_time(&to->dep_time, &from->dep_time);
    copy_time(&to->travel_time, &from->travel_time);
}
