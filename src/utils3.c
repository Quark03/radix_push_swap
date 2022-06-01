/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:43:37 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/01 20:48:07 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
