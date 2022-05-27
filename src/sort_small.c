//
// Created by quark on 21-05-2022.
//
#include "../push_swap.h"

void sort2(void)
{
    if ((*get_stack(A))->content > (*get_stack(A))->next->content)
        exec_command(0);
}

void sort3(void)
{
    int min_pos = lst_index_by_value((*get_stack(A)), get_min((*get_stack(A))));
    int max_pos = lst_index_by_value((*get_stack(A)), get_max((*get_stack(A))));
    if (min_pos == 0)
    {
        exec_command(3);
        exec_command(0);
        exec_command(6);
    }
    else if (min_pos == 1 && max_pos == 2)
        exec_command(0);
    else if (min_pos == 1 && max_pos == 0)
        exec_multiple(6, 2);
    else if (min_pos == 2 && max_pos == 0)
    {
        exec_command(0);
        exec_command(6);
    }
    else if (min_pos == 2 && max_pos == 1)
        exec_command(6);
}

void sort5(void)
{
    while(lst_length((*get_stack(A))) > 3)
        push_max_to_b();
    sort3();
    while (lst_length((*get_stack(B))) > 0)
        place_on_a();

}

void sort_small(void)
{
    int len = lst_length((*get_stack(A)));
    if (len == 3)
        sort3();
    else if (len == 2)
        sort2();
    else
        sort5();
}

