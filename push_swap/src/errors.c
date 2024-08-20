/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:35:37 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/20 20:44:02 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

bool	is_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

bool	is_duplicate(char **args, int number, int size)
{
	int	i;
	int	n;

	i = 0;
	while (i < size)
	{
		n = ft_atoi(args[i]);
		if (n == number)
			return (true);
		i++;
	}
	return (false);
}

bool	check_tokens(char **tokens)
{
	int		i;
	long	n;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (!is_number(tokens[i]))
		{
			free_split_args(tokens);
			return (false);
		}
		n = ft_atol(tokens[i]);
		if (n > 2147483647 || n < -2147483648 || is_duplicate(tokens, n, i))
		{
			free_split_args(tokens);
			return (false);
		}
		i++;
	}
	free_split_args(tokens);
	return (true);
}

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
		if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '+' && argv[i][j] != '-')
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
