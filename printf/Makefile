# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 19:38:58 by kwillian          #+#    #+#              #
#    Updated: 2024/04/26 16:59:10 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

var				= ../libft/

SRCS			=	$(var)ft_memcpy.c $(var)ft_isalnum.c $(var)ft_isprint.c $(var)ft_memcmp.c $(var)ft_putchar_fd.c $(var)ft_split.c \
					$(var)ft_strlcat.c $(var)ft_strncmp.c $(var)ft_substr.c $(var)ft_atoi.c $(var)ft_isalpha.c \
					$(var)ft_itoa.c $(var)ft_putendl_fd.c $(var)ft_strchr.c $(var)ft_strlcpy.c \
					$(var)ft_strnstr.c $(var)ft_tolower.c $(var)ft_bzero.c $(var)ft_isascii.c \
					$(var)ft_memmove.c $(var)ft_putnbr_fd.c $(var)ft_strdup.c $(var)ft_strlen.c $(var)ft_strrchr.c \
					$(var)ft_toupper.c $(var)ft_calloc.c $(var)ft_isdigit.c $(var)ft_memchr.c $(var)ft_memset.c \
					$(var)ft_putstr_fd.c $(var)ft_strjoin.c $(var)ft_strmapi.c $(var)ft_strtrim.c $(var)ft_striteri.c

OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

RM				= rm -f

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
				touch bonus

.PHONY:			all clean fclean re