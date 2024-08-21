/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tudoextra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:11:39 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/21 12:15:03 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calculate_cost(t_node *node, int len_a, int len_b)
{
	node->cost_to_push = node->index;
	if (!node->upmedium)
		node->cost_to_push = len_a - node->index;
	if (node->target != NULL)
	{
		if (node->target->upmedium)
			node->cost_to_push += node->target->index;
		else
			node->cost_to_push += len_b - node->target->index;
	}
}

void	cost_checker(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a != NULL)
	{
		calculate_cost(a, len_a, len_b);
		a = a->next;
	}
	while (b != NULL)
	{
		calculate_cost(b, len_b, len_a);
		b = b->next;
	}
}

t_node	*find_min(t_node *stack)
{
	t_node	*min_node;
	long	min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max_node;
	long	max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
