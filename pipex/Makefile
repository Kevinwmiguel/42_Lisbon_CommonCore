# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 12:37:09 by kwillian          #+#    #+#              #
#    Updated: 2025/02/02 19:01:46 by kwillian         ###   ########.fr        #
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

SRCS 	=	$(SRC_DIR)pipex.c $(SRC_DIR)closes.c \
			$(SRC_DIR)ft_free_split.c $(SRC_DIR)checkers.c \
			$(SRC_DIR)children.c $(SRC_DIR)aux.c $(SRC_DIR)aux2.c \
			$(SRC_DIR)path.c

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) -o $@ $(LIBFT)
	clear
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@


$(LIBFT):
	make -s -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	@rm -f *.o
	clear

fclean: clean
	make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME) $(OBJECTS)
	clear
	@echo Never is a good bye...

loading:
	@echo "Let's do Magic..."
	@i=0; \
	while [ $$i -lt 40 ]; do \
		if [ $$((i % 4)) -eq 0 ]; then printf "\033[32m\r◜\033[0m"; fi; \
		if [ $$((i % 4)) -eq 1 ]; then printf "\033[32m\r◝\033[0m"; fi; \
		if [ $$((i % 4)) -eq 2 ]; then printf "\033[32m\r◞\033[0m"; fi; \
		if [ $$((i % 4)) -eq 3 ]; then printf "\033[32m\r◟\033[0m"; fi; \
		sleep 0.15; \
		i=$$((i + 1)); \
	done; \
	echo "\r\033[32mAbrakadabra!!\033[0m"

re: fclean all loading