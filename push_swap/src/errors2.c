/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:10:38 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/21 12:11:51 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	signals2(char **c, int i, int j)
{
	if (c[i][j] == '+' || c[i][j] == '-')
	{
		if (j != 0)
			return (false);
		if (c[i][j + 1])
		{
			if (c[i][j + 1] == '-' || c[i][j + 1] == '+')
				return (false);
		}
		if (c[i][j - 1])
		{
			if (c[i][j - 1] == '-' || c[i][j - 1] == '+')
				return (false);
		}
	}
	return (true);
}

bool	signals(char **argv, int i, int j)
{
	long	n;

	while (argv[i][++j])
	{
		if (!signals2(argv, i, j))
			return (false);
		if (ft_isdigit(argv[i][j]) == 0 \
			&& argv[i][j] != '+' && argv[i][j] != '-')
			return (false);
	}
	n = ft_atol(argv[i]);
	if (n > 2147483647 || n < -2147483648 || is_duplicate(argv + 1, n, i - 1))
		return (false);
	return (true);
}

bool	check_errors(int argc, char *argv[])
{
	char	**tokens;
	int		i;
	int		j;

	i = 1;
	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (tokens == NULL)
			return (false);
		return (check_tokens(tokens));
	}
	else
	{
		while (i < argc)
		{
			j = -1;
			if (!signals(argv, i, j))
				return (false);
			i++;
		}
	}
	return (true);
}