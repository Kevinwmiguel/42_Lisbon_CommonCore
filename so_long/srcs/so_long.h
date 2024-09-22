/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:28:39 by kwillian          #+#    #+#             */
/*   Updated: 2024/09/22 16:30:52 by kwillian         ###   ########.fr       */
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
	t_imgs	*lantern;
	t_imgs	*ground;
	t_imgs	*character;
	t_imgs	*gwc;
	t_imgs	*cwl;
	t_imgs	*door;
	t_imgs	*gwl;
	t_imgs	*par;
	t_imgs	*gwp;
	t_imgs	*wall;
	t_imgs	*gwd;
	t_imgs	*gwdwc;
	t_imgs	*gwcwl;
	t_imgs	*c2;
	t_imgs	*gwc2;
	t_imgs	*cwl2;
	t_imgs	*gwcwl2;
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
}	t_vars;

typedef struct s_map
{
	int	c;
	int	p;
	int	e;
	int	l;
	int	x;
	int	y;
}	t_map;

void	final_cleaner(t_vars *vars, int assets);
int	key_hook(int keycode, t_vars *vars);
void	put_image_to_map(char p, int x1, int y1, t_vars *v);
void	check_file_is_valid(char *file_line);
void	assets_cleaner2(t_vars *v);
void	assets_cleaner(t_vars *v);
void	assets_initiator2(t_vars *v);
void	put_image_to_map(char p, int x1, int y1, t_vars *v);
t_imgs	*new_img(int w, int h, t_vars *mlx, t_vars *window);
t_imgs	*new_file_img(char *path, void *mlx, void *window);
void	put_pixel_img(t_imgs *img, int x, int y, int color);
unsigned int	get_pixel_img(t_imgs *img, int x, int y);
void	put_img_to_img(t_imgs *dst, t_imgs *src, int x, int y);

#endif