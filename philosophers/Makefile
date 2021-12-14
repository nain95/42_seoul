# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:20:52 by ijeon             #+#    #+#              #
#    Updated: 2021/12/13 15:57:02 by ijeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
SRC = ./main.c ./launcher.c ./utils.c
NAME = philo
OBJ = ${SRC:.c=.o}

all : $(NAME)

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

${NAME} :  ${OBJ}
		$(CC) ${CFLAGS} -o ${NAME} ${OBJ}

clean : 
		rm -rf ${OBJ}

fclean : clean
		rm -rf ${NAME}

re :	fclean all

.PHONY : clean fclean re all
