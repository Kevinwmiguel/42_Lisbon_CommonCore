# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 06:53:20 by kwillian          #+#    #+#              #
#    Updated: 2024/06/06 20:45:54 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NOme do meu programa
NAME: = push_swap.a

#Aqui eu pego as bibliotecas 
LIBFT_DIR := libft
PRINT_F_DIR := printf

CC: := cc

#Compilar com as flags da 42
CFLAGS := -Wall -Werror -Wextra

all: $(LIBFT_DIR) $(PRINT_F_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINT_F_DIR)
	$(MAKE) $(NAME)

$(NAME): main.c push_swap.c
	cc -o $(NAME) main.c push_swap.c -L(LIBFT_DIR) -libft -L(PRINT_F_DIR) -libftprintf

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

