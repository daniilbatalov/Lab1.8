#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <stdio.h>

#include "flight_structs.h"

void print_main_menu();
void print_enter_menu();
void print_print_menu(const int);
void print_sort_menu(const int);
FILE* choose_stream (const int, FILE*);
void print_line(const int, FILE*);
void print_str_line(const int, FILE*);
void print_empty_line(const int, FILE*);
void print_header(const int, FILE*);
void print_empty_table(const int, FILE*);
void print_flight(const flight, const int, const int, FILE*);
void print_flights (const flight*, const int, const int, FILE*);
void print_pure_flight(const flight, FILE*);
void print_pure_flights (const flight*, const int, FILE*);

#endif // PRINT_H_INCLUDED
