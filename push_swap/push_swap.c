/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:00:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/30 02:29:56 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // Inclui a definição de t_node
#include <stdio.h>
#include "libft/libft.h" 
#include "printf/ft_printf.h"


void	move_cheapest(t_node **a, t_node **b)
{
	t_node	*current;

	cost_checker(*a, *b);
	cheaper_one(*a);
	cheaper_one(*b);
	current = *a;
	while (current != NULL)
	{
		if (current->cheapest)
		{
			pa(a, b);
			return ;
		}
		current = current->next;
	}
	current = *b;
	while (current != NULL)
	{
		if (current->cheapest)
		{
			pb(a, b);
			return ;
		}
		current = current->next;
	}
}

void	create_index(t_node *stack)
{
	t_node *current = stack;

	int	i;

	i = 0;
	while ((stack))
	{
		(stack)->index = i;
		if (i <= (stack_len(stack) / 2))
			(stack)->upmedium = true;
		else
			(stack)->upmedium = false;
		i++;
		(stack) = (stack)->next;
	}
	stack = current;
}

void	push_3_on_a(t_node **a, t_node **b)
{
	int	len;
	
	create_index(*a);
	len = stack_len(*a);
	if (len == 3)
		simple_sort_three(a);
	else
	{
		simple_sort(a, b);
	}
}
