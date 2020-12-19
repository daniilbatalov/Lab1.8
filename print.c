#include <stdio.h>

#include "print.h"
#include "flight_structs.h"

void print_main_menu()
{
    printf("What do you want to do?\n");
    printf("1. Enter the flights\n");
    printf("2. Delete the flight\n");
    printf("3. Sort the flights\n");
    printf("4. Print the flights\n");
    printf("5. Clear all the flights\n");
    printf("6. Exit\n");
    printf(">");
}

void print_enter_menu()
{
    printf("How do you want to enter the flights?\n");
    printf("1. Enter the flights manually\n");
    printf("2. Import the filghts from input.txt\n");
    printf("3. Back\n");
    printf(">");
}

void print_print_menu(const int way)
{
    printf("How do you want to print the flights?\n");
    printf("1. Print the flights on screen\n");
    printf("2. Export the filghts into %s.txt\n", ((way == 0) ? "input" : "output"));
    printf("3. Change the way of export: %s\n", ((way == 1) ? "pure" : (way == 0 ? "save" : "as table")));
    printf("4. Back\n");
    printf(">");
}

void print_sort_menu(const int order)
{
    printf("How do you want to sort the flights?\n");
    printf("1. Sort by date and time of departure\n");
    printf("2. Sort by travel time\n");
    printf("3. Sort by availability of breakfast\n");
    printf("4. Sort by airport of destination\n");
    printf("5. Change the sort order: %s\n", ((order == 1) ? "ascending" : "descending"));
    printf("6. Back\n");
    printf(">");
}

FILE* choose_stream (const int mode, FILE* out)
{
    return ((mode == 1) ? stdout : out);
}

void print_line(const int mode, FILE* out)
{
    fprintf(choose_stream(mode, out) ,"+----+------------+--------+-------------+-----------+---------------+\n");
}

void print_str_line(const int mode, FILE* out)
{
    fprintf(choose_stream(mode, out), "----------------------------\n");
}

void print_empty_line(const int mode, FILE* out)
{
    fprintf(choose_stream(mode, out), "+--------------------------------------------------------------------+\n");
}

void print_header(const int mode, FILE* out)
{
    print_line(mode, out);
    fprintf(choose_stream(mode, out), "| No |    Date    |  Time  | Travel time | Breakfast |    Airport    |\n");
}

void print_empty_table(const int mode, FILE* out)
{
    print_empty_line(mode, out);
    fprintf(choose_stream(mode, out), "|                     There's no flights yet...                      |\n");
    print_empty_line(mode, out);
}

void print_flight(const flight fl, const int i, const int mode, FILE* out)
{
    char* b = fl.breakfast ? "+" : "-";
    print_line(mode, out);
    fprintf(choose_stream(mode, out), "| %2i | %02d.%02d.%04d | %02d:%02d  |    %02d:%02d    |     %s     | %13s |\n", i, fl.departure_date.day, fl.departure_date.month, fl.departure_date.year, fl.dep_time.hour, fl.dep_time.minute, fl.travel_time.hour, fl.travel_time.minute, b, fl.airport_dest);
}

void print_flights (const flight* flights, const int amount, const int mode, FILE* out)
{
    print_header(mode, out);
    if (amount == 0)
    {
        print_empty_table(mode, out);
    }
    else
    {
        for(int i = 0; i < amount; i++)
        {
            print_flight(flights[i], i + 1, mode, out);
        }
        print_line(mode, out);
    }
}

void print_pure_flight(const flight fl, FILE* out)
{
    fprintf(out, "%02d.%02d.%04d %02d:%02d %02d:%02d %s\n", fl.departure_date.day, fl.departure_date.month, fl.departure_date.year, fl.dep_time.hour, fl.dep_time.minute, fl.travel_time.hour, fl.travel_time.minute, fl.airport_dest);
}

void print_pure_flights (const flight* flights, const int amount, FILE* out)
{
        fprintf(out, "%i\n", amount);
        for(int i = 0; i < amount; i++)
        {
            print_pure_flight(flights[i], out);
        }
}
