/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tudoextra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:11:39 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/24 14:19:07 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_node	*find_best_target(t_node *a_node, t_node *b)
{
	t_node	*best_target;
	t_node	*current_b;

	best_target = NULL;
	current_b = b;
	while (current_b)
	{
		if (current_b->number < a_node->number)
			if (!best_target || current_b->number > best_target->number)
				best_target = current_b;
		current_b = current_b->next;
	}
	if (!best_target)
	{
		current_b = b;
		best_target = current_b;
		while (current_b)
		{
			if (current_b->number < best_target->number)
				best_target = current_b;
			current_b = current_b->next;
		}
	}
	return (best_target);
}

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_a;

	current_a = a;
	while (current_a)
	{
		current_a->target = find_best_target(current_a, b);
		current_a = current_a->next;
	}
}

void	calculate_cost(t_node *node, int len, int len_other)
{
	node->cost_to_push = node->index;
	if (!node->upmedium)
		node->cost_to_push = len - node->index;
	if (node->target->upmedium)
		node->cost_to_push += node->target->index;
	else
		node->cost_to_push += len_other - node->target->index;
}

void	cost_checker(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_b = stack_len(b);
	len_a = stack_len(a);
	while (a)
	{
		calculate_cost(a, len_a, len_b);
		a = a->next;
	}
	while (b)
	{
		calculate_cost(b, len_b, len_a);
		b = b->next;
	}
}
