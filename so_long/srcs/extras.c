/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:11:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/10/13 22:35:51 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_verifier(t_vars *v, int xy, int vet)
{
	if (v->collect <= 0)
		exit_door(v);
	else
	{
		if (xy == 0)
		{
			if (vet == 0)
				v->x_p -= 32;
			else if (vet == 1)
				v->x_p += 32;
		}
		else if (xy == 1)
		{
			if (vet == 0)
				v->y_p -= 32;
			else if (vet == 1)
				v->y_p += 32;
		}
	}
}

void	exit_door(t_vars *v)
{
	final_cleaner(v, 1);
	exit(1);
}

void	put_text(t_vars *v)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;

	number = ft_itoa(++(v)->movements);
	text = ft_join_strings("Move: ", number);
	v->img_wall = mlx_xpm_file_to_image(
			v->mlx, "assets/textures/agua.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets->water->img, 0, 0);
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets->water->img, 32, 0);
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets->water->img, 32 * 2, 0);
	mlx_string_put(v->mlx, v->win, 5, 10, 0xfffffff, text);
	ft_printf("%s\n", number);
	free(text);
	free(number);
}

void	lantern(t_vars *v)
{
	v->compass--;
	v->map[(v->y_p / 32)][(v->x_p / 32)] = '0';
}

void	move_idk(t_vars *v)
{
	if ((v)->map[((v)->y_p / 32)][((v)->x_p / 32)] == 'C')
		collected(v);
	if ((v)->map[((v)->y_p / 32)][((v)->x_p / 32)] == 'B')
		lantern(v);
	if (v->existscompass == 1 && v->compass == 0 && v->left == 0)
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->character->img,
			v->x_p, v->y_p);
	else if (v->left == 1)
	{
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->compass->img, v->x_p, v->y_p);
		if (v->existscompass == 1 && v->compass == 0)
			mlx_put_image_to_window(v->mlx, v->win,
				v->assets->character->img,
				v->x_p, v->y_p);
	}
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->character->img,
			v->x_p, v->y_p);
}
