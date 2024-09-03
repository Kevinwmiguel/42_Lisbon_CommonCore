# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:10:05 by kwillian          #+#    #+#              #
#    Updated: 2024/09/03 16:37:08 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

SRCS			=	

OBJS			= $(SRCS:.c=.o)

BONUS			=	

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