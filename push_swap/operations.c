/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:36:37 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/24 16:02:06 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*current;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	current = *a;
	while (current->next != NULL)
		current = current->next;
	if (current->prev != NULL)
		current->prev->next = NULL;
	current->prev = NULL;
	current->next = *a;
	(*a)->prev = current;
	*a = current;
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	t_node	*current;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	current = *b;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *b;
	(*b)->prev = current;
	*b = current;
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
