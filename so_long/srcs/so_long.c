/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:27:47 by kwillian          #+#    #+#             */
/*   Updated: 2024/09/22 16:24:37 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../All_libs/minilibx-linux/mlx.h" 
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"



void	load_images(t_vars *vars)
{
	// Carregar imagem da parede
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx, "path/to/wall.xpm", &vars->img_width, &vars->img_height);
	if (!vars->img_wall)
	{
		printf("Erro ao carregar a imagem da parede\n");
		exit(1);
	}
	// Carregar imagem do chão
	vars->img_floor = mlx_xpm_file_to_image(vars->mlx, "path/to/floor.xpm", &vars->img_width, &vars->img_height);
	if (!vars->img_floor)
	{
		printf("Erro ao carregar a imagem do chão\n");
		exit(1);
	}
}

void	draw_map(t_vars *vars)
{
	int x, y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1') // Posição da parede
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall, x * 32, y * 32);
			else if (vars->map[y][x] == '0') // Posição do chão
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
void	load_map(t_vars *vars, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Erro ao abrir o arquivo de mapa\n");
		exit(1);
	}

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		vars->map[i] = line; // Salva a linha na matriz de mapa
		i++;
	}
	vars->map[i] = NULL; // Marca o final do mapa
	close(fd);
}
int	map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}


int	main(int argc, char **argv)
{
	t_vars	vars;
	if (argc != 2)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	//Checa se o mapa ´e valido
	check_file_is_valid(argv[1]);
	
	// Inicializa a conexão com o MiniLibX
	vars.mlx = mlx_init();
	
	// Carregar o mapa
	load_map(&vars, argv[1]);

	// Definir as dimensões da janela com base no mapa
	vars.win_w = 32 * ft_strlen(vars.map[0]); // Largura em pixels (supondo que cada tile é 32x32)
	vars.win_h = 32 * map_height(vars.map); // Altura em pixels

	// Criar a janela
	vars.win = mlx_new_window(vars.mlx, vars.win_w, vars.win_h, "So_Long");

	// Carregar as imagens
	load_images(&vars);

	// Desenhar o mapa na janela
	draw_map(&vars);

	// Loop do MiniLibX
	mlx_loop(vars.mlx);

	return (0);
}
