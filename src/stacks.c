/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:30:01 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/01 20:48:00 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Creates a new t_stack node
 * @param nbr
 * @return
 */
t_stack	*lst_new(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = nbr;
	new->next = NULL;
	return (new);
}

/**
 * Adds a new node to the end of the linked list
 * @param head
 * @param nbr
 */
void	lst_add_back(t_stack *head, int nbr)
{
	t_stack	*temp;

	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = lst_new(nbr);
}

/**
 * Initializes or adds a new node
 * @param list
 * @param nbr
 */
void	lst_initialize_add_back(t_stack **list, int nbr)
{
	if (*list)
		lst_add_back(*list, nbr);
	else if ((*(list)) == 0)
		*list = lst_new(nbr);
}

/**
 * Adds a new node to the front of the list
 * @param list
 * @param nbr
 */
void	lst_add_front(t_stack **list, int nbr)
{
	t_stack	*new;

	new = lst_new(nbr);
	new->next = *list;
	*list = new;
}

/**
 * Returns the length of the linked list
 * @param head
 * @return
 */
int	lst_length(t_stack *head)
{
	t_stack	*temp;
	int		sum;

	temp = head;
	sum = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		sum++;
	}
	return (sum);
}
