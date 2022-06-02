/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:33:04 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/02 13:53:47 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort2(void)
{
	if ((*get_stack(A))->content > (*get_stack(A))->next->content)
		exec_command(0);
}

void	sort3(void)
{
	int	min_pos;
	int	max_pos;

	min_pos = lst_index_by_value((*get_stack(A)), get_min((*get_stack(A))));
	max_pos = lst_index_by_value((*get_stack(A)), get_max((*get_stack(A))));
	if (is_sorted((*get_stack(A))))
		return ;
	if (min_pos == 0 && max_pos == 1)
	{
		exec_command(6);
		exec_command(0);
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

void	sort_small(void)
{
	int	len;

	len = lst_length((*get_stack(A)));
	if (len == 3)
		sort3();
	else if (len == 2)
		sort2();
	else
		sort5();
}
