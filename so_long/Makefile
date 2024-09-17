# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:10:05 by kwillian          #+#    #+#              #
#    Updated: 2024/09/06 19:48:23 by kwillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

#Dir
LIB_DIR			= All_libs/libft/
OBJ_DIR			= obj_dir/
SRC_DIR			= srcs/
MLX				= -L./All_libs/libft
#Sources
SRCS			=	SOLONG

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

.PHONY:			start all clean fclean re