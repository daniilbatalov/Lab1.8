#include <stdio.h>

#include "limit.h"
#include "get_flight.h"
#include "flight_structs.h"
#include "get_data.h"
#include "f_constructor.h"
#include "print.h"
#include "array_f.h"

void enter_flight(flight* fl, const int n)
{
    print_str_line(ON_SCREEN, stdout);
    printf("Flight #%d\n", n + 1);
    date dd = get_date();
    time dt = get_time(true);
    time tt = get_time(false);
    printf("What's the airport of destination?\n>");
    char s[STRING_LIMIT];
    gets(s);
    fl[n] = flight_constructor(s, tt, dt, dd);
}
int import_flight(FILE *file, flight* fl, const int n)
{
    int d, m, y, hd, md, th, tm = 0;
    char air[STRING_LIMIT];
    fscanf(file, "%2i.%2i.%4i %2i:%2i  %2i:%2i %[^\n]", &d, &m, &y, &hd, &md, &th, &tm, air);
    int result = 1;
    result = validate(d, UPPER_DAY, LOWER_DATE) * validate(m, UPPER_MONTH, LOWER_DATE) * validate(y, UPPER_YEAR, LOWER_DATE);
    result = result * validate(hd, UPPER_HOUR, LOWER_TIME) * validate(md, UPPER_MINUTE, LOWER_TIME) * validate(th, UPPER_NO_VALID, LOWER_TIME) * validate(tm, UPPER_MINUTE, LOWER_TIME);
    if(result)
    {
        fl[n] = flight_constructor_p(d, m, y, hd, md, th, tm, air);
    }
    return result;
}
