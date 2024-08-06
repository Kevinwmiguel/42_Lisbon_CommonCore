/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:17:49 by mmata-al          #+#    #+#             */
/*   Updated: 2024/08/04 21:04:29 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number 
				&& current_a->number < best_match_index)
			{
				best_match_index = current_a->number;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	run_nodes_b(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
