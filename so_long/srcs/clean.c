/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:03:43 by kwillian          #+#    #+#             */
/*   Updated: 2024/09/29 18:37:59 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_clenar(t_vars *vetor)
{
	mlx_destroy_image(vetor->mlx, vetor->assets->character->img);
	mlx_destroy_image(vetor->mlx, vetor->assets->water->img);
	mlx_destroy_image(vetor->mlx, vetor->assets->wood->img);
	mlx_destroy_image(vetor->mlx, vetor->assets->compass->img);
	mlx_destroy_image(vetor->mlx, vetor->assets->map->img);
	mlx_destroy_image(vetor->mlx, vetor->assets->monster->img);
	mlx_destroy_image(vetor->mlx, vetor->assets->boat->img);
	free(vetor->assets->character);
	free(vetor->assets->water);
	free(vetor->assets->wood);
	free(vetor->assets->compass);
	free(vetor->assets->map);
	free(vetor->assets->monster);
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
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	else if (assets == 2)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}
