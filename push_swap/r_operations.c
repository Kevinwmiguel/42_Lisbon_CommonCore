/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:11:11 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/24 16:49:09 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*temp;
	t_node	*current;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	current = *a;
	temp = *a;
	while (current->next != NULL)
		current = current->next;
	*a = (*a)->next;
	(*a)->prev = NULL;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	t_node	*current;
	t_node	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	current = *b;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
