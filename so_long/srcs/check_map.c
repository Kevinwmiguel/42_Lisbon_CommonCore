/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:09:55 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/05 22:08:18 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	map_check_initiatializer(t_vars *vars, t_map map)
{
	map.x = 0;
	while (map.y--)
	{
		map.x = 0;
		while (vars->map[map.y][map.x] != '\0')
		{
			if (vars->map[map.y][map.x] == 'E')
				map.e++;
			else if (vars->map[map.y][map.x] == 'P')
				map.p++;
			else if (vars->map[map.y][map.x] == 'C')
				map.c++;
			else if (vars->map[map.y][map.x] == 'B')
				map.b++;
			else if (vars->map[map.y][map.x] != '1' \
						&& vars->map[map.y][map.x] != '0' \
						&& vars->map[map.y][map.x] != '\n' \
						&& vars->map[map.y][map.x] != '\0')
				ft_error(vars, "Wrong Element stupid");
			map.x++;
		}
	}
	return (map);
}

void	invisible_door(t_vars *v, int x1, int y1)
{
	mlx_put_image_to_window(v->mlx, v->win, v->assets->water->img, x1, y1);
	v->e_x = x1;
	v->e_y = y1;
}

void	check_is_rectangular(t_vars *vars)
{
	int	map_x;
	int	map_y;
	int	backup;
	int	height;

	map_y = 0;
	map_x = 0;
	backup = 0;
	height = get_height(vars->map);
	while (map_y != height)
	{
		map_x = 0;
		while (vars->map[map_y][map_x] != '\0')
			map_x++;
		map_y++;
		if (backup != 0)
		{
			if (backup != map_x)
				ft_error(vars, "Error");
		}
		else
			backup = map_x;
	}
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != 49)
			return (1);
		i++;
	}
	return (0);
}

void	check_walls(t_vars *v)
{
	int		i;
	char	*message;

	message = "[ERROR] Not surrounded by walls";
	if (v->map[0] && check_line(v->map[0]))
		ft_error(v, message);
	i = get_height(v->map) - 1;
	if (i < 0)
		i = 0;
	while (i)
	{
		if (v->map[i][0] != '1' ||
			v->map[i][ft_strlen(v->map[i]) - 1] != '1')
			ft_error(v, message);
		i--;
	}
	if (check_line(v->map[get_height(v->map) - 1]))
	{
		ft_error(v, message);
	}
}
