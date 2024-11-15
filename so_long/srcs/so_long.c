/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:27:47 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/15 15:25:46 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../All_libs/minilibx-linux/mlx.h" 
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

void	put_image_to_map(char p, int x1, int y1, t_vars *v)
{
	if (p == '1')
		mlx_put_image_to_window(v->mlx, v->win, v->assets->water->img, x1, y1);
	else if (p == 'C')
	{
		mlx_put_image_to_window(v->mlx, \
			v->win, v->assets->compass->img, x1, y1);
		v->collect++;
	}
	else if (p == 'E')
		invisible_door(v, x1, y1);
	else if (p == 'P')
	{
		v->y_p = y1;
		v->x_p = x1;
		mlx_put_image_to_window(v->mlx, v->win, \
			v->assets->character->img, x1, y1);
	}
	else if (p == 'B')
	{
		mlx_put_image_to_window(v->mlx, v->win, \
			v->assets->monster->img, x1, y1);
	}
	else
		mlx_put_image_to_window(v->mlx, v->win, v->assets->wood->img, x1, y1);
}

char	*linear(int fd, char *line, char *ml)
{
	char	*temp;

	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		temp = ft_strjoin(ml, line);
		free(ml);
		ml = temp;
		free(line);
	}
	return (ml);
}

void	load_map(t_vars *vars, char **argv)
{
	int	map_y;
	int	y1;
	int	backup_w;

	map_y = 0;
	y1 = 0;
	backup_w = vars->win_w;
	flood_checker(vars, argv);
	while (vars->win_h > 0)
	{
		map_xloop(vars, 0, y1, map_y);
		vars->win_w = backup_w;
		map_y++;
		vars->win_h--;
		y1 = (map_y * 32);
	}
}

int	count_map_lines(char *file)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	if (!check_file_is_valid(argv[1]))
		exit(1);
	vars.map = get_map(argv[1], &vars);
	if (vars.map != NULL)
	{
		check_map_valid(&vars);
		init_vars(&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, \
				vars.win_w * 32, vars.win_h * 32, "So_long");
		load_map(&vars, argv);
		mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
		mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
