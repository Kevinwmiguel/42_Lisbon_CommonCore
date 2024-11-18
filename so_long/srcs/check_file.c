/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:10:30 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/18 18:16:50 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_is_valid(char *file_line)
{
	char	*temp;

	temp = ft_strchr(file_line, '.');
	if (temp)
	{
		if (ft_strncmp(temp, ".ber", 5) == 0)
		{
			return (1);
		}
		else
		{
			ft_printf("ERROR\nerro encontrado no nome do mapa\n");
			return (0);
		}
	}
	else
	{
		ft_printf("ERROR\nerro encontrado no nome do mapa\n");
		return (0);
	}
	return (1);
}

int	check_c(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][n] != '\0' && vars->map[i][n] != '\n')
		{
			n++;
			if (vars->map[i][n - 1] == 'C')
			{
				ft_printf("ERROR\nNO way to collectable and exit\n");
				final_cleaner(vars, 4);
				exit(1);
			}
		}
		n = 0;
		i++;
	}
	return (1);
}

int	check_e(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][n] != '\0' && vars->map[i][n] != '\n')
		{
			n++;
			if (vars->map[i][n] == 'E')
			{
				ft_printf("ERROR\nNo way to exit\n");
				final_cleaner(vars, 0);
				exit(1);
			}
		}
		n = 0;
		i++;
	}
	return (1);
}

void	check_map_valid(t_vars *vars)
{
	check_is_rectangular(vars);
	check_walls(vars);
	check_elements(vars);
	if (!checker_way_out(vars->map, 0, 0))
	{
		ft_printf("ERROR\nno way out\n");
		final_cleaner(vars, 3);
		exit(1);
	}
}

int	map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
