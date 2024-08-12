/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aditional.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:33:55 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/24 15:32:17 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew2(int number, int idx)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->index = idx;
	new_node->cost_to_push = 0;
	new_node->upmedium = false;
	new_node->cheapest = false;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lstadd_front2(t_node **lst, t_node *new_node)
{
	if (lst && new_node)
	{
		new_node->next = *lst;
		if (*lst)
			(*lst)->prev = new_node;
		*lst = new_node;
	}
}

void	cheaper_one(t_node *lst)
{
	long	cheapest;
	t_node	*cheapest_node;

	cheapest = LONG_MAX;
	cheapest_node = NULL;
	while (lst)
	{
		if (lst->cost_to_push < cheapest)
		{
			cheapest = lst->cost_to_push;
			cheapest_node = lst;
		}
		lst = lst->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	free_list(t_node *head)
{
	t_node		*current;
	t_node		*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
