# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 13:36:58 by bleroy            #+#    #+#              #
#    Updated: 2021/12/23 16:36:42 by bleroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = GNL/get_next_line_utils.c \
	   GNL/get_next_line.c \
	   sources/checkmap.c \
	   sources/error.c \
	   sources/ft_strstr.c \
	   sources/key.c \
	   sources/map.c \
	   sources/move.c \
	   sources/start.c \
	   sources/useimg.c \
	   sources/player.c \

OBJS = ${SRCS:.c=.o}

NAME = so_long

CC = cc
 
CFLAGS = -Wall -Wextra -Werror

FLAGSMLX = -lmlx -framework OpenGL -framework AppKit -lz

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		$(CC) $(OBJS) $(FLAGSMLX) $(CFLAGS) -o $(NAME)

%o:	%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
		${RM} *.out
		
re: fclean all

.PHONY: all clean fclean re