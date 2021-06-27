/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:21:19 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/28 01:00:03 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_deque(int len, t_deque *q, char c)
{
    while ((q->value = (int *)malloc(sizeof(int) * len)) == NULL)
        continue;
    q->front = 0;
    q->rear = 0;
	q->name = c;
	q->length = len;
}

int is_empty(t_deque *q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

int is_full(t_deque *q, int len)
{
    if (is_empty(q))
        return 0;
    else if (q->front == (q->rear + 1) % len)
        return 1;
    else
        return 0;
}

int get_deque(t_deque *q, int idx, int len)
{
	return q->value[(q->front + idx + 1) % len];
}
