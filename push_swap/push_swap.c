/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/30 19:11:25 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_deque(int len, t_deque *q)
{
	while ((q->value = (int *)malloc(sizeof(int) * len)) == NULL)
		continue;
	q->front = 0;
	q->rear = 0;
}

int is_full(t_deque *q, int len)
{
	if (q->front == (q->rear + 1) % len)
		return 1;
	else
		return 0;
}

int is_empty(t_deque *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void push_deque(t_deque *q, int data, int len)
{
	if (!is_full(q, len))
	{
		q->rear = (q->rear + 1) % len;
		q->value[q->rear] = data;
	}
}

int delete_front(t_deque *q, int len)
{
	int data;

	if (!is_empty(q))
	{
		q->front = (q->front+1) % len;
		data = q->value[q->front];
		return data;
	}
	else
		return -1;
}

int	main(int argc, char *argv[])
{
	t_deque q;
	int i;

	i = 1;
	init_deque(argc, &q);
	while (i < argc)
	{
		push_deque(&q, ft_atoi(argv[i++]), argc);
	}
	i = 1;
	while (i++ < argc)
	{
		printf("%d ",delete_front(&q, argc));
	}
}
