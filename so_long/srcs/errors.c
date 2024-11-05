/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:12:52 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/05 21:07:38 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fmessage_error(t_vars *vars)
{
	ft_printf("Error");
	final_cleaner(vars, 0);
	exit(0);
}

void	f_error(char *file)
{
	ft_printf("can't open the file %s", file);
	exit(0);
}

static char	*error_possibility(t_map *map)
{
	if (map->c == 0)
		return ("Miss 'C'\n");
	else if (map->p == 0)
		return ("Miss 'P\n");
	else if (map->e == 0)
		return ("Miss 'e\n");
	else if (map->p > 1)
		return ("> 1 p\n");
	else if (map->e)
		return ("> 1 e\n");
	else if (map->b)
		return ("> 1 b\n");
	return ("Missing Map\n");
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
