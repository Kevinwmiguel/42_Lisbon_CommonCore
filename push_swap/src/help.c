/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:11:27 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/21 12:14:25 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_cheapest(t_node *stack)
{
	long	min_cost;
	t_node	*cheap;

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

void	min_on_top(t_node **stack)
{
	t_node	*min_node;
	int		len;
	int		min_index;

	if (stack == NULL || *stack == NULL)
		return ;
	min_node = find_min(*stack);
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
