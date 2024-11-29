# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 12:37:09 by kwillian          #+#    #+#              #
#    Updated: 2024/11/29 12:39:02 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror -g

OBJ_DIR = objects
OBJECTS= $(SRC:sources/%.c=%.o)
SRC_DIR				= ./srcs/

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS 	=	$(SRC_DIR)pipex.c

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) -o $@ $(LIBFT)
	clear
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

$(MLX): 
	$(MAKE) -C $()

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