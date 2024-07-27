/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aditional2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:34:18 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/26 18:55:52 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_sorted(t_node *lst) {
    while (lst != NULL && lst->next != NULL) {
        if (lst->number > lst->next->number)
            return false;
        lst = lst->next;
    }
    return true;
}

bool is_sorted_b(t_node *lst)
{
    while (lst != NULL && lst->next != NULL)
    {
        if (lst->number > lst->next->number)
            return false;
        lst = lst->next;
    }
    return true;
}

void	sort_stack_b(t_node **b)
{
	while (!is_sorted_b(*b))
	{
		if ((*b)->number > (*b)->next->number)
		{
			sb(*b); // Trocar os dois primeiros elementos se necessári
		}
	}
}


int	is_sorted_desc(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}
