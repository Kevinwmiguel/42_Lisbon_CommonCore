/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:58:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/18 19:09:41 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *fmap, t_vars *vars)
{
	char	*line;
	char	*all_lines;
	int		fd;
	char	**result;

	line = "";
	all_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
	{
		free(all_lines);
		ft_printf("Error\nNo map\n");
		exit(1);
	}
	all_lines = linear(fd, line, all_lines);
	ft_empty_map(all_lines);
	close(fd);
	if (!all_lines)
		fmessage_error(vars, 0);
	if (check_nl(all_lines) == 1)
		lines_mistake(all_lines);
	result = ft_split(all_lines, '\n');
	free(all_lines);
	return (result);
}

void	flood_fill(char **map, int x, int y)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (map[h][w] != '\0' && map[h][w] != '\n')
		w++;
	while (map[h])
		h++;
	if (x < 0 || y < 0 || x >= w || y >= h)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, (x + 1), y);
	flood_fill(map, (x - 1), y);
	flood_fill(map, x, (y + 1));
	flood_fill(map, x, (y - 1));
}

void	get_player(t_vars *vars)
{
	int	map_y;
	int	backup_w;
	int	map_x;

	map_y = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		map_x = 0;
		while (vars->win_w > 0)
		{
			if (vars->map[map_y][map_x] == 'P')
			{
				vars->x_p = map_x;
				vars->y_p = map_y;
			}
			vars->win_w--;
			map_x++;
		}
		vars->win_w = backup_w;
		map_y++;
		vars->win_h--;
	}
	init_vars(vars);
}

void	flood_checker(t_vars *vars, char **argv)
{
	get_player(vars);
	flood_fill(vars->map, vars->x_p, vars->y_p);
	check_c(vars);
	check_e(vars);
	final_cleaner(vars, 0);
	vars->map = get_map(argv[1], vars);
	vars->assets = malloc(sizeof(t_assets));
	assets_initiator(vars);
}
