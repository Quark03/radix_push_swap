/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:36:15 by acinca-f          #+#    #+#             */
/*   Updated: 2022/06/01 20:47:53 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Gives the value at a given index
 * @param head
 * @param index Position in the linked list (starts at 0)
 * @return The value at said position
 */
int	lst_value_by_index(t_stack *head, int index)
{
	int	i;
	int	lst_len;

	i = 0;
	while (head && i++ < index)
		head = head->next;
	return (head->content);
}

/**
 * Get the index where the value is located
 * @param head
 * @param value The value to search for (-1 if not found)
 * @return The position in the linked list (starts at 0)
 */
int	lst_index_by_value(t_stack *head, int value)
{
	int	count;

	count = 0;
	while (head)
	{
		if (head->content == value)
			return (count);
		count++;
		head = head->next;
	}
	return (-1);
}

void	lst_delete_back(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		return ;
	if (head->next == NULL)
	{
		free(head);
		return ;
	}
	temp = head;
	while ((temp->next)->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}

void	lst_delete_front(t_stack **list)
{
	t_stack	*head;

	if (!*list)
		return ;
	head = *list;
	*list = (*list)->next;
	free(head);
}

void	lst_remove_node(t_stack **list, int pos)
{
	int	i;
	int	lst_len;

	lst_len = lst_length(*list);
	if (pos == lst_len - 1)
		lst_delete_back(*list);
	else if (pos == 0)
		lst_delete_front(list);
	else
		lst_delete_middle(*list, pos);
}
