# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:20:52 by ijeon             #+#    #+#              #
#    Updated: 2021/11/29 16:20:56 by ijeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
SRC = ./main.c ./ft_atoi.c ./ft_putstr_fd.c ./launcher.c
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
