/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:58:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/10/02 21:02:04 by kwillian         ###   ########.fr       */
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

static int	check_line(char *line)
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

static void	check_walls(t_vars *vetor)
{
	int	i;
	char	*message;

	message = "[ERROR] not all 4 walls";
	if (check_line(vetor->map[0]))
		ft_error(vetor, message);
	i = get_height(vetor->map) - 1;
	while (i)
	{
		if (vetor->map[i][0] != '1' || vetor->map[1][ft_strlen(vetor->map[i]) - 1] != '1')
			ft_error(vetor, message);
		i--;
	}
	if (check_line(vetor->map[get_height(vetor->map) - 1]))
		ft_error(vetor, message);
}

void	check_map_valid(t_vars *vars)
{
	check_is_rectangular(vars);
	check_walls(vars);
	check_elemens(vars);
}
