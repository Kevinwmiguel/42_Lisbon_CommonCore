/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:27:47 by kwillian          #+#    #+#             */
/*   Updated: 2024/10/03 22:26:06 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../All_libs/minilibx-linux/mlx.h" 
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

void	load_images(t_vars *vars)
{
	// Alocando memória para assets
	vars->assets = malloc(sizeof(t_assets));
	if (!vars->assets)
	{
		printf("Erro ao alocar memória para assets\n");
		exit(1);
	}
	// Carregar imagem da parede (madeira)
	vars->assets->wood = malloc(sizeof(t_imgs) * 32);
	vars->assets->wood->img = mlx_xpm_file_to_image(vars->mlx, "assets/textures/ponte.xpm", &vars->img_width, &vars->img_height);
	if (!vars->assets->wood->img)
	{
		printf("Erro ao carregar a imagem da madeira\n");
		exit(1);
	}
	// Carregar imagem do chão (mapa)
	vars->assets->map = malloc(sizeof(t_imgs) * 32);
	vars->assets->map->img = mlx_xpm_file_to_image(vars->mlx, "assets/textures/mapa.xpm", &vars->img_width, &vars->img_height);
	if (!vars->assets->map->img)
	{
		printf("Erro ao carregar a imagem do mapa\n");
		exit(1);
	}
	// Carregar outros assets
	// Água
	vars->assets->water = malloc(sizeof(t_imgs) * 32);
	vars->assets->water->img = mlx_xpm_file_to_image(vars->mlx, "assets/textures/agua.xpm", &vars->img_width, &vars->img_height);
	if (!vars->assets->water->img)
	{
		printf("Erro ao carregar a imagem da água\n");
		exit(1);
	}
	// Personagem
	vars->assets->character = malloc(sizeof(t_imgs) * 32);
	vars->assets->character->img = mlx_xpm_file_to_image(vars->mlx, "assets/textures/Arrrg.xpm", &vars->img_width, &vars->img_height);
	if (!vars->assets->character->img)
	{
		printf("Erro ao carregar a imagem do personagem\n");
		exit(1);
	}
	// Barco
	vars->assets->boat = malloc(sizeof(t_imgs) * 32);
	vars->assets->boat->img = mlx_xpm_file_to_image(vars->mlx, "assets/textures/barco.xpm", &vars->img_width, &vars->img_height);
	if (!vars->assets->boat->img)
	{
		printf("Erro ao carregar a imagem do barco\n");
		exit(1);
	}
}

void	put_image_to_map(char p, int x1, int y1, t_vars *v)
{
	if (p == '1') // Parede
		mlx_put_image_to_window(v->mlx, v->win, v->assets->wood->img, x1, y1);
	else if (p == 'C') // Colecionável
	{
		mlx_put_image_to_window(v->mlx, v->win, v->assets->character->img, x1, y1);
		v->collect++;  // Incrementa a quantidade de colecionáveis no mapa
	}
	else if (p == 'E') // Saída/Inimigo
		invisible_door(v, x1, y1); // Supondo que você já tenha essa função implementada
	else if (p == 'P') // Personagem
	{
		v->y_p = y1;  // Armazena a posição Y do personagem
		v->x_p = x1;  // Armazena a posição X do personagem
		mlx_put_image_to_window(v->mlx, v->win, v->assets->boat->img, x1, y1);
	}
	else if (p == 'W') // Água
	{
		mlx_put_image_to_window(v->mlx, v->win, v->assets->water->img, x1, y1);
	}
	else // Chão
		mlx_put_image_to_window(v->mlx, v->win, v->assets->map->img, x1, y1);
}

char	*linear(int fd, char *line, char *ml)
{
	char	*temp;

	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\0')
		{
			free(line);
			break ;
		}
		temp = ft_strjoin(ml, line);
		free(ml);
		ml = temp;
		free(line);
	}
	return (ml);
}

void	**load_map2(char *mapfile, t_vars *vars)
{
	int		fd;
	char	*line;
	char	**splits;
	char	*mapll;

	line = "";
	mapll = ft_strdup("");
	fd = open(mapll, O_RDONLY);
	if (fd < 0)
	{
		free(mapll);
		ferror(mapll);
	}
	mapll = linear(fd, line, mapll);
	close(fd);
	if (!mapll)
		fmessage_error(vars, 0);
	splits = ft_split(mapll, '\n');
	free(mapll);
	return (splits);
}
void	load_map(t_vars *vars, char **argv)
{
	int	map_y;
	int	y1;
	int backup_w;

	map_y = 0;
	y1 = 0;
	backup_w = vars->win_w;
	flood_checker(vars, argv);
	while (vars->win_h > 0)
	{
		map_xloop(vars, 0, y1, map_y);
		vars->win_w = backup_w;
		map_y;
		vars->win_h--;
		y1 = (map_y * 32);
	}
}

int	map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	count_map_lines(char *file)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		line_count++;
	}
	close(fd);
	return (line_count);
}

void	init_vars(t_vars *vars)
{
	vars->collect = 0;
	vars->compass = 0;
	vars->existscompass = 0;
	vars->movements = 0;
	if (vars->map[0] == NULL)
	{
		write(1, "ERROR in map\n", 13);
		final_cleaner(vars, 0);
		exit(1);
	}
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	// Checa se o mapa ´e valido
	check_file_is_valid(argv[1]);
	vars.map = load_map(argv[1], &vars);
	if (vars.map != NULL)
	{
		//inicia os valores recebendo tudo e atribuindo valores
		init_vars(&vars);
		//checa o mapa
		check_map_valid(&vars);
		// Inicializa a conexão com o MiniLibX
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.win_w * 32, vars.win_h * 32, "so_long");
		load_map(&vars, argv);
	}
	
	// Carregar o mapa
	load_map(&vars, argv[1]);
	// Definir as dimensões da janela com base no mapa
	load_images(&vars);
	
	
	// Desenhar o mapa na janela

	// Loop do MiniLibX
	mlx_loop(vars.mlx);

	return (0);
}
