# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 19:38:58 by kwillian          #+#    #+#              #
#    Updated: 2024/06/10 18:22:57 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_putchar_fd2.c ft_putstr_fd2.c \
ft_putnbr_ptr_fd.c ft_putnbr_fd2.c ft_strlen2.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
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