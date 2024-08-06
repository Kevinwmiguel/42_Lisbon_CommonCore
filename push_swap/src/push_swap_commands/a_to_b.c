/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:17:44 by mmata-al          #+#    #+#             */
/*   Updated: 2024/08/04 21:04:29 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->upmedian = true;
		else
			stack->upmedian = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number 
				&& current_b->number > best_match_index)
			{
				best_match_index = current_b->number;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	cost_analysis_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost_to_push = a->index;
		if (!(a->upmedian))
			a->cost_to_push = len_a - (a->index);
		if (a->target->upmedian)
			a->cost_to_push += a->target->index;
		else
			a->cost_to_push += len_b - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long			cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost_to_push < cheapest_value)
		{
			cheapest_value = stack->cost_to_push;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	run_nodes_a(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
