/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:03:43 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/05 21:22:23 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_cleaner(t_vars *vetor)
{
	mlx_destroy_image(vetor->mlx, vetor->assets->character->img);
	free(vetor->assets->character);
	mlx_destroy_image(vetor->mlx, vetor->assets->water->img);
	free(vetor->assets->water);
	mlx_destroy_image(vetor->mlx, vetor->assets->wood->img);
	free(vetor->assets->wood);
	mlx_destroy_image(vetor->mlx, vetor->assets->compass->img);
	free(vetor->assets->compass);
	mlx_destroy_image(vetor->mlx, vetor->assets->monster->img);
	free(vetor->assets->monster);
	mlx_destroy_image(vetor->mlx, vetor->assets->boat->img);
	free(vetor->assets->boat);
}

void	final_cleaner(t_vars *vars, int assets)
{
	int	i;

	i = 0;
	while (vars->map && vars->map[i] != NULL)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	if (assets == 1)
	{
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
