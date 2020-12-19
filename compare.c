#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "flight_structs.h"

int signum(const int x)
{
    return (!x) ? 0 : (x / abs(x));
}
int compare_time (const flight* first, const flight* second)
{
    int result = 0;
    int arr[2];
    arr[0] = signum(first->travel_time.hour - second->travel_time.hour);
    arr[1] = signum(first->travel_time.minute - second->travel_time.minute);
    result = signum(10 * arr[0] + arr[1]);
    return result;
}
int compare_date_time (const flight* first, const flight* second)
{
    int result = 0;
    int arr[4];
    arr[0] = signum(first->departure_date.year - second->departure_date.year);
    arr[1] = signum(first->departure_date.month - second->departure_date.month);
    arr[2] = signum(first->departure_date.day - second->departure_date.day);
    arr[3] = compare_time(first, second);
    result = signum(1000 * arr[0] + 100 * arr[1] + 10 * arr[2] + arr[3]);
    return result;
}
int compare_by_airport (const flight* first, const flight* second)
{
    return strcmp(first->airport_dest, second->airport_dest);
}
