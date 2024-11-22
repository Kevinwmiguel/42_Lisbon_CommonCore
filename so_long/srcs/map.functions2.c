/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:37:23 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/18 00:38:19 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_nl(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1])
		{
			if (str[i + 1] == '\n')
				return (1);
		}
		i++;
	}
	return (0);
}

void	lines_mistake(char *all_lines)
{
	ft_printf("Error\nproblemas aqui, linhas em branco\n");
	free(all_lines);
	exit(1);
}

void	ft_empty_map(char *all_lines)
{
	if (all_lines[0] == '\0')
	{
		ft_printf("Error\nMapa vazio ai n po!\n");
		free(all_lines);
		exit(1);
	}
}

int	find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}
