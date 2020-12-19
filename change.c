#include "change.h"

void change_order (int *order)
{
     (*order == 1) ? (*order = -1) : (*order = 1);
}

void change_way (int *way)
{
     (*way == 1) ? (*way = 0) : ((*way == 0) ? (*way = -1) : (*way = 1));
}
