/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:16:46 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/12 19:45:13 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_three(t_node **a)
{
    if ((*a)->number > (*a)->next->number)
        sa(*a, 'a');
    if ((*a)->next->number > (*a)->next->next->number)
    {
        rra(a, 'a');
        if ((*a)->number > (*a)->next->number)
            sa(*a, 'a');
    }
    if ((*a)->number > (*a)->next->number)
        sa(*a, 'a');
}


void	set_target(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	long	best_match_index;

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

void	set_targetb(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target;
	long	best_match_index;

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

void prep_push_combined(t_node **a, t_node **b, t_node *cheap, char stack_id, bool is_double_rotation)
{
    while ((*a != cheap && stack_id == 'a') || (*b != cheap && stack_id == 'b'))
    {
        create_index(*a);
        create_index(*b);
        if (is_double_rotation)
        {
            if (cheap->upmedium == false && cheap->target->upmedium == false)
                rrr(a, b, 'c');
            else if (cheap->upmedium == true && cheap->target->upmedium == true)
                rr(a, b, 'c');
            else
                break;
        }
        else
        {
            if (stack_id == 'a')
            {
                if (cheap->upmedium == false)
                    rra(a, 'a');
                else
                    ra(a, 'a');
            }
            else if (stack_id == 'b')
            {
                if (cheap->upmedium == false)
                    rrb(b, 'b');
                else
                    rb(b, 'b');
            }
        }
    }
}

void	simple_sort(t_node **a, t_node **b)
{
	t_node *cheap;

    while (!is_sorted(*a))
    {
        pb(a, b);
        pb(a, b);
        while (stack_len(*a) > 3)
        {
            create_index(*b);
            create_index(*a);
            //simple_sort_three(a);
            cost_checker(*a, *b);
            cheap = get_cheapest((*a));
            set_target(*a, *b);
            prep_push_combined(a, b, cheap, 'a', true); // substitui prep_pushr
            prep_push_combined(a, b, cheap, 'a', false); // substitui prep_push
            prep_push_combined(a, b, cheap->target, 'b', false); // substitui prep_push
            pb(a, b);
        }
        simple_sort_three(a);
        while((*b))
        {
            //simple_sort_three(a);
            create_index(*b);
            create_index(*a);
            set_targetb(*a, *b);
            cost_checker(*a, *b);
            cheap = get_cheapest((*b));
            prep_push_combined(a, b, cheap, 'b', true); // substitui prep_pushrb
            prep_push_combined(a, b, cheap, 'b', false); // substitui prep_push
            prep_push_combined(a, b, cheap->target, 'a', false); // substitui prep_push
            //printb(*b);
            pa(a, b);
        }
        min_on_top(a);
    }
    create_index(*a);
    //printa(*a);
}
