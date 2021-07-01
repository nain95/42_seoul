/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:00:27 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/01 17:33:18 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *q, int *command)
{
	int tmp;
	int len;

	len = q->length;
	if (deque_len(q) >= 2)
	{
		tmp = q->value[(q->front + 1) % len];
		q->value[(q->front + 1) % len] = q->value[(q->front + 2) % len];
		q->value[(q->front + 2) % len] = tmp;
		if (q->name == 'a')
			print_command(q, command, 0);
		else
			print_command(q, command, 1);
	}
}

void	push(t_deque *des, t_deque *src, int *command)
{
	int num;

	if (deque_len(src) > 0)
	{
		num = pop_top(src);
		push_top(des, num);
		if (des->name == 'a')
			print_command(des, command, 3);
		else
			print_command(des, command, 4);
	}
}

void	rotate(t_deque *q, int *command)
{
	int num;

	if (deque_len(q) > 1)
	{
		num = pop_top(q);
		push_rear(q, num);
		if (q->name == 'a')
			print_command(q, command, 5);
		else
			print_command(q, command, 6);
	}
}

void	rev_rotate(t_deque *q, int *command)
{
	int num;

	if (deque_len(q) > 1)
	{
		num = pop_rear(q);
		push_top(q, num);
		if (q->name == 'a')
			print_command(q, command, 8);
		else
			print_command(q, command, 9);
	}
}

void	rrr(t_deque *a, t_deque *b, int *command)
{
	int num;

	if (deque_len(a) > 1)
	{
		num = pop_rear(a);
		push_top(a, num);
	}
	if (deque_len(b) > 1)
	{
		num = pop_rear(b);
		push_top(b, num);
	}
	print_command(a, command, 10);
}
