/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:33 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/23 17:30:22 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

# include <stdio.h>


typedef struct	s_deque
{
	int		*value;
	int		rear;
	int		front;
}				t_deque;

//-------------------------------- command
void swap(t_deque *q, int len);
void push(t_deque *des, t_deque *src, int len);
void rotate(t_deque *q, int len);
void rev_rotate(t_deque *q, int len);
//-------------------------------- deque_command
void push_rear(t_deque *q, int data, int len);
void push_top(t_deque *q, int data, int len);
int pop_rear(t_deque *q, int len);
int pop_top(t_deque *q, int len);
int deque_len(t_deque *q, int len);
//--------------------------------
int max(int a, int b);
void init_deque(int len, t_deque *q);
int is_empty(t_deque *q);
int is_full(t_deque *q, int len);
//--------------------------------
void a_to_b(t_deque *a, t_deque *b, int cnt, int len);
void b_to_a(t_deque *a, t_deque *b, int cnt, int len);
void print_deque(t_deque *a, t_deque *b, int len);



#endif
