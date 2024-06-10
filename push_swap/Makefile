# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 06:53:20 by kwillian          #+#    #+#              #
#    Updated: 2024/06/10 17:04:41 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NOme do meu programa
NAME := push_swap

#Aqui eu pego as bibliotecas 
LIBFT_DIR := libft
PRINT_F_DIR := printf


#Compilar com as flags da 42
CC := cc
CFLAGS := -Wall -Werror -Wextra

SRC := push_swap.c operations.c
OBJ := $(SRC:.c=o)

#inclui os diretorios de bibliotecas para o linker
LDFLAGS := -L$(LIBFT_DIR) -L$(PRINT_F_DIR)
LDLIBS := -llibft -libftprintf

all: $(LIBFT_DIR) $(PRINT_F_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINT_F_DIR)
	$(MAKE) $(NAME)

$(NAME): push_swap.c
	$(CC) -o $(NAME) push_swap.c -L(LIBFT_DIR) -libft -L(PRINT_F_DIR) -libftprintf

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINT_F_DIR)
	rm -f $(OBJECTS)
	rm -f **/*.o

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINT_F_DIR)
	rm -f $(NAME)
	rm -f **/push_swap.a

re: fclean all

