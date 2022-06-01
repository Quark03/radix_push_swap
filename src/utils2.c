/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:38:14 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/01 18:44:15 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Get the stack ordered
 */

typedef struct s_reorder_vars
{
	int	min;
	int	pos;
	int	len;
	int	offset;
	int	half;
	int	moves;
}	t_reorder_vars;

void	reorder_a(void)
{
	t_reorder_vars	vars;

	vars.min = get_min((*get_stack(A)));
	vars.pos = lst_index_by_value((*get_stack(A)), vars.min);
	vars.len = lst_length((*get_stack(A)));
	vars.half = vars.len / 2;
	vars.offset = vars.len - vars.pos;
	if (vars.offset > vars.half)
	{
		vars.moves = vars.len - vars.offset;
		while (vars.moves-- > 0)
			exec_command(3);
	}
	else
	{
		while (vars.offset-- > 0)
			exec_command(6);
	}
}

/**
 * Count the amount of times a given number appears in a list
 * @param nbr
 * @param head
 * @return
 */
int	count_occurrences(int nbr, t_stack *head)
{
	int	counter;

	counter = 0;
	while (head)
	{
		if (head->content == nbr)
			counter++;
		head = head->next;
	}
	return (counter);
}

/**
 * Check if the stack has repeated numbers
 * @param head
 * @return 1 if it has, 0 if not
 */
int	has_repeated_numbers(t_stack *head)
{
	t_stack	*fixed;

	fixed = head;
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
	ft_putstr_fd("\n", 1);
}

int	has_negative(t_stack *head)
{
	while (head)
	{
		if (head->content < 0)
			return (1);
		head = head->next;
	}
	return (0);
}
