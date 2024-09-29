/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:58:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/09/29 20:12:53 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_vars *vars, char *msg)
{
	int	x;

	x = 0;
	while (vars->map[x])
	{
		free(vars->map[x]);
		x++;
	}
	free(vars->map);
	ft_printf("%s", msg);
	exit(1);
}

static void	check_is_rectangular(t_vars *vars)
{
	int	map_y;
	int	map_x;
	int	height;
	int	extra;

	map_y = 0;
	map_x = 0;
	height = get_height(vars->map);
	extra = 0;
	while (map_y != height)
	{
		while (vars->map[map_y][map_x] != '\0')
			map_x++;
		map_y++;
		if (extra != 0)
		{
			if (extra != map_x)
				ft_error(vars, "Error");
		}
		else
			extra = map_x;
	}
}

void	check_map_valid(t_vars *vars)
{
	check_is_rectangular(vars);
	check_walls(vars);
	check_elemens(vars);
}
