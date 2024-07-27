/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:11:11 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/25 19:16:39 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *original)
{
	int	temp;

	if (original == NULL || original->next == NULL)
		return ;
	temp = original->number;
	original->number = original->next->number;
	original->next->number = temp;
	ft_printf("sa\n");
}

void	sb(t_node *original)
{
	int	temp;

	if (original == NULL || original->next == NULL)
		return ;
	temp = original->number;
	original->number = original->next->number;
	original->next->number = temp;
	ft_printf("sb\n");
}

void	ss(t_node *a, t_node *b)
{
	int	temp;

	if (a == NULL || a->next == NULL)
		return ;
	if (b == NULL || b->next == NULL)
		return ;
	temp = a->number;
	a->number = a->next->number;
	a->next->number = temp;
	temp = b->number;
	b->number = b->next->number;
	b->next->number = temp;
	ft_printf("ss\n");
}
