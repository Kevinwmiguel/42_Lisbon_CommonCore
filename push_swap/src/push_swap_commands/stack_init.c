/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:20 by mmata-al          #+#    #+#             */
/*   Updated: 2024/08/07 19:33:46 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->number = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	node->cheapest = false;
}

static long	ft_atol(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

void	init_stack_a(t_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			return (free_nodes(argv), free_errors(a));
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free_nodes(argv), free_errors(a));
		if (duplicated(*a, (int)n))
			return (free_nodes(argv), free_errors(a));
		append_node(a, (int)n);
		i++;
	}
	free_nodes(argv);
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_prep(t_node **stack, t_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->upmedian)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top->upmedian)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
