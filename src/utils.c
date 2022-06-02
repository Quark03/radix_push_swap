/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:47:04 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/02 13:52:12 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	exec_command(int cmd)
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

void	exec_multiple(int cmd, int rep)
{
	int	i;

	i = 0;
	while (i++ < rep)
		exec_command(cmd);
}

/**
 * Check if list is ordered
 * @param head
 * @return 0 if not ordered; 1 if ordered
 */
int	is_sorted(t_stack *head)
{
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_min(t_stack *head)
{
	int	min;

	min = INT_MAX;
	while (head)
	{
		if (head->content < min)
			min = head->content;
		head = head->next;
	}
	return (min);
}

int	get_max(t_stack *head)
{
	int	max;

	max = INT_MIN;
	while (head)
	{
		if (head->content > max)
			max = head->content;
		head = head->next;
	}
	return (max);
}
