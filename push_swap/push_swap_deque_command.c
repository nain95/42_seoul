/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:06:42 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/23 21:02:39 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_rear(t_deque *q, int data, int len)
{
    if (!is_full(q, len))
    {
        q->rear = (q->rear + 1) % len;
        q->value[q->rear] = data;
    }
}

void push_top(t_deque *q, int data, int len)
{
    if (!is_full(q, len))
    {
        q->value[q->front] = data;
        if (q->front == 0)
            q->front = len - 1;
        else
            q->front -= 1;
    }
}

int pop_rear(t_deque *q, int len)
{
    int data;

    if (!is_empty(q))
    {
        data = q->value[q->rear];
        q->rear -= 1;
		if (q->rear == -1)
			q->rear = len - 1;
        return data;
    }
    else
        return -1;
}

int pop_top(t_deque *q, int len)
{
    int data;

    if (!is_empty(q))
    {
        q->front = (q->front + 1) % len;
        data = q->value[q->front];
        return data;
    }
    else
        return -1;
}

int deque_len(t_deque *q, int len)
{
    int tmp;
    int cnt;

    cnt = 0;
    tmp = q->front;
    while (q->rear != tmp++ && ++cnt)
        tmp %= len;
    return (cnt);
}
