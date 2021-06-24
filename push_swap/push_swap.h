/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:33 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/24 23:54:05 by ijeon            ###   ########.fr       */
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
	char	name[2];
}				t_deque;

//-------------------------------- command
void swap(t_deque *q, int len);
void push(t_deque *des, t_deque *src, int len);
void rotate(t_deque *q, int len);
void rev_rotate(t_deque *q, int len);
void rrr(t_deque *a, t_deque *b, int len);
//-------------------------------- deque_command
void push_rear(t_deque *q, int data, int len);
void push_top(t_deque *q, int data, int len);
int pop_rear(t_deque *q, int len);
int pop_top(t_deque *q, int len);
int deque_len(t_deque *q, int len);
//-------------------------------- deque_utils
int get_deque(t_deque *q, int idx, int len);
void init_deque(int len, t_deque *q, char c);
int is_empty(t_deque *q);
int is_full(t_deque *q, int len);
//-------------------------------- utils
void swap_num(int *num1, int *num2);
int max(int a, int b);
int min(int a, int b);
//-------------------------------- main
void a_to_b(t_deque *a, t_deque *b, int cnt, int len);
void b_to_a(t_deque *a, t_deque *b, int cnt, int len);
void print_deque(t_deque *a, t_deque *b, int len);
int *get_pivot(t_deque *q, int cnt, int len);
void quicksort(int *arr, int left, int right);

#endif
