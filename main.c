#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>

#include "flight_structs.h"
#include "bool_type.h"
#include "limit.h"
#include "compare.h"
#include "print.h"
#include "get_data.h"
#include "array_f.h"
#include "get_flight.h"
#include "delete_f.h"
#include "exception.h"
#include "sort.h"
#include "change.h"

int main()
{
    int pick;
    int number, amount = 0;
    int to_del;
    int order = 1;
    int way = 1;
    flight* flights = NULL;
    FILE *input;
    FILE *output;
    do
    {
        system("cls");
        int print_pick, enter_pick, sort_pick;
        print_main_menu();
        pick = get_int("", LOWER_MENU, UPPER_MENU);
        switch (pick)
        {
        case 1:
            do
            {
                system("cls");
                print_enter_menu();
                enter_pick = get_int("", LOWER_MENU, UPPER_PRINT_MENU);
                switch (enter_pick)
                {
                case 1:
                    if (!amount)
                    {
                        number = get_int("How many flights are there?\n>", LOWER_FLIGHTS, UPPER_NO_VALID);
                    }
                    else
                    {
                        number = get_int("How many flights would you like to add?\n>", LOWER_FLIGHTS, UPPER_NO_VALID);
                    }
                    amount += number;
                    if (!flights)
                    {
                        flights = alloc_array_f(number);
                    }
                    else
                    {
                        flights = append_array_f(flights, number);
                    }
                    for(int i = amount - number; i < amount; i++)
                    {
                        enter_flight(flights, i);
                    }
                    enter_pick = UPPER_ENTER_MENU;
                    break;
                case 2:
                    if((input = fopen("input.txt", "r")) == NULL)
                    {
                        exept("Error: cannot open file.\n", 1);
                    }
                    ;
                    fscanf(input, "%i", &number);
                    amount += number;
                    if (!flights)
                    {
                        flights = alloc_array_f(number);
                    }
                    else
                    {
                        flights = append_array_f(flights, number);
                    }
                    for(int i = amount - number; i < amount; i++)
                    {
                        if (!import_flight(input, flights, i))
                        {
                            exept("Error: incorrect data!", 1);
                        }
                    }
                    fclose(input);
                    enter_pick = UPPER_ENTER_MENU;
                    break;
                }
            }
            while (enter_pick != UPPER_ENTER_MENU);
            break;
        case 2:
            if (!amount)
            {
                puts("Warning! Nothing to delete");
                getchar();
            }
            else
            {
                to_del = get_int("Which flight do you want to delete?\n>", 1, amount);
                delete_flight(flights, &amount, to_del - 1);
            }
            break;
        case 3:
            do
            {
                system("cls");
                print_sort_menu(order);
                sort_pick = get_int("", LOWER_MENU, UPPER_SORT_MENU);
                switch (sort_pick)
                {
                case 1:
                    sort_b(flights, amount, order, compare_date_time);
                    sort_pick = UPPER_SORT_MENU;
                    break;
                case 2:
                case 3:
                    sort_b(flights, amount, order, compare_time);
                    sort_pick = UPPER_SORT_MENU;
                    break;
                case 4:
                    sort_b(flights, amount, order, compare_by_airport);
                    sort_pick = UPPER_SORT_MENU;
                    break;
                case 5:
                    change_order(&order);
                    break;
                }
            }
            while (sort_pick != UPPER_SORT_MENU);
            break;
        case 4:
            do
            {
                system("cls");
                print_print_menu(way);
                print_pick = get_int("", LOWER_MENU, UPPER_PRINT_MENU);
                switch (print_pick)
                {
                case 1:
                    print_flights(flights, amount, ON_SCREEN, stdout);
                    getchar();
                    print_pick = UPPER_PRINT_MENU;
                    break;
                case 2:

                    switch (way)
                    {
                    case 1:
                        if((output = fopen("output.txt", "w")) == NULL)
                        {
                            exept("Error: cannot open file.\n", 1);
                        }
                        print_pure_flights(flights, amount, output);
                        fclose(output);
                        break;
                    case 0:
                        if((output = fopen("input.txt", "w")) == NULL)
                        {
                            exept("Error: cannot open file.\n", 1);
                        }
                        print_pure_flights(flights, amount, output);
                        fclose(output);
                        break;
                    case -1:
                        if((output = fopen("output.txt", "w")) == NULL)
                        {
                            exept("Error: cannot open file.\n", 1);
                        }
                        print_flights(flights, amount, IN_FILE, output);
                        fclose(output);
                        break;
                    }
                    print_pick = UPPER_PRINT_MENU;
                    break;
                case 3:
                    change_way(&way);
                    break;
                }
            }
            while (print_pick != UPPER_PRINT_MENU);
            break;
        case 5:
            if (!amount)
            {
                puts("Warning! Nothing to delete");
                getchar();
            }
            else
            {
                puts("Warning! This will delete every flight");
                getchar();
                while (amount != 0)
                {
                    delete_flight(flights, &amount, 0);
                }
                flights = NULL;
            }
            break;
        }

    }
    while (pick != UPPER_MENU);
    free(flights);
    flights = NULL;
    return 0;
}
