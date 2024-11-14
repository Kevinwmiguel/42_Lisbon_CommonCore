/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:03:43 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/14 17:07:43 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_cleaner(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->assets->character->img);
	free(vars->assets->character);
	mlx_destroy_image(vars->mlx, vars->assets->water->img);
	free(vars->assets->water);
	mlx_destroy_image(vars->mlx, vars->assets->wood->img);
	free(vars->assets->wood);
	mlx_destroy_image(vars->mlx, vars->assets->compass->img);
	free(vars->assets->compass);
	mlx_destroy_image(vars->mlx, vars->assets->monster->img);
	free(vars->assets->monster);
	mlx_destroy_image(vars->mlx, vars->assets->boat->img);
	free(vars->assets->boat);
	free(vars->assets);
}

// static void	free_map(t_vars *vars)
// {
// 	int	i;

// 	i = 0;
// 	while (vars->map && vars->map[i] != NULL)
// 	{
// 		free(vars->map[i]);
// 		i++;
// 	}
// 	free(vars->map);
// }

void	final_cleaner(t_vars *vars, int assets)
{
	int	i;

	i = 0;
	if (assets == 4)
	{
		while (vars->map && vars->map[i] != NULL)
		{
			free(vars->map[i]);
			i++;
		}
		free(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		return ;
	}
	if (assets == 1)
	{
		while (vars->map && vars->map[i] != NULL)
		{
			free(vars->map[i]);
			i++;
		}
		free(vars->map);
		assets_cleaner(vars);
		if (vars->mlx && vars->win)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			mlx_destroy_display(vars->mlx);
			free(vars->mlx);
		}
	}
}

int	ft_exit(t_vars *vars)
{
	final_cleaner(vars, 1);
	exit(1);
}
