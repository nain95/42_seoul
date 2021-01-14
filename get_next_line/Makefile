# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 19:57:15 by ijeon             #+#    #+#              #
#    Updated: 2021/01/13 17:44:03 by ijeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c main.c

OBJS = $(SRCS:.c=.o)


%.o : %.c
	$(CC) $(CFLAGS) -c $?

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
