/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:48:01 by mmata-al          #+#    #+#             */
/*   Updated: 2024/08/04 21:03:26 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-'))
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	if ((*str_n == '+' || *str_n == '-'))
	{
		if (!(str_n[1] >= '0' && str_n[1] <= '9'))
			return (1);
	}
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	duplicated(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->number == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->number = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_node **a)
{
	free_stack(a);
	ft_printf("An Error has occurred.\n");
	exit(1);
}
