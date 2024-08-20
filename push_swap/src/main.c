/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:32:14 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/20 23:32:26 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

void	printaa(t_node **a)
{
	while ((*a)->next != NULL)
	{
		ft_printf("numero atual %d\n", (*a)->number);
		(*a) = (*a)->next;
	}
}

int	main(int argc, char *argv[])
{
	t_node		*a;
	t_node		*b;

	a = NULL;
	b = NULL;
	if (!check_errors(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	process_args(argc, argv, &a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
