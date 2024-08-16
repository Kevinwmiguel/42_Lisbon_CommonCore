/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tudoextra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:11:39 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/16 03:46:24 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_cheapest(t_node *stack)
{
	t_node	*cheap;
	long		min_cost;

	if (!stack)
		return (NULL);
	min_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost_to_push < min_cost)
		{
			min_cost = stack->cost_to_push;
			cheap = stack;
		}
		stack = stack->next;
	}
	cheap->cheapest = true;
	return (cheap);
}

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
			stack->upmedium = true;
		else
			stack->upmedium = false;
		stack = stack->next;
		++i;
	}
}

t_node	*find_min_to_a(t_node *stack)
{
	t_node	*min_node;
	long	min;

	min = LONG_MAX;
	min_node = NULL;
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

void	min_on_top(t_node **stack)
{
	t_node	*min_node;
	int		len;
	int		min_index;

	if (stack == NULL || *stack == NULL)
		return ;
	min_node = find_min_to_a(*stack);
	if (min_node == NULL)
		return ;
	len = stack_len(*stack);
	min_index = min_node->index;
	while ((*stack)->number != min_node->number)
	{
		if (min_index <= len / 2)
			ra(stack, 'a');
		else
			rra(stack, 'a');
	}
}
