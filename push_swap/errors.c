/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:35:37 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/27 02:40:45 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	n;
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (!is_number(tokens[i]))
		{
			free_split_args(tokens);
			return (false);
		}
		n = ft_atoi(tokens[i]);
		if (n > INT_MAX || n < INT_MIN || is_duplicate(tokens, n, i))
		{
			free_split_args(tokens);
			return (false);
		}
		i++;
	}
	free_split_args(tokens);
	return (true);
}

bool	check_errors(int argc, char *argv[])
{
	char	**tokens;
	int		n;
	int		i;

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
			if (!is_number(argv[i]))
				return (false);
			n = ft_atoi(argv[i]);
			if (n > INT_MAX || n < INT_MIN || is_duplicate(argv + 1, n, i - 1))
				return (false);
			i++;
		}
	}
	return (true);
}
