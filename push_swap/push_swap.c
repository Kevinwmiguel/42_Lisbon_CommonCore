/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:00:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/24 18:56:22 by kwillian         ###   ########.fr       */
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

void	push_all_to_b(t_node **a, t_node **b)
{
	while (*a != NULL)
		pb(a, b);
	sort_stack_b(b);
	while (*b != NULL)
		pa(a, b);
}

void	bubble_sort_stack(t_node **a)
{
	t_node	*current;
	int		swapped;
	int		temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *a;
		while (current->next != NULL)
		{
			if (current->number > current->next->number)
			{
				temp = current->number;
				current->number = current->next->number;
				current->next->number = temp;
				swapped = 1;
			}
			current = current->next;
		}
	}
}

void	push_3_on_a(t_node **a, t_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 3)
		simple_sort_three(a);
	else if (len == 5)
		simple_sort_five(a, b);
	else
	{
		while (stack_len(*a) > 3)
			pb(a, b);
		simple_sort_three(a);
		while (*b != NULL)
			move_cheapest(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_node		*a;
	t_node		*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!check_errors(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	process_args(argc, argv, &a, &b);
	printa(a);
	free_list(a);
	free_list(b);
	return (0);
}
