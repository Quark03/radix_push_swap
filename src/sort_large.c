//
// Created by quark on 21-05-2022.
//
#include "../push_swap.h"

int flip_number(int nbr)
{
    int SIZE = sizeof(int) * 8 - 1;
    return nbr ^ (1 << SIZE);
}


/**
 * Flips the last bit of all numbers on the stack A
 */
void flip_numbers()
{
    t_stack *head;

    head = (*get_stack(A));
    while (head)
    {
        head->content = flip_number(head->content);
        head = head->next;
    }
}


/**
 * Sort When Length > 5
 * @param negative 1 if there are negative numbers
 */
void sort_large(int negative)
{
    int length = lst_length((*get_stack(A)));
    int max = get_max((*get_stack(A)));
    int max_bits = 0;
    while ((max >> max_bits) != 0) ++max_bits;

    int i = 0;
    while (i < max_bits)
    {
        int j = 0;
        while (j < length)
        {
            int num = (*get_stack(A))->content;
            if (((num >> i) & 1) == 1) exec_command(3);
            else exec_command(10);
            ++j;
        }
        while(lst_length((*get_stack(B))) > 0) exec_command(9);
        if (negative && is_sorted((*get_stack(A)))) {
            break;
        }
        ++i;
    }

    // printf("LEN:%d, MAX: %d | With %d bits\n", length, max, max_bits);
}