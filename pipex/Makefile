# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:58:11 by ijeon             #+#    #+#              #
#    Updated: 2021/06/09 14:58:21 by ijeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ./pipex.c
OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	$(CC) -L libft -l ft -o $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
