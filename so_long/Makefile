# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:16:02 by ijeon             #+#    #+#              #
#    Updated: 2021/11/16 19:02:13 by ijeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MMSPATH = ./minilibx
CLFLAGS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_LIB = libft.a
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
SRC = ./so_long.c ./srcs/so_long_utils.c ./srcs/checker_map.c
NAME = so_long
OBJ = ${SRC:.c=.o}
OBJS = ${GNL:.c=.o}

all : $(NAME)

.c.o: $(SRC) $(GNL)
	$(CC) $(CFLAGS) -c -o $@ $<

${NAME} :  ${OBJ}  ${OBJS}
		make all -C ${LIBFT}/
		gcc ${FLAGS} -o ${NAME} ${OBJ} ${OBJS} -L $(MMSPATH) $(CLFLAGS) -L ${LIBFT} -l ft

clean : 
		rm -rf ${OBJ} ${OBJS}

fclean : clean
		rm -rf ${NAME}

re :	fclean all