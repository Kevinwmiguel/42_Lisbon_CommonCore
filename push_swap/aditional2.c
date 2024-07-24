/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aditional2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:34:18 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/23 21:35:00 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_node *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		if (lst->number > lst->next->number)
			return (0);
		lst = lst->next;
	}
	return (1);
}

bool	is_sorted_b(t_node *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		if (lst->number < lst->next->number)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	simple_sort(t_node **a, t_node **b)
{
	while (!is_sorted(*a))
	{
		if ((*a)->number > (*a)->next->number)
			sa(*a);
		else
			pb(a, b);
	}
	while (*b != NULL)
	{
		pa(a, b);
	}
}

void	sort_stack_b(t_node **b)
{
	int		swapped;
	int		temp;
	t_node	*current;

	swapped = 1;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	while (swapped)
	{
		swapped = 0;
		current = *b;
		while (current->next != NULL)
		{
			if (current->number < current->next->number)
			{
				temp = current->number;
				current->number = current->next->number;
				current->next->number = temp;
				swapped = 1;
			}
			current = current->next;
		}
	}
}

int	is_sorted_desc(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number < stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}
