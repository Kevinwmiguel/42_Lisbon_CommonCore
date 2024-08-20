/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:09:48 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/21 00:10:22 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	static int i = 1;

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
	i++;
	// if (i == 19)
	// 	printf(" numero do pb 18 %d target %d index do target %d e index do padrao %d\n", (*a)->number, (*a)->target->number, (*a)->target->index, (*a)->index);
}
