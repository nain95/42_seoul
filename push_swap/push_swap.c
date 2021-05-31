/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/31 14:27:57 by ijeon            ###   ########.fr       */
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

void push_rear_deque(t_deque *q, int data, int len)
{
	if (!is_full(q, len))
	{
		q->rear = (q->rear + 1) % len;
		q->value[q->rear] = data;
	}
}

void push_front_deque(t_deque *q, int data, int len)
{
	if (!is_full(q, len))
	{
		if (q->front == 0)
			q->front = len - 1;
		else
			q->front = (q->front - 1) % len;
		q->value[q->front] = data;
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



void print_deque(t_deque *q)
{
	int cnt;

	cnt = q->front;
	printf("=====================\n");
	while (cnt++ < q->rear)
		printf("%d\n", q->value[cnt]);
	printf("=====================\n");
}

int	main(int argc, char *argv[])
{
	t_deque q;
	int i;

	i = 1;
	init_deque(argc, &q);
	while (i < argc)
		push_rear_deque(&q, ft_atoi(argv[i++]), argc);
	print_deque(&q);
	free(q.value);
}
