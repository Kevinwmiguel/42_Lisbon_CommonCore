/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:22:50 by kwillian          #+#    #+#             */
/*   Updated: 2024/10/13 22:26:35 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_xloop(t_vars *vars, int x1, int y1, int map_y)
{
	int	map_x;

	map_x = 0;
	if (vars->map[map_y] == NULL)
	{
		final_cleaner(vars, 1);
		exit (1);
	}
	while (vars->win_w > 0)
	{
		put_image_to_map(vars->map[map_y][map_x], x1, y1, vars);
		vars->win_w--;
		map_x++;
		x1 += 32;
	}
	x1 = (map_x * 32);
	return (x1);
}


t_imgs	*new_file_img(char *path, void *mlx, void *window)
{
	t_imgs	*image;

	image = (t_imgs *)malloc(sizeof(t_imgs));
	image->win = window;
	image->img = mlx_xpm_file_to_image(mlx, path, &image->width,
			&image->height);
	if (!image->img)
		write(2, "File could not be read\n", 23);
	else
		image->addr = mlx_get_data_addr(image->img, &(image->bites_per_pxl),
				&(image->line_len), &(image->endian));
	return (image);
}

void	put_pixel_img(t_imgs *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x00FFFFFF || color == -16777216)
		return ;
	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		dst = img->addr + (y * img->line_len + x * (img->bites_per_pxl / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_pixel_img(t_imgs *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_len) + (x
				* img->bites_per_pxl / 8))));
}

void	assets_initiator(t_vars *v)
{
	v->assets->character = new_file_img("assets/textures/Arrrg.xpm", v->mlx, v->win);
	v->assets->water = new_file_img("assets/textures/agua.xpm", v->mlx, v->win);
	v->assets->wood = new_file_img("assets/textures/ponte.xpm", v->mlx, v->win);
	v->assets->compass = new_file_img("assets/textures/mapa.xpm", v->mlx, v->win);
	v->assets->boat = new_file_img("assets/textures/barco.xpm", v->mlx, v->win);
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
