/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:09:48 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/29 06:12:17 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*hold;

	if (*b == NULL)
		return ;
	hold = *b;
	*b = (*b)->next;
	if (*b != NULL)
		(*b)->prev = NULL;
	hold->next = NULL;
	hold->prev = NULL;
	ft_lstadd_front2(a, hold);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	t_node	*hold;

	if (*a == NULL)
		return ;
	hold = *a;
	*a = (*a)->next;
	if (*a != NULL)
		(*a)->prev = NULL;
	hold->next = NULL;
	hold->prev = NULL;
	ft_lstadd_front2(b, hold);
	ft_printf("pb\n");
}
