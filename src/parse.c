/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:06:15 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/02 16:19:15 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_array(int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
		printf("%d.", array[i++]);
	ft_putstr_fd("\n", 1);
}

void copy_to_array(int *array, t_stack *head)
{
	int i;
	int temp;

	i = 0;
	while (head)
	{
		temp = head->content;
		head = head->next;
		array[i] = temp;
		i++;
	}
}

void bouble_sort(int *array, int size)
{
	int step;
	int i;
	int temp;

	step = 0;
	while (step < size)
	{
		i = 0;
		while (i < size - step)
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

void swap_values(int *array, t_stack *head, int size)
{
	int j;

	while (head)
	{
		j = 0;
		while (j < size)
		{
			if (head->content == array[j])
				head->content = j;
			j++;
		}
		head = head->next;
	}
}

void	parse_negatives(void)
{
	int	*array;
	t_stack *head;
	int	len;
	int	i;

	len = lst_length((*get_stack(A)));
	array = malloc(sizeof(int) * len);
	head = (*get_stack(A));
	if (!array)
		return ;
	// copy_to_array(array, (*get_stack(A)));
    i = 0;
    while (head)
	{
		array[i] = head->content;
        printf("Content %d\n", head->content);
		head = head->next;
		i++;
	}
	ft_putstr_fd("Before sort ", 1);
	print_array(array, len);
	bouble_sort(array, len);
	ft_putstr_fd("Before swap ", 1);
	print_array(array, len);
	swap_values(array, (*get_stack(A)), len);
	ft_putstr_fd("After swap ", 1);
	print_stack(A);
}
