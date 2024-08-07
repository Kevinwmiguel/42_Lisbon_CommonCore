/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:36:34 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/07 19:37:06 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->upmedian
		&& cheapest_node->target->upmedian)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->upmedian)
		&& !(cheapest_node->target->upmedian))
		rev_rotate_both(a, b, cheapest_node);
	push_prep(a, cheapest_node, 'a');
	push_prep(b, cheapest_node->target, 'b');
	pb(b, a, false);
}

static void	min_on_top(t_node **a)
{
	while ((*a)->number != find_min(*a)->number)
	{
		if (find_min(*a)->upmedian)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_all_numbers(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		run_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	simple_sort(a);
	while (*b)
	{
		run_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
