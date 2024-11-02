/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:03:43 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/02 14:47:59 by kwillian         ###   ########.fr       */
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
			printf("hello");
			mlx_destroy_window(vars->mlx, vars->win);
			mlx_destroy_display(vars->mlx);
		}
		if (vars->mlx)	
			free(vars->mlx);
		vars->mlx = NULL;
		//free(vars->img_wall);
		if (vars->mlx != NULL)
			printf("letters");
		
	}
	// else if (assets == 2)
	// {
	// 	assets_cleaner(vars);
	// 	if (vars->mlx && vars->win)
	// 	{
	// 		printf("hello2");
	// 		mlx_destroy_window(vars->mlx, vars->win);
	// 		mlx_destroy_display(vars->mlx);
	// 	}
	// 	if (vars->win)
	// 		free(vars->win);
	// 	if (vars->mlx)	
	// 		free(vars->mlx);
	// 	if (vars->mlx != NULL)
	// 		printf("letters2");
	// }
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
