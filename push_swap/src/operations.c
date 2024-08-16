/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:36:37 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/14 19:46:50 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_node **a, char c)
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
	if (c == 'a')
		ft_printf("rra\n");
}

void	rrb(t_node **b, char c)
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
	if (c == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, char c)
{
	rra(a,'c');
	rrb(b,'c');
	if (c == 'c')
		ft_printf("rra\n");
}
