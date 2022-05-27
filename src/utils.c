//
// Created by quark on 12-05-2022.
//

#include "../push_swap.h"

/**
 * @param cmd Command to print
 * 0 -> SA
 * 1 -> SB
 * 2 -> SS
 * 3 -> RA
 * 4 -> RB
 * 5 -> RR
 * 6 -> RRA
 * 7 -> RRB
 * 8 -> RRR
 * 9 -> PA
 * 10 -> PB
 */
void exec_command(int cmd)
{
    if (cmd == 0)
        sa(1);
    else if (cmd == 1)
        sb(1);
    else if (cmd == 2)
        ss();
    else if (cmd == 3)
        ra(1);
    else if (cmd == 4)
        rb(1);
    else if (cmd == 5)
        rr();
    else if (cmd == 6)
        rra(1);
    else if (cmd == 7)
        rrb(1);
    else if (cmd == 8)
        rrr();
    else if (cmd == 9)
        pa();
    else if (cmd == 10)
        pb();
}

void exec_multiple(int cmd, int rep)
{
    int i = 0;
    while (i++ < rep)
        exec_command(cmd);
}

/**
 * Check if list is ordered
 * @param head
 * @return 0 if not ordered; 1 if ordered
 */
int is_sorted(t_stack *head)
{
    while (head && head->next)
    {
        if (head->content > head->next->content)
            return (0);
        head = head->next;
    }
    return (1);
}

int get_min(t_stack *head)
{
    int min;

    min = INT_MAX;
    while (head)
    {
        if (head->content < min)
            min = head->content;
        head = head->next;
    }
    return (min);
}

int get_max(t_stack *head)
{
    int max;

    max = INT_MIN;
    while (head)
    {
        if (head->content > max)
            max = head->content;
        head = head->next;
    }
    return (max);
}

/**
 * Get the stack ordered
 */
void reorder_a(void)
{
    int min = get_min((*get_stack(A)));
    int pos = lst_index_by_value((*get_stack(A)), min);
    int len = lst_length((*get_stack(A)));
    int offset = len - pos;
    int half = len / 2;

    if (offset > half)
    {
        int moves = len - offset;
        while (moves-- > 0)
            exec_command(3);
    }
    else
    {
        while (offset-- > 0)
            exec_command(6);
    }
}

/**
 * Count the amount of times a given number appears in a list
 * @param nbr
 * @param head
 * @return
 */
int count_occurrences(int nbr, t_stack *head)
{
    int counter = 0;
    while (head)
    {
        if (head->content == nbr)
            counter++;
        head = head->next;
    }
    return counter;
}

/**
 * Check if the stack has repeated numbers
 * @param head
 * @return 1 if it has, 0 if not
 */
int has_repeated_numbers(t_stack *head)
{
    t_stack *fixed = head;
    while (head)
    {
        if (count_occurrences(head->content, fixed) != 1)
            return (1);
        head = head->next;
    }
    return (0);
}

/**
 * Print a given list
 * @param head
 */
void	print_list(t_stack *head)
{
    while (head)
    {
        ft_putnbr_fd(head->content, 1);
        ft_putstr_fd(" ", 1);
        head = head->next;
    }
}

int has_negative(t_stack *head)
{
    while (head)
    {
        if (head->content < 0)
            return 1;
        head = head->next;
    }
    return 0;
}

/**
 * Print Stack
 * @param stack
 */
void	print_stack(t_type stack)
{
    t_stack	*head;
    t_stack	*temp;

    ft_putstr_fd("Stack", 1);
    if (stack == A)
        ft_putstr_fd(" A: ", 1);
    else
        ft_putstr_fd(" B: ", 1);
    head = (*get_stack(stack));
    temp = head;
    if (!head)
    {
        ft_putstr_fd("(EMPTY)\n", 1);
        return ;
    }
    while (temp != NULL)
    {
        ft_putnbr_fd(temp->content, 1);
        ft_putstr_fd(" ", 1);
        temp = temp->next;
    }
    ft_putstr_fd("\n", 1);
}