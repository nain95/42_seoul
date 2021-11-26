# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:16:02 by ijeon             #+#    #+#              #
#    Updated: 2021/11/26 15:16:42 by ijeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
MMSPATH = ./minilibx
CLFLAGS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_LIB = libft.a
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
SRC = ./so_long.c ./srcs/checker_map.c ./srcs/utils.c ./srcs/push_element.c \
		./srcs/init.c ./srcs/checker.c ./srcs/free.c ./srcs/pixel_put_image.c \
		./srcs/draw_function1.c ./srcs/draw_function2.c ./srcs/key_hook.c
NAME = so_long
OBJ = ${SRC:.c=.o}
GNL_OBJ = ${GNL:.c=.o}

all : $(NAME)

.c.o: $(SRC) $(GNL)
	$(CC) $(FLAGS) -c -o $@ $<

${NAME} :  ${OBJ}  ${GNL_OBJ}
		make all -C ${LIBFT}/
		gcc ${FLAGS} -o ${NAME} ${OBJ} ${GNL_OBJ} -L $(MMSPATH) $(CLFLAGS) -L $(LIBFT) -lft

clean : 
		make clean -C $(LIBFT)
		rm -rf ${OBJ} ${GNL_OBJ} 

fclean : clean
		rm -rf $(LIBFT)/$(LIBFT_LIB)
		rm -rf ${NAME}

re :	fclean all

.PHONY : clean fclean re all
