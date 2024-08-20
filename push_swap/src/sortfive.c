/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:16:46 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/20 23:10:02 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple_sort_three(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, 'a');
	else if ((*a)->next == biggest_node)
		rra(a, 'a');
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

void	push_prep(t_node **stack, t_node *top, char stack_name)
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
static void	rotate_both(t_node **a,
						t_node **b,
						t_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rr(a, b, 'c');
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_node **a,
								t_node **b,
								t_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rrr(a, b, 'c');
	current_index(*a);
	current_index(*b);
}

void	simple_sort(t_node **a, t_node **b)
{
	t_node  *cheap;

    if (stack_len(*a) == 4)
         pb(a, b);
    else
    {
        pb(a, b);
        pb(a, b);
    }
    while (stack_len(*a) > 3)
    {
        create_index(*b);
        create_index(*a);
        set_target(*a, *b);
        cost_checker(*a, *b);
        cheap = get_cheapest((*a));
        //printa(*a);
        if (cheap->upmedium 
            && cheap->target->upmedium)
            rotate_both(a, b, cheap);
        else if (!(cheap->upmedium) 
            && !(cheap->target->upmedium))
		    rev_rotate_both(a, b, cheap);
        push_prep(a, cheap, 'a');
	    push_prep(b, cheap->target, 'b');
        pb(a, b);
    }
    simple_sort_three(a);
    while((*b))
    {
        create_index(*b);
        create_index(*a);
        set_targetb(*a, *b);
        push_prep(a, (*b)->target, 'a');
        pa(a, b);
    }
    min_on_top(a);
    //printaa(a);
}
