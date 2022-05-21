/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:30:01 by acinca-f          #+#    #+#             */
/*   Updated: 2022/03/16 18:11:05 by acinca-f         ###   ########.fr       */
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
void lst_add_back(t_stack *head, int nbr)
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
void lst_initialize_add_back(t_stack **list, int nbr)
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
void lst_add_front(t_stack **list, int nbr)
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
int lst_length(t_stack *head)
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

/**
 * Gives the value at a given index
 * @param head
 * @param index Position in the linked list (starts at 0)
 * @return The value at said position
 */
int lst_value_by_index(t_stack *head, int  index)
{
    int i;
    int lst_len;

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
int lst_index_by_value(t_stack *head, int value)
{
    int count;

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

void lst_delete_back(t_stack *head)
{
    t_stack *temp;

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

void lst_delete_front(t_stack **list)
{
    t_stack *head;

    if (!*list)
        return;
   head = *list;
   *list = (*list)->next;
   free(head);
}

void lst_delete_middle(t_stack *head, int pos)
{

}

void lst_remove_node(t_stack **list, int pos)
{
    int i;
    int lst_len;

    lst_len = lst_length(*list);
    if (pos == lst_len - 1)
        lst_delete_back(*list);
    else if (pos == 0)
        lst_delete_front(list);
    else
        lst_delete_middle(*list, pos);
}

void lst_delete(t_stack **list)
{

}



