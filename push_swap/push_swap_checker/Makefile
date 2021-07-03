# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 17:45:24 by ijeon             #+#    #+#              #
#    Updated: 2021/07/03 16:04:01 by ijeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c checker.c\
	   ../push_swap_command.c ../push_swap_utils.c\
	   ../push_swap_deque_command.c ../utils.c\
	   ../utils2.c
LIBFT = ../libft
LIBFT_LIB = ft

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $?

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) -l $(LIBFT_LIB) -L $(LIBFT)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
