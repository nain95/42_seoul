/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:00:27 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/23 17:30:01 by ijeon            ###   ########.fr       */
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
    }
}

void push(t_deque *des, t_deque *src, int len)
{
    int num;

    if (deque_len(src, len) > 0)
    {
        num = pop_top(src, len);
        push_top(des, num, len);
    }
}

void rotate(t_deque *q, int len)
{
    int num;

    if (deque_len(q, len) > 1)
    {
        num = pop_top(q, len);
        push_rear(q, num, len);
    }
}


void rev_rotate(t_deque *q, int len)
{
    int num;

    if (deque_len(q, len) > 1)
    {
        num = pop_rear(q, len);
        push_top(q, num, len);
    }
}
