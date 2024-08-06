# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 12:18:35 by mmata-al          #+#    #+#              #
#    Updated: 2024/08/06 20:31:52 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do programa
NAME = push_swap

# Diretórios das bibliotecas e includes
SRC_DIR = src/
LIBFT_DIR = $(SRC_DIR)/libft/
PRINTF_DIR = $(SRC_DIR)/printf/
LDFLAGS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf

# Arquivos fonte do projeto
PUSHSWAP = $(SRC_DIR)push_swap_commands/error_handler.c \
           $(SRC_DIR)push_swap_commands/a_to_b.c \
           $(SRC_DIR)push_swap_commands/push_swap.c \
           $(SRC_DIR)push_swap_commands/b_to_a.c \
           $(SRC_DIR)push_swap_commands/stack_init.c \
           $(SRC_DIR)push_swap_commands/split.c \
           $(SRC_DIR)push_swap_commands/stack_utils.c

COMMANDS = $(SRC_DIR)commands/push.c \
           $(SRC_DIR)commands/rev_rotate.c \
           $(SRC_DIR)commands/sort_all_numbers.c \
           $(SRC_DIR)commands/swap.c \
           $(SRC_DIR)commands/rotate.c \
           $(SRC_DIR)commands/sort_3.c \
           $(SRC_DIR)commands/move_b_to_a.c

SRCS = $(PUSHSWAP) $(COMMANDS)
OBJS = $(SRCS:.c=.o)

# Compilador e flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(SRC_DIR) -I$(LIBFT_DIR)include -I$(PRINTF_DIR)include -g

# Regras de compilação
all: $(LIBFT_DIR)libft.a $(PRINTF_DIR)libftprintf.a $(NAME)

$(LIBFT_DIR)libft.a:
	@make -C $(LIBFT_DIR)

$(PRINTF_DIR)libftprintf.a:
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpeza de arquivos
clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
