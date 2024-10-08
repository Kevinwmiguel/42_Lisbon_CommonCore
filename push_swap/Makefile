# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 06:53:20 by kwillian          #+#    #+#              #
#    Updated: 2024/08/21 13:29:03 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do meu programa
NAME := push_swap

# Aqui eu pego as bibliotecas 
LIBFT_DIR := libft
PRINT_F_DIR := printf
# Diretório atual onde está push_swap.h
INCLUDE_DIR := .

# Compilar com as flags da 42
CC := cc
CFLAGS := -Wall -Werror -Wextra -I$(LIBFT_DIR) -I$(PRINT_F_DIR) -I$(INCLUDE_DIR) -g

SRC := src/main.c src/push_swap.c src/operations.c src/aditional.c src/aditional2.c \
	src/sortfive.c src/r_operations.c src/tudoextra.c src/s_operations.c src/errors.c \
	 src/p_operations.c src/errors2.c src/insert_process.c src/prep.c src/help.c
OBJ := $(SRC:.c=.o)

# Inclui os diretórios de bibliotecas para o linker
LDFLAGS := -L$(LIBFT_DIR) -L$(PRINT_F_DIR)
LDLIBS := -lft -lftprintf

# Alvo padrão
all: $(LIBFT_DIR)/libft.a $(PRINT_F_DIR)/libftprintf.a $(NAME)

# Chama os Makefiles das subpastas
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(PRINT_F_DIR)/libftprintf.a:
	$(MAKE) -C $(PRINT_F_DIR)

# Compila o projeto principal
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	clear

# Regras de compilação para os arquivos objeto
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Regras de limpeza
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINT_F_DIR)
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINT_F_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re