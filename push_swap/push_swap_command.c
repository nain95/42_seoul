/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:00:27 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/01 13:24:26 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_deque *q, int *command)
{
    int tmp;
	int len;

	len = q->length;
    if (deque_len(q, len) >= 2)
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

void push(t_deque *des, t_deque *src, int *command)
{
    int num;
	int len;

	len = des->length;
    if (deque_len(src, len) > 0)
    {
        num = pop_top(src, len);
        push_top(des, num, len);
		if (des->name == 'a')
			print_command(des, command, 3);
		else	
			print_command(des, command, 4);
    }
}

void rotate(t_deque *q, int *command)
{
    int num;
	int len;

	len = q->length;
    if (deque_len(q, len) > 1)
    {
        num = pop_top(q, len);
        push_rear(q, num, len);
		if (q->name == 'a')
			print_command(q, command, 5);
		else	
			print_command(q, command, 6);
    }
}


void rev_rotate(t_deque *q, int *command)
{
    int num;
	int len;

	len = q->length;
    if (deque_len(q, len) > 1)
    {
        num = pop_rear(q, len);
        push_top(q, num, len);
		if (q->name == 'a')
			print_command(q, command, 8);
		else	
			print_command(q, command, 9);
	}
}

void rrr(t_deque *a, t_deque *b, int *command)
{
	int num;
	int len;

	len = a->length;
    if (deque_len(a, len) > 1)
    {
        num = pop_rear(a, len);
        push_top(a, num, len);
	}
    if (deque_len(b, len) > 1)
    {
        num = pop_rear(b, len);
        push_top(b, num, len);
	}
	print_command(a, command, 10);
}
