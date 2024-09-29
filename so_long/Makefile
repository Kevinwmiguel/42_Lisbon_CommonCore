# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:10:05 by kwillian          #+#    #+#              #
#    Updated: 2024/09/24 20:38:52 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror -g

MLX_DIR = ./mlx/

OBJ_DIR = objects
OBJECTS= $(SRC:sources/%.c=%.o)

LIBFT_PATH = ./All_libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS 	=	./srcs/getnextline/get_next_line_utils.c\
			./srcs/getnextline/get_next_line.c\
			./srcs/so_long.c ./srcs/check_map.c\
			./srcs/check_file.c ./srcs/map.utils.c

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) -L./All_libs/minilibx-linux -lmlx_Linux -lXext -lX11 -o $@ $(LIBFT)
	clear
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

$(MLX): 
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(OBJ_DIR)/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	@rm -f *.o

fclean: clean
	make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME) $(OBJECTS)

re: fclean all