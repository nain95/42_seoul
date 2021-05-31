/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/31 21:42:24 by ijeon            ###   ########.fr       */
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
			q->front = (q->front - 1) % len;
	}
}

int pop_top(t_deque *q, int len)
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

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void swap(t_deque *q, int len)
{
	int tmp;

	if (max(q->rear - q->front, q->front - q->rear) >= 2)
	{
		tmp = q->value[(q->front + 1) % len];
		q->value[(q->front + 1) % len] = q->value[(q->front + 2) % len];
		q->value[(q->front + 2) % len] = tmp;
	}
}

void push(t_deque *src, t_deque *des, int len)
{
	int num;

	num = 5;
	num = pop_top(&src, len);
	push_rear(&des, num, len);
	push_rear(&src, num, len);
}



int	main(int argc, char *argv[])
{
	t_deque a;
	t_deque b;
	int i;

	i = 1;
	init_deque(argc, &a);
	init_deque(argc, &b);
	while (i < argc)
		push_rear(&a, ft_atoi(argv[i++]), argc);
	print_deque(&a);
	print_deque(&b);
	printf("#################\n");
	push(&a, &b, argc);
	print_deque(&a);
	print_deque(&b);
	printf("#################\n");
	free(a.value);
	free(b.value);
}
