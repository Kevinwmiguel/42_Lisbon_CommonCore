/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:06:50 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/21 13:41:51 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_push(t_node **stack, t_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->upmedium)
				ra(stack, 'a');
			else
				rra(stack, 'a');
		}
		else if (stack_name == 'b')
		{
			if (top->upmedium)
				rb(stack, 'b');
			else
				rrb(stack, 'b');
		}
	}
}

void	rr_prepare(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rr(a, b, 'c');
	indexes(a, b);
}

void	rrr_prepare(t_node **a, t_node **b, t_node *cheap)
{
	while (*b != cheap->target
		&& *a != cheap)
		rrr(a, b, 'c');
	indexes(a, b);
}

void	prep_push_combined(t_node **a, t_node **b, t_node *cheap)
{
	if (cheap->upmedium && cheap->target->upmedium)
		rr_prepare(a, b, cheap);
	else if (!(cheap->upmedium) && !(cheap->target->upmedium))
		rrr_prepare(a, b, cheap);
}
