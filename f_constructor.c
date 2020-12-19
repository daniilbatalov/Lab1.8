#include "string.h"

#include "f_constructor.h"
#include "bool_type.h"
#include "flight_structs.h"
#include "array_f.h"
bool breakfast_check (const time tt)
{
    return ((tt.hour > 4 || (tt.hour == 4 && tt.minute >= 1)) ? true : false);
}

flight flight_constructor (char* a, const time tt, const time dt, const date dd)
{
    flight result;
    result.departure_date = dd;
    result.breakfast = breakfast_check(tt);
    result.dep_time = dt;
    result.travel_time = tt;
    strcpy(result.airport_dest, a);
    return result;
};
flight flight_constructor_p (const int d, const int m, const int y, const int dh, const int dm, const int th, const int tm, char* a)
{
    date dd = {d, m, y};
    time dt = {dh, dm};
    time tt = {th, tm};
    return flight_constructor(a, tt, dt, dd);
};
