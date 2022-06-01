/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:13:40 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/01 18:25:27 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	flip_number(int nbr)
{
	int	size;

	size = sizeof(int) * 8 - 1;
	return (nbr ^ (1 << size));
}

/**
 * Flips the last bit of all numbers on the stack A
 */
void	flip_numbers(void)
{
	t_stack	*head;

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

typedef struct s_large_vars
{
	int	length;
	int	max;
	int	max_bits;
	int	i;
	int	j;
	int	num;
}	t_large_vars;

void	sort_large2(t_large_vars *vars)
{
	while (vars->j < vars->length)
	{
		vars->num = (*get_stack(A))->content;
		if (((vars->num >> vars->i) & 1) == 1)
			exec_command(3);
		else
			exec_command(10);
		++vars->j;
	}
}

void	sort_large(int negative)
{
	t_large_vars	vars;

	vars.length = lst_length((*get_stack(A)));
	vars.max = get_max((*get_stack(A)));
	vars.max_bits = 0;
	while ((vars.max >> vars.max_bits) != 0)
		++vars.max_bits;
	vars.i = 0;
	while (vars.i < vars.max_bits)
	{
		vars.j = 0;
		sort_large2(&vars);
		while (lst_length((*get_stack(B))) > 0)
			exec_command(9);
		if (negative && is_sorted((*get_stack(A))))
			break ;
		++vars.i;
	}
}
