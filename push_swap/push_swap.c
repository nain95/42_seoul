/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/17 17:25:30 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void init_deque(int len, t_deque *q)
{
	while ((q->value = (int *)malloc(sizeof(int) * len)) == NULL)
		continue;
	q->front = 0;
	q->rear = 0;
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
			q->front = (q->front - 1);
	}
}

int pop_rear(t_deque *q)
{
	int data;

	if (!is_empty(q))
	{
		data = q->value[q->rear];
		q->rear = max(0, q->rear-1);
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
		q->front = (q->front+1) % len;
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

void print_deque(t_deque *a, t_deque *b, int len)
{
	int cnt_a;
	int cnt_b;
	int tmp_a;
	int tmp_b;
	int tmp;

	tmp_a = deque_len(a, len);
	tmp_b = deque_len(b, len);
	tmp = (tmp_a - tmp_b);

	cnt_a = a->front;
	cnt_b = b->front;
	printf("|==== a ====== b ====|\n");
	while (tmp_a > 0 || tmp_b > 0)
	{
		if (tmp > 0)
		{
			tmp--;
			printf("|    %3d             |\n", a->value[(++cnt_a) % len]);
			tmp_a--;
		}
		else if (tmp < 0)
		{
			tmp++;
			tmp_b--;
			printf("|             %3d    |\n", b->value[(++cnt_b) % len]);
		}
		else
		{
			printf("|    %3d      %3d    |\n", a->value[(++cnt_a) % len], b->value[(++cnt_b) % len]);
			tmp_a--;
			tmp_b--;
		}
	}
	printf("|====================|\n");
}

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
		num = pop_rear(q);
		push_top(q, num, len);
	}
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
	print_deque(&a, &b, argc);
	
	free(a.value);
	free(b.value);
}
