/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:11:11 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/14 19:46:50 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **a, char c)
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
	if (c == 'a')
		ft_printf("ra\n");
}

void	rb(t_node **b, char c)
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
	if (c == 'b')
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, char c)
{
	ra(a, 'c');
	rb(b, 'c');
	if (c == 'c')
		ft_printf("rr\n");
}
