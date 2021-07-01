/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:33 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/01 19:39:37 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_deque
{
	int		*value;
	int		rear;
	int		front;
	int		length;
	char	name;
	char	*command_list[11];
}				t_deque;

void			swap(t_deque *q, int *command);
void			push(t_deque *des, t_deque *src, int *command);
void			rotate(t_deque *q, int *command);
void			rev_rotate(t_deque *q, int *command);
void			rrr(t_deque *a, t_deque *b, int *command);

int				pop_rear(t_deque *q);
int				pop_top(t_deque *q);
int				deque_len(t_deque *q);
void			push_rear(t_deque *q, int data);
void			push_top(t_deque *q, int data);

int				get_deque(t_deque *q, int idx);
int				is_empty(t_deque *q);
int				is_full(t_deque *q);
void			init_deque(int len, t_deque *q, char c);
void			print_command(t_deque *q, int *command, int cur);

int				get_argc(int argc, char **argv);
int				*get_pivot(t_deque *q, int cnt);
void			quicksort(int *arr, int left, int right);
int				init_a(t_deque *q, int idx, char **argv);
int				check(t_deque *a);

int				get_type_num(t_deque *q);
void			three_num_sort(t_deque *a, t_deque *b, int *command);
void			three_num_rev_sort(t_deque *a, t_deque *b, int *command);
void			under_three_a_to_b(t_deque *a, t_deque *b,\
		int cnt, int *command);
void			under_three_b_to_a(t_deque *a, t_deque *b,\
		int cnt, int *command);

void			a_to_b(t_deque *a, t_deque *b, int cnt, int *command);
void			b_to_a(t_deque *a, t_deque *b, int cnt, int *command);
void			rev_ra_rb(t_deque *a, t_deque *b,\
		int *cnt_command, int *command);
#endif
