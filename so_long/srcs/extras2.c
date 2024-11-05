/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:45:18 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/05 22:06:01 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_vars *vars)
{
	vars->collect = 0;
	vars->compass = 0;
	vars->existscompass = 0;
	vars->movements = 0;
	vars->img_wall = NULL;
	vars->img_floor = NULL;
	if (vars->map[0] == NULL)
	{
		write(1, "ERROR in map\n", 13);
		final_cleaner(vars, 1);
		exit(1);
	}
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
}

void	collected(t_vars *v)
{
	v->collect--;
	v->map[(v->y_p / 32)][(v->x_p / 32)] = '0';
	if (v->collect == 0)
		mlx_put_image_to_window(v->mlx, v->win, v->assets->boat->img,
			v->e_x, v->e_y);
}

void	you_died(t_vars *v)
{
	ft_printf("You died\n");
	exit_door(v);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	put_img_to_img(t_imgs *dst, t_imgs *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
