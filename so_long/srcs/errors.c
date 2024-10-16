/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:12:52 by kwillian          #+#    #+#             */
/*   Updated: 2024/10/10 22:49:07 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fmessage_error(t_vars *vars, int assets)
{
	ft_printf("Error");
	final_cleaner(vars, assets);
	exit(1);
}

void	f_error(char *file)
{
	ft_printf("can't open the file %s", file);
	exit(1);
}

static char	*error_possibility(t_map *map)
{
	if (map->c == 0)
		return ("Miss 'C'");
	else if (map->p == 0)
		return ("Miss 'P");
	else if (map->e == 0)
		return ("Miss 'e");
	else if (map->p > 1)
		return ("> 1 p");
	else if (map->e)
		return ("> 1 e");
	else if (map->b)
		return ("> 1 b");
	return ("Missing Map");
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
	if (map.e == 00 || map.p == 0 || map.c == 0 || map.p > 1 || map.b > 1 || map.e > 1)
		ft_error(vars, error_possibility(&map));
}