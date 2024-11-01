/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:58:41 by kwillian          #+#    #+#             */
/*   Updated: 2024/10/26 22:14:26 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collected(t_vars *v)
{
	v->collect--;
	v->map[(v->y_p / 32)][(v->x_p / 32)] = '0';
	if (v->collect == 0)
		mlx_put_image_to_window(v->mlx, v->win, v->assets->boat->img,
			v->e_x, v->e_y);
}

void	move_left(t_vars *v)
{
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets->wood->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32)][(v->x_p / 32) - 1] == 'E')
		exit_verifier(v, 0, 1);
	else if (v->map[(v->y_p / 32)][(v->x_p / 32) - 1] != '1')
	{
		v->x_p -= 32;
		put_text(v);
	}
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'C')
		collected(v);
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'B')
		you_died(v);
	v->left = 1;
	if (v->existscompass== 1 && v->compass == 0)
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->character->img,
			v->x_p, v->y_p);
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->character->img,
			v->x_p, v->y_p);
}

void	move_right(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win,v->assets->wood->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32)][(v->x_p / 32) + 1] == 'E')
		exit_verifier(v, 0, 1);
	else if (v->map[(v->y_p / 32)][(v->x_p / 32) + 1] != '1')
	{
		v->x_p += 32;
		put_text(v);
	}
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'C')
		collected(v);
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'B')
		you_died(v);
	v->left = 0;
	if (v->existscompass == 1 && v->compass == 0)
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->character->img,
			v->x_p, v->y_p);
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->character->img,
			v->x_p, v->y_p);
}

void	move_up(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->wood->img, v->x_p, v->y_p);
	if ((v)->map[((v)->y_p / 32) - 1][((v)->x_p / 32)] == 'E')
		exit_verifier(v, 1, 0);
	else if ((v)->map[((v)->y_p / 32) - 1][((v)->x_p / 32)] != '1')
	{
		(v)->y_p -= 32;
		put_text(v);
	}
	move_idk(v);
}

void	move_down(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->wood->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32) + 1][(v->x_p / 32)] == 'E')
		exit_verifier(v, 1, 1);
	else if (v->map[(v->y_p / 32) + 1][(v->x_p / 32)] != '1')
	{
		v->y_p += 32;
		put_text(v);
	}
	move_idk(v);
}
