#include <stdio.h>

#include "get_data.h"
#include "limit.h"
#include "flight_structs.h"
#include "bool_type.h"

int get_int(const char* message, const int lower, const int upper)
{
    char str[STRING_LIMIT];
    int x = 0;
    printf(message);
    fgets(str, sizeof(str), stdin);
    while (sscanf (str, "%d", &x) != 1 || x < lower || x > upper)
    {
        printf("Enter correct value!\n>");
        fgets(str, sizeof(str), stdin);
    }
    return x;
}
date get_date()
{
    date dt;
    dt.day = get_int("Enter the day of the flight:\n>", LOWER_DATE, UPPER_DAY);
    dt.month = get_int("Enter the month of the flight:\n>", LOWER_DATE, UPPER_MONTH);
    dt.year = get_int("Enter the year of the flight:\n>", LOWER_DATE, UPPER_YEAR);
    return dt;
}
time get_time(const bool val)
{
    time t;
    if(val)
    {
        t.hour = get_int("Enter the hour of departure:\n>", LOWER_TIME, UPPER_HOUR) % UPPER_HOUR;
        t.minute = get_int("Enter the minute of departure:\n>", LOWER_TIME, UPPER_MINUTE) % UPPER_MINUTE;
    }
    else
    {
        t.hour = get_int("How many hours the flight will be?\n>", LOWER_TIME, UPPER_NO_VALID);
        t.minute = get_int("How many minutes the flight will be?\n>", LOWER_TIME, UPPER_MINUTE);
    }
    return t;
}

bool validate (const int value, const int upper, const int lower)
{
    return ((value <= upper) && (value >= lower)) ? true : false;
}
void clear_stdin()
{
	int ch = getchar();
	while (ch != '\n' && ch != EOF)
	{
		ch = getchar();
	}
}
