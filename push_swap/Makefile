# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 19:59:00 by ijeon             #+#    #+#              #
#    Updated: 2021/07/01 16:32:45 by ijeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= ft

CHECKER		= get_next_line
CHECKER_NAME= checker
SRCS		= ./push_swap.c ./utils.c ./push_swap_utils.c ./push_swap_command.c ./push_swap_deque_command.c ./push_swap_under_three_case.c
OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rcs
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	$(CC) -o $(NAME) $(OBJS) -l $(LIBFT_LIB) -L $(LIBFT)
	make all -C $(CHECKER)
	mv $(CHECKER)/$(CHECKER_NAME) $(CHECKER_NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(CHECKER)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(CHECKER)

re : fclean all
