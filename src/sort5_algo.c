//
// Created by quark on 21-05-2022.
//
#include "../push_swap.h"

void push_max_to_b()
{
    int len = lst_length((*get_stack(A)));
    int max = get_max((*get_stack(A)));
    int max_pos = lst_index_by_value((*get_stack(A)), max);
    if (len - max_pos < len / 2)
        exec_multiple(6, len - max_pos);
    else
        exec_multiple(3, max_pos);
    exec_command(10);
}

void place_on_a()
{
    exec_command(9);
    reorder_a();
}