/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:08:53 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/02 13:53:43 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_b(void)
{
	if (lst_length((*get_stack(B))) == 2)
		if ((*get_stack(B))->content > (*get_stack(B))->next->content)
			exec_command(1);
}

void	clear_stack_a(void)
{
	int	max_pos;
	int	len;

	max_pos = lst_index_by_value((*get_stack(A)), get_max((*get_stack(A))));
	len = lst_length((*get_stack(A)));
	if (max_pos == 1)
		exec_multiple(3, 1);
	else if (max_pos == 2)
		exec_multiple(3, 2);
	else if (max_pos == 3 && len == 5)
		exec_multiple(6, 2);
	else if (max_pos == 3 && len == 4)
		exec_multiple(6, 1);
	else if (max_pos == 4 && len == 5)
		exec_multiple(6, 1);
	exec_command(10);
}

void	sort5(void)
{
	while (lst_length((*get_stack(A))) > 3)
	{
		clear_stack_a();
	}
	sort_b();
	sort3();
	while (lst_length((*get_stack(B))) > 0)
	{
		exec_command(9);
		exec_command(3);
	}
}
