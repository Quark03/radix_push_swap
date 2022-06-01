/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:30:01 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/01 20:48:28 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	**get_stack(t_type stack)
{
	static t_stack	*stack_a;
	static t_stack	*stack_b;

	if (stack == A)
		return (&stack_a);
	else if (stack == B)
		return (&stack_b);
	return (&stack_a);
}

int	invalid_number(int ac, char **av)
{
	int		i;
	long	n;

	i = 0;
	while (ac > 0)
	{
		n = long_atoi(av[i++]);
		if (n > INT_MAX)
			return (1);
		if (n < INT_MIN)
			return (1);
		ac--;
	}
	return (0);
}

void	stack_sort(void)
{
	if (is_sorted((*get_stack(A))))
		return ;
	if (lst_length((*get_stack(A))) > 5)
	{
		if (has_negative((*get_stack(A))) == 0)
			sort_large(0);
		else
		{
			flip_numbers();
			sort_large(1);
			flip_numbers();
			reorder_a();
		}
	}
	else
		sort_small();
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*temp;

	(*get_stack(B)) = NULL;
	i = 1;
	if (invalid_number(ac, av))
	{
		ft_putstr_fd("ERROR\n", 1);
		return (0);
	}
	while (i < ac)
	{
		if (i == 1)
		{
			temp = lst_new(ft_atoi(av[i]));
			(*get_stack(A)) = temp;
		}
		else
			lst_add_back((*get_stack(A)), ft_atoi(av[i]));
		i++;
	}
	if (has_repeated_numbers((*get_stack(A))))
		ft_putstr_fd("ERROR\n", 1);
	else
		stack_sort();
}
