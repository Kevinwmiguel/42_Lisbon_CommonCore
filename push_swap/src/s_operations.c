/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:11:11 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/14 19:46:50 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node *original, char c)
{
	int	temp;

	if (original == NULL || original->next == NULL)
		return ;
	temp = original->number;
	original->number = original->next->number;
	original->next->number = temp;
	if (c == 'a')
		ft_printf("sa\n");
}

void	sb(t_node *original, char c)
{
	int	temp;

	if (original == NULL || original->next == NULL)
		return ;
	temp = original->number;
	original->number = original->next->number;
	original->next->number = temp;
	if (c == 'b')
		ft_printf("sb\n");
}

void	ss(t_node *a, t_node *b, char c)
{
	sa(a, 'c');
	sb(b, 'c');
	if (c == 'c')
		ft_printf("ss\n");
}
