/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:22:50 by kwillian          #+#    #+#             */
/*   Updated: 2024/10/03 22:24:52 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	assets_initiator(t_vars *v)
{
	v->assets->character = new_file_img("assets/textures/Arrrg.xpm", v->mlx, v->win);
	v->assets->water = new_file_img("assets/textures/agua.xpm", v->mlx, v->win);
	v->assets->compass = new_file_img("assets/textures/mapa.xpm", v->mlx, v->win);
	v->assets->c2 = new_file_img("assets/textures/c2.xpm", v->mlx, v->win);
	v->assets->gwc2 = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwc2, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwc2, v->assets->c2, 0, 0);
	v->assets->gwc = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwc, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwc, v->assets->character, 0, 0);
	v->assets->cwl = new_file_img("assets/textures/cl.xpm", v->mlx, v->win);
	v->assets->cwl2 = new_file_img("assets/textures/cl2.xpm", v->mlx, v->win);
	v->assets->boat = new_file_img("assets/textures/barco.xpm", v->mlx, v->win);
	assets_initiator2(v);
}
