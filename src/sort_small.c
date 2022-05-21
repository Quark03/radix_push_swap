//
// Created by quark on 21-05-2022.
//
#include "../push_swap.h"

void sort5(void)
{

}

void sort3(void)
{
    if (lst_length((*get_stack(A))) < 3)
    {
        if ((*get_stack(A))->content > (*get_stack(A))->next->content)
            exec_command(0);
        return ;
    }
    if ((*get_stack(A))->content > (*get_stack(A))->next->content)
    {
        exec_command(0);
    }
    if ((*get_stack(A))->next->content > (*get_stack(A))->next->next->content)
    {
        exec_command(3);
        exec_command(0);
        exec_command(6);
        if ((*get_stack(A))->content > (*get_stack(A))->next->content)
        {
            exec_command(0);
        }
    }
}

void sort_small(void)
{
    if (lst_length((*get_stack(A))) < 4)
        sort3();
    else
        sort5();
}

