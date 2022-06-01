/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:06:00 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/01 18:08:56 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
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
 * (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
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
