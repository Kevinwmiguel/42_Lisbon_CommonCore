/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:00:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/27 01:19:16 by kwillian         ###   ########.fr       */
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

void	create_index(t_node *a)
{
	t_node *current = a;

	int	i;
	
	printf("VALOR TOTAL DA STACK %d\n", stack_len(a));
	i = 0;
	while ((a))
	{
		(a)->index = i;
		if (i <= (stack_len(a) / 2))
			(a)->upmedium = true;
		else
			(a)->upmedium = false;
		i++;
		(a) = (a)->next;
	}
	a = current;
}

void	push_3_on_a(t_node **a, t_node **b)
{
	int	len;
	
	create_index(*a);
	printa(*a);
	len = stack_len(*a);
	if (len == 3)
		simple_sort_three(a);
	else
	{
		simple_sort(a, b);
	}
}
