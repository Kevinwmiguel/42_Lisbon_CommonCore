/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:16:46 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/31 05:03:54 by kwillian         ###   ########.fr       */
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

void set_target(t_node *a, t_node *b)
{
	t_node *original_b = b;
	t_node *original_a = a;
    while (original_a != NULL)
    {
        original_a->target = find_min(a, original_b);
		original_a = original_a->next;
    }
	a = original_a;
}

void set_targetb(t_node *a, t_node *b)
{
    while (b != NULL)
    {
        b->target = find_max(a, b);
		b = b->next;
    }
}
//WOrking better dont know how
// void set_targetb(t_node *a, t_node *b)
// {
//     while (b != NULL)
//     {
//         b->target = find_max(a, b);
// 		b = b->next;
//     }
// }

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
            else
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

    pb(a, b);
    pb(a, b);
    while (stack_len(*a) > 3)
    {
        create_index(*b);
        create_index(*a);
        simple_sort_three(a);
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
        simple_sort_three(a);
        create_index(*b);
        create_index(*a);
        set_targetb(*a, *b);
        cost_checker(*a, *b);
        cheap = get_cheapest((*b));
		create_index(*b);
        create_index(*a);
        prep_push_combined(a, b, cheap, 'b', true); // substitui prep_pushrb
		prep_push_combined(a, b, cheap->target, 'a', false); // substitui prep_push
        prep_push_combined(a, b, cheap, 'b', false); // substitui prep_push
        pa(a, b);
    }
    min_on_top(a);

}
