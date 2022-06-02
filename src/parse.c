/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:06:15 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/02 17:03:36 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	copy_to_array(int *array, t_stack *head)
{
	int	i;
	int	temp;

	i = 0;
	while (head)
	{
		temp = head->content;
		head = head->next;
		array[i] = temp;
		i++;
	}
}

void	bubble_sort(int *array, int size)
{
	int	step;
	int	i;
	int	temp;

	step = 0;
	while (step < size - 1)
	{
		i = 0;
		while (i < size - step - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			++i;
		}
		++step;
	}
}

void	swap_values(int *array, t_stack *head, int size)
{
	int	j;

	while (head)
	{
		j = 0;
		while (j < size)
		{
			if (head->content == array[j])
			{
				head->content = j;
				break ;
			}
			j++;
		}
		head = head->next;
	}
}

void	parse_negatives(void)
{
	int		*array;
	int		len;

	len = lst_length((*get_stack(A)));
	array = malloc(sizeof(int) * len);
	if (!array)
		return ;
	copy_to_array(array, (*get_stack(A)));
	bubble_sort(array, len);
	swap_values(array, (*get_stack(A)), len);
}
