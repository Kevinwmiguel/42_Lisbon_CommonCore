/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tudoextra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:11:39 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/27 16:45:18 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_node* get_cheapest(t_node *stack)
{
    t_node *cheap = NULL;
    int min_cost = INT_MAX;

    while (stack != NULL)
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

void    find_last(t_node **last)
{
    while ((*last)->next != NULL)
         *last = (*last)->next;
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

t_node *find_best_target(t_node *a, t_node *b)
{
    t_node *best_target = NULL;
    t_node *current_b = b;

    while (current_b != NULL)
    {
        if (current_b->number < a->number)
        {
            if (best_target == NULL || current_b->number > best_target->number)
            {
                best_target = current_b;
            }
        }
        current_b = current_b->next;
    }
    if (best_target == NULL)
    {
        current_b = b;
        best_target = current_b;
        while (current_b != NULL) {
            if (current_b->number < best_target->number) {
                best_target = current_b;
            }
            current_b = current_b->next;
        }
    }
    return best_target;
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

void cost_checker(t_node *a, t_node *b)
{
    int len_a;
    int len_b;

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

t_node	*find_min(t_node *a, t_node *b)
{
	int			min;
    int         check;
	t_node	*min_node;
    t_node  *fail;
    
	if (!a || !b)
		return (NULL);
	min = INT_MIN;
    check = INT_MIN;
	while (b)
	{
		if (b->number < a->number && b->number > min)
		{
			min = b->number;
			min_node = b;
		}
        if (b->number > check)
            {
                check = b->number;
                fail = b;
            }
		b = b->next;
	}
    if (min == INT_MIN)
    {
        min_node = fail;
    }
    return (min_node);
}


t_node	*find_max(t_node *a, t_node *b)
{
	int			max;
    int         check;
	t_node	*max_node;
    t_node	*fail;
    
	if (!a || !b)
		return (NULL);
	max = INT_MAX;
    check = INT_MAX;
	while (a)
	{
		if (a->number > b->number && a->number < max)
		{
			max = a->number;
			max_node = a;
		}
        if (a->number < check)
            {
                check = a->number;
                fail = a;
            }
		a = a->next;
	}
    if (max == INT_MAX)
    {
        max_node = fail;
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

t_node *find_min_to_a(t_node *stack)
{
    long min = LONG_MAX;
    t_node *min_node = NULL;

    while (stack)
    {
        if (stack->number < min)
        {
            min = stack->number;
            min_node = stack;
        }
        stack = stack->next;
    }
    return min_node;
}

void min_on_top(t_node **stack)
{
    t_node *min_node = find_min_to_a(*stack); // Encontrar o menor elemento na stack passada como parâmetro
    int len = stack_len(*stack);
    int min_index = min_node->index;

    // Determinar se o menor elemento está na metade superior ou inferior da pilha
    while ((*stack)->number != min_node->number)
    {
        if (min_index <= len / 2)
        {
            ra(stack, 'a');
        }
        else
        {
            rra(stack);
        }
    }
}
