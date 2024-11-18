# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:10:05 by kwillian          #+#    #+#              #
#    Updated: 2024/11/18 00:39:15 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror -g

MLX_DIR = ./mlx/

OBJ_DIR = objects
OBJECTS= $(SRC:sources/%.c=%.o)
SRC_DIR				= ./srcs/

LIBFT_PATH = ./All_libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS 	=	./srcs/get_next_line/get_next_line_utils.c \
			./srcs/get_next_line/get_next_line.c \
			$(SRC_DIR)so_long.c $(SRC_DIR)check_map.c\
			$(SRC_DIR)check_file.c $(SRC_DIR)map.functions.c \
			$(SRC_DIR)assets.c $(SRC_DIR)clean.c \
			$(SRC_DIR)errors.c $(SRC_DIR)extras.c \
			$(SRC_DIR)move.c $(SRC_DIR)extras2.c \
			$(SRC_DIR)map.functions2.c

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) -L./All_libs/minilibx-linux -lmlx_Linux -lXext -lX11 -o $@ $(LIBFT)
	clear
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

$(MLX): 
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	make -s -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	@rm -f *.o

fclean: clean
	make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME) $(OBJECTS)

re: fclean all