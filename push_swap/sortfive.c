/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:16:46 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/27 02:52:53 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_last_greater_than_first(t_node *stack)
{
    t_node *first = stack;
    t_node *last = stack;

    if (!stack)
    	return (0);
    while (last->next != NULL)
        last = last->next;
    return (last->number > first->number);
}

int	is_fisrt_greater_middle(t_node *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack;
	last = stack;
	if (!stack)
		return (0);
	while (last->next != NULL)
		last = last->next;
	return (last->prev->prev->number < first->number);
}

void	simple_sort_three(t_node **a)
{
    if ((*a)->number > (*a)->next->number)
        sa(*a);
    if ((*a)->next->number > (*a)->next->next->number)
    {
        rra(a);
        if ((*a)->number > (*a)->next->number)
            sa(*a);
    }
    if ((*a)->number > (*a)->next->number)
        sa(*a);
}

void set_target(t_node *a, t_node *b)
{
    while (a != NULL)
    {
        a->target = find_min(a, b);
		a = a->next;
    }
}

void set_targetb(t_node *a, t_node *b)
{
    while (b != NULL)
    {
        b->target = find_max(a, b);

		b = b->next;
    }
}

void prep_push(t_node **stack, t_node *cheap, char c)
{
	while(*stack != cheap)
	{
		if (c == 'a')
		{
			if (cheap->upmedium == false)
				rra(stack);
			else
				ra(stack, 'a');
		}
		else
		{
			if (cheap->upmedium == false)
				rrb(stack);
			else
				rb(stack, 'b');
		}
	}
}

void prep_pushr(t_node **a, t_node **b, t_node *cheap)
{
	while ((cheap->upmedium == false && cheap->target->upmedium == false) && (cheap != *a || cheap->target != *b))
			rrr(a, b);
	while ((cheap->upmedium == true && cheap->target->upmedium == true) && (cheap != *a || cheap->target != *b))
		rr(a, b, 'c');
}

void prep_pushrb(t_node **a, t_node **b, t_node *cheap)
{
	while ((cheap->upmedium == false && cheap->target->upmedium == false) && (cheap != *b || cheap->target != *a))
			rrr(a, b);
	while ((cheap->upmedium == true && cheap->target->upmedium == true) && (cheap != *b || cheap->target != *a))
			rr(a, b, 'c');
}

void simple_sort(t_node **a, t_node **b)
{
    pb(a, b);
    pb(a, b);
	t_node *cheap;
	
    while (stack_len(*a) > 3)
    {
		//menormais prox OU maior de todos
		set_target(*a, *b);
        cost_checker(*a, *b);
		cheap = get_cheapest((*a));
		prep_pushr(a, b, cheap);
		prep_push(a, cheap, 'a');
		prep_push(b, cheap->target, 'b');
		pb(a ,b);
		create_index(*b);
		create_index(*a);
    }
	simple_sort_three(a);
	// printf("=================================\n");
	// printa(*a);
	// printb(*b);
	// printf("=================================\n");
	while((*b))
	{
		set_targetb(*a, *b);
		cost_checker(*a, *b);
		cheap = get_cheapest((*b));
		prep_pushrb(a, b, cheap);
		prep_push(b, cheap, 'b');
		prep_push(a, cheap->target, 'a');
		pa(a, b);
	}
	
}



