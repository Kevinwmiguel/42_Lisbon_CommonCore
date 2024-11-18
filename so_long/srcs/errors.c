/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:12:52 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/18 18:18:32 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fmessage_error(t_vars *vars, int n)
{
	ft_printf("ERROR\n in map\n");
	final_cleaner(vars, n);
	exit(0);
}

void	f_error(char *file)
{
	ft_printf("ERROR\ncan't open the file %s", file);
	exit(0);
}

static char	*error_possibility(t_map *map)
{
	if (map->c == 0)
		return ("ERROR\nMiss 'C'");
	else if (map->p == 0)
		return ("ERROR\nMiss 'P'");
	else if (map->e == 0)
		return ("ERROR\nMiss 'E'");
	else if (map->p > 1)
		return ("ERROR\n> 1 p");
	else if (map->e)
		return ("ERROR\n> 1 e");
	else if (map->b)
		return ("> 1 b");
	return ("ERROR\nMissing Map");
}

void	check_elements(t_vars *vars)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height(vars->map);
	map.b = 0;
	map = map_check_initiatializer(vars, map);
	if (map.b == 1)
		vars->compass++;
	if (map.e == 00 || map.p == 0 \
		|| map.c == 0 || map.p > 1 || map.b > 1 || map.e > 1)
		ft_error(vars, error_possibility(&map));
}

void	ft_error(t_vars *vars, char *message)
{
	int	x;

	x = 0;
	while (vars->map[x])
	{
		free(vars->map[x]);
		x++;
	}
	free (vars->map);
	ft_printf("%s\n", message);
	exit (1);
}
