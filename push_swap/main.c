/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:32:14 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/27 00:02:23 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	main(int argc, char *argv[])
{
	t_node		*a;
	t_node		*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!check_errors(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	process_args(argc, argv, &a, &b);
	
	free_list(a);
	free_list(b);
	return (0);
}
