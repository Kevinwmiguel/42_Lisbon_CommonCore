# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 19:38:58 by kwillian          #+#    #+#              #
#    Updated: 2024/04/28 18:19:12 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = *.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(MAKE) -C ./libft
	cp ./libft/libft.a ./$(NAME)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)
	rm -f **/*.o

fclean: clean
	rm -f $(NAME)
	rm -f **/libft.a

re: fclean all

.PHONY: all clean fclean re