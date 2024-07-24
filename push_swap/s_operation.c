/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:11:11 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/24 18:04:31 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *original)
{
	int	temp;

	if (original == NULL || original->next == NULL)
		return ;
	temp = original->number;
	original->number = original->next->number;
	original->next->number = temp;
	ft_printf("sa\n");
}

void	sb(t_node *original)
{
	int	temp;

	if (original == NULL || original->next == NULL)
		return ;
	temp = original->number;
	original->number = original->next->number;
	original->next->number = temp;
	ft_printf("sb\n");
}

void	ss(t_node *a, t_node *b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	simple_sort_five(t_node **a, t_node **b)
{
	pb(a, b);
	pb(a, b);
	simple_sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	simple_sort_three(t_node **a)
{
	if ((*a)->number > (*a)->next->number)
		sa(*a);
	if ((*a)->next->number > (*a)->next->next->number)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(*a);
}
