/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:28:39 by kwillian          #+#    #+#             */
/*   Updated: 2024/10/09 21:38:27 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "../All_libs/minilibx-linux/mlx.h"
# include "./getnextline/get_next_line.h"
# include <X11/keysym.h>
# include "../All_libs/libft/libft.h"

typedef struct s_imgs
{
	char	*addr;
	int		bites_per_pxl;
	int		endian;
	int		height;
	int		line_len;
	int		width;
	void	*win;
	void	*img;
}				t_imgs;

typedef struct s_assets
{
	t_imgs	*water;
	t_imgs	*character;
	t_imgs	*boat;
	t_imgs	*compass;
	t_imgs	*map;
	t_imgs	*wood;
	t_imgs	*monster;
}	t_assets;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	int		img_width;
	int		img_height;
	char	**map;
	int		win_w;
	int		win_h;
	int				e_x;
	int				e_y;
	t_assets *assets;
	int		collect;   // Quantidade de colecionáveis
	int		compass;   // Quantidade da bussola ?
	int		existscompass;
	int		movements;
	int		x_p;       // Posição X do personagem
	int		y_p;       // Posição Y do personagem
}	t_vars;

typedef struct s_map
{
	int	p; // personagem 
	int	e; //barco
	int	c; // MApa
	int	w; // agua
	int	wo; //madeira
	int	x; // cordenada
	int	y; // cordenada
	int	b; // bussola
}	t_map;

void	check_file_is_valid(char *file_line);
int		find(char *str, char *to_find);
void	fmessage_error(t_vars *vars, int assets);
void	ferror(char *file);
void	final_cleaner(t_vars *vars, int assets);
int	get_height(char **map);
t_map	map_check_initiatializer(t_vars *vars, t_map map);
void	check_map_valid(t_vars *vars);
void	check_elements(t_vars *vars);
void	ft_error(t_vars *vars, char *message);
void	init_vars(t_vars *vars);
char	*linear(int fd, char *line, char *ml);

void	flood_checker(t_vars *vars, char **argv);
void	get_player(t_vars *vars);
int	check_e(t_vars *vars);
int	check_c(t_vars *vars);
char	**get_map(char *fmap, t_vars *vars);
void	flood_fill(char **map, int x, int y);
void	assets_initiator(t_vars *v);

void	put_pixel_img(t_imgs *img, int x, int y, int color);
unsigned int	get_pixel_img(t_imgs *img, int x, int y);
t_imgs	*new_file_img(char *path, void *mlx, void *window);

void	put_image_to_map(char p, int x1, int y1, t_vars *v);
void	invisible_door(t_vars *v, int x1, int y1);

#endif