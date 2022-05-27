/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:30:01 by acinca-f          #+#    #+#             */
/*   Updated: 2022/03/16 18:11:05 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/**
 * a (push a): Take the first element at the
 * top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
void	pa(void)
{
	t_stack	*stack_b;
	t_stack	*temp;

	if ((*get_stack(B)) == NULL)
		return ;
	stack_b = (*get_stack(B));
	if ((*get_stack(A)) == NULL)
	{
		temp = lst_new(stack_b->content);
		(*get_stack(A)) = temp;
	}
	else
		lst_add_front(get_stack(A), stack_b->content);
	(*get_stack(B)) = stack_b->next;
	ft_putstr_fd("pa\n", 1);
}

/**
 * (push b): Take the first element at the
 * top of a and put it at the top of b.
 * Do nothing if a is empty.
 */
void	pb(void)
{
	t_stack	*stack_a;
	t_stack	*temp;

	if ((*get_stack(A)) == NULL)
		return ;
	stack_a = (*get_stack(A));
	if ((*get_stack(B)) == NULL)
	{
		temp = lst_new(stack_a->content);
		(*get_stack(B)) = temp;
	}
	else
		lst_add_front(get_stack(B), stack_a->content);
	(*get_stack(A)) = stack_a->next;
	ft_putstr_fd("pb\n", 1);
}

/**
 * (rotate a) Shift up all elements of stack a by 1. The first element becomes the last one.
 * @param print If to print the message
 */
void	ra(int print)
{
    t_stack	*head;
    t_stack	*temp;

    head = (*get_stack(A));
    temp = head;
    if (temp == NULL)
        return ;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;
    (*get_stack(A)) = head->next;
    temp = temp->next;
    temp->next = NULL;
    if (print)
        ft_putstr_fd("ra\n", 1);
}

/**
 * rotate b): Shift up all elements of stack b by 1. The first element becomes the last one
 * @param print
 */
void	rb(int print)
{
    t_stack	*head;
    t_stack	*temp;

    head = (*get_stack(B));
    temp = head;
    if (temp == NULL)
        return ;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;
    (*get_stack(B)) = head->next;
    temp = temp->next;
    temp->next = NULL;
    if (print)
        ft_putstr_fd("rb\n", 1);
}

/**
 * Rotate both. ra + rb
 */
void	rr(void)
{
    ra(0);
    rb(0);
    ft_putstr_fd("rr\n", 1);
}

/**
 * (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
 * @param print
 */
void	rra(int print)
{
    t_stack	*temp;
    t_stack	*save;
    int		len;

    temp = (*get_stack(A));
    if (temp == NULL)
        return ;
    len = 0;
    while (temp->next != NULL && len < lst_length((*get_stack(A))) - 2)
    {
        temp = temp->next;
        len++;
    }
    save = temp->next;
    temp->next = NULL;
    save->next = (*get_stack(A));
    (*get_stack(A)) = save;
    if (print)
        ft_putstr_fd("rra\n", 1);
}

/**
 * (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
 * @param print
 */
void	rrb(int print)
{
    t_stack	*temp;
    t_stack	*save;
    int		len;

    temp = (*get_stack(B));
    if (temp == NULL)
        return ;
    len = 0;
    while (temp->next != NULL && len < lst_length((*get_stack(B))) - 2)
    {
        temp = temp->next;
        len++;
    }
    save = temp->next;
    temp->next = NULL;
    save->next = (*get_stack(B));
    (*get_stack(B)) = save;
    if (print)
        ft_putstr_fd("rrb\n", 1);
}

/**
 * Reverse Rotate both. RRA + RRB
 */
void	rrr(void)
{
    rra(0);
    rrb(0);
    ft_putstr_fd("rrr\n", 1);
}

/**
 * (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
 * @param print
 */
void	sa(int print)
{
    t_stack	*node_1;
    t_stack	*node_2;
    t_stack	*node_3;

    if (lst_length((*get_stack(A))) < 2)
        return ;
    node_1 = (*get_stack(A));
    node_2 = node_1->next;
    node_3 = node_2->next;
    node_2->next = node_1;
    node_1->next = node_3;
    (*get_stack(A)) = node_2;
    if (print)
        ft_putstr_fd("sa\n", 1);
}

/**
 * (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements
 * @param print
 */
void	sb(int print)
{
    t_stack	*node_1;
    t_stack	*node_2;
    t_stack	*node_3;

    if (lst_length((*get_stack(B))) < 2)
        return ;
    node_1 = (*get_stack(B));
    node_2 = node_1->next;
    node_3 = node_2->next;
    node_2->next = node_1;
    node_1->next = node_3;
    (*get_stack(B)) = node_2;
    if (print)
        ft_putstr_fd("sb\n", 1);
}

/**
 * Swap both. SA + SB
 */
void	ss(void)
{
    sa(0);
    sb(0);
    ft_putstr_fd("ss\n", 1);
}

