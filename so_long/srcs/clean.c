/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:03:43 by kwillian          #+#    #+#             */
/*   Updated: 2024/10/11 22:10:33 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_cleaner(t_vars *vetor)
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

char	*ft_join_strings(char *s1, char *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	char			*ptr;

	if (!s1)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1_len-- != 0)
		ptr[i++] = *s1++;
	while (s2_len-- != 0)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
