/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:35:04 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/01 18:35:28 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_to_a(int value)
{
	int	max;

	max = get_max((*get_stack(A)));
	if (value > max)
		exec_command(9);
	else
		complex_sort(value);
}
