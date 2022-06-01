/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:30:01 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/01 18:08:59 by acinca-f         ###   ########.fr       */
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
 * (rotate a) Shift up all elements of stack a by 1.
 * The first element becomes the last one.
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
 * rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one
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
