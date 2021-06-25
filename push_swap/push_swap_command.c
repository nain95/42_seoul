/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:00:27 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/26 02:03:54 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_deque *q, int len)
{
    int tmp;

    if (deque_len(q, len) >= 2)
    {
        tmp = q->value[(q->front + 1) % len];
        q->value[(q->front + 1) % len] = q->value[(q->front + 2) % len];
        q->value[(q->front + 2) % len] = tmp;
		write(1, "s", 1);
		write(1, q->name, 1);
		write(1, "\n", 1);
    }
}

void push(t_deque *des, t_deque *src, int len)
{
    int num;

    if (deque_len(src, len) > 0)
    {
        num = pop_top(src, len);
        push_top(des, num, len);
		write(1, "p", 1);
		write(1, des->name, 1);
		write(1, "\n", 1);
    }
}

void rotate(t_deque *q, int len)
{
    int num;

    if (deque_len(q, len) > 1)
    {
        num = pop_top(q, len);
        push_rear(q, num, len);
		write(1, "r", 1);
		write(1, q->name, 1);
		write(1, "\n", 1);
    }
}


void rev_rotate(t_deque *q, int len)
{
    int num;

    if (deque_len(q, len) > 1)
    {
        num = pop_rear(q, len);
        push_top(q, num, len);
		write(1, "rr", 2);
		write(1, q->name, 1);
		write(1, "\n", 1);
	}
}

void rrr(t_deque *a, t_deque *b, int len)
{
	int num;

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
	write(1, "rrr\n", 4);
}

