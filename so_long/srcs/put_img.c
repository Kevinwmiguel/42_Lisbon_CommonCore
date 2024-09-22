/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:19:35 by kwillian          #+#    #+#             */
/*   Updated: 2024/09/22 16:20:59 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_cleaner2(t_vars *v)
{
	mlx_destroy_image(v->mlx, v->assets->cwl2->img);
	free(v->assets->cwl2);
	mlx_destroy_image(v->mlx, v->assets->door->img);
	free(v->assets->door);
	mlx_destroy_image(v->mlx, v->assets->gwl->img);
	free(v->assets->gwl);
	mlx_destroy_image(v->mlx, v->assets->par->img);
	free(v->assets->par);
	mlx_destroy_image(v->mlx, v->assets->gwp->img);
	free(v->assets->gwp);
	mlx_destroy_image(v->mlx, v->assets->wall->img);
	free(v->assets->wall);
	mlx_destroy_image(v->mlx, v->assets->gwd->img);
	free (v->assets->gwd);
	mlx_destroy_image(v->mlx, v->assets->gwcwl->img);
	free(v->assets->gwcwl);
	mlx_destroy_image(v->mlx, v->assets->gwcwl2->img);
	free(v->assets->gwcwl2);
	free(v->assets);
}

void	assets_cleaner(t_vars *v)
{
	mlx_destroy_image(v->mlx, v->assets->character->img);
	free(v->assets->character);
	mlx_destroy_image(v->mlx, v->assets->ground->img);
	free(v->assets->ground);
	mlx_destroy_image(v->mlx, v->assets->lantern->img);
	free(v->assets->lantern);
	mlx_destroy_image(v->mlx, v->assets->c2->img);
	free(v->assets->c2);
	mlx_destroy_image(v->mlx, v->assets->gwc2->img);
	free(v->assets->gwc2);
	mlx_destroy_image(v->mlx, v->assets->gwc->img);
	free(v->assets->gwc);
	mlx_destroy_image(v->mlx, v->assets->cwl->img);
	free(v->assets->cwl);
	mlx_destroy_image(v->mlx, v->assets->gwdwc->img);
	free(v->assets->gwdwc);
	assets_cleaner2(v);
}

void	assets_initiator2(t_vars *v)
{
	v->assets->gwl = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwl, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwl, v->assets->lantern, 0, 0);
	v->assets->par = new_file_img("Assets/par.xpm", v->mlx, v->win);
	v->assets->gwp = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwp, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwp, v->assets->par, 0, 0);
	v->assets->wall = new_file_img("Assets/wall.xpm", v->mlx, v->win);
	v->assets->gwd = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwd, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwd, v->assets->door, 0, 0);
	v->assets->gwcwl = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwcwl, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwcwl, v->assets->cwl, 0, 0);
	v->assets->gwcwl2 = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwcwl2, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwcwl2, v->assets->cwl2, 0, 0);
	v->assets->gwdwc = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwdwc, v->assets->gwd, 0, 0);
	put_img_to_img(v->assets->gwdwc, v->assets->character, 0, 0);
}

void	assets_initiator(t_vars *v)
{
	v->assets->character = new_file_img("Assets/character.xpm", v->mlx, v->win);
	v->assets->ground = new_file_img("Assets/ground.xpm", v->mlx, v->win);
	v->assets->lantern = new_file_img("Assets/lantern.xpm", v->mlx, v->win);
	v->assets->c2 = new_file_img("Assets/c2.xpm", v->mlx, v->win);
	v->assets->gwc2 = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwc2, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwc2, v->assets->c2, 0, 0);
	v->assets->gwc = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwc, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwc, v->assets->character, 0, 0);
	v->assets->cwl = new_file_img("Assets/cl.xpm", v->mlx, v->win);
	v->assets->cwl2 = new_file_img("Assets/cl2.xpm", v->mlx, v->win);
	v->assets->door = new_file_img("Assets/door.xpm", v->mlx, v->win);
	assets_initiator2(v);
}

void	put_image_to_map(char p, int x1, int y1, t_vars *v)
{
	if (p == '1')
		mlx_put_image_to_window(v->mlx, v->win, v->assets->wall->img, x1, y1);
	else if (p == 'C')
	{
		mlx_put_image_to_window(v->mlx, v->win, v->assets->gwp->img, x1, y1);
		v->collect++;
	}
	else if (p == 'E')
		invisible_door(v, x1, y1);
	else if (p == 'P')
	{
		v->y_p = y1;
		v->x_p = x1;
		mlx_put_image_to_window(v->mlx, v->win, v->assets->gwc->img, x1, y1);
	}
	else if (p == 'L')
	{
		mlx_put_image_to_window(v->mlx, v->win, v->assets->gwl->img, x1, y1);
		v->lantern++;
		v->there_was_lantern++;
	}
	else
		mlx_put_image_to_window(v->mlx, v->win, v->assets->ground->img, x1, y1);
}