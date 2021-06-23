/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/23 22:59:15 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void a_to_b(t_deque *a, t_deque *b, int cnt, int len)
{
	int cnt_ra;
	int cnt_pb;
	int tmp;
	int pivot;
//	int num[3];
	int max_n;
	int min_n;

	tmp = 1;
	pivot = -1;
	max_n = 0;
	min_n = -1;
	while (tmp++ <= cnt+1)
	{
		if (max_n < a->value[(a->front + tmp) % len])
			max_n = a->value[(a->front + tmp) % len];
		if (min_n != -1 && min_n > a->value[(a->front + tmp)])
			min_n = a->value[(a->front + tmp) % len];
	}
	tmp = 1;
	while (pivot == -1 || min_n == pivot || max_n == pivot)
	{
		pivot = a->value[(a->front + tmp++) % len];
		if (tmp == cnt)
			break;
	}
	//pivot /= max(1, cnt);
	
	printf("%d %d\n\n",cnt, pivot);
	cnt_ra = 0;
	cnt_pb = 0;
	if (cnt <= 1)
		return;

	else if (cnt == 2)
	{
		if (a->value[(a->front + 1) % len] > a->value[(a->front + 2) % len])
		{
			swap(a, len);
			printf("sa\n");
		}
		return ;
	}
	/*
	else if (cnt == 3)
	{
		printf("123\n");
		num[0] = a->value[(a->front + 1) % len];
		num[1] = a->value[(a->front + 2) % len];
		num[2] = a->value[(a->front + 3) % len];
		if (num[0] > num[1] && num[1] > num[2])
		{
			swap(a, len);
			rotate(a, len);
			rotate(a, len);
			push(b, a, len);
			rev_rotate(a, len);
			rev_rotate(a, len);
			push(a, b, len);
			printf("pb\npb\npb\npa\npa\npa\n");
		}
		else if (num[0] < num[1] && num[1] > num[2])
		{
			if (num[0] < num[2])
			{
				push(b, a, len);
				swap(a, len);
				push(a, b, len);
			}
			else
			{
				push(b, a, len);
				swap(a, len);
				push(a, b, len);
				swap(a, len);
			}
		}
		else if (num[0] > num[1] && num[1] < num[2])
			swap(a, len);
		return;
	}*/

	while (cnt--)
	{
		if (a->value[(a->front + 1) % len] > pivot && ++cnt_ra)
		{
			rotate(a, len);
			printf("ra\n");
		}
		else if(++cnt_pb)
		{
			push(b, a, len);
			printf("pb\n");
		}
	}
	tmp = cnt_ra;
	while(tmp--)
	{
		rev_rotate(a, len);
		printf("rra\n");
	}
	print_deque(a, b, len);
	//printf("11111111111111111111\n");
	a_to_b(a, b, cnt_ra, len);
	b_to_a(a, b, cnt_pb, len);
}

void b_to_a(t_deque *a, t_deque *b, int cnt, int len)
{
	int cnt_rb;
	int cnt_pa;
	int tmp;
	int pivot;
	int max_n;
	int min_n;

	tmp = 1;
	max_n = 0;
	min_n = -1;
	pivot = -1;
	while (tmp++ <= cnt+1)
	{
		if (max_n < b->value[(b->front + tmp) % len])
			max_n = b->value[(b->front + tmp) % len];
		if (min_n != -1 && min_n > b->value[(b->front + tmp)])
			min_n = b->value[(b->front + tmp) % len];
	}
	tmp = 1;
	while (pivot == -1 || min_n == pivot || max_n == pivot)
	{
		pivot = b->value[(b->front + tmp++) % len];
		if (tmp == cnt)
			break;
	}
	tmp = 1;
	/*pivot = 0;
	while (tmp++ <= cnt+1)
	{
		pivot += b->value[(b->front+tmp) % len];
	}
	//pivot /= max(1, cnt);
	pivot = b->value[(b->front + 1 + (cnt / 2)) % len];
	*/
	cnt_rb = 0;
	cnt_pa = 0;
	if (cnt <= 1)
	{
		push(a, b, len);
		printf("pa\n");
		return;
	}
	while (cnt--)
	{
		if (b->value[(b->front + 1) % len] < pivot && ++cnt_rb)
		{
			rotate(b, len);
			printf("rb\n");
		}
		else if(++cnt_pa)
		{
			push(a, b, len);
			printf("pa\n");
		}
	}
	tmp = cnt_rb;
	while (tmp--)
	{
		rev_rotate(b, len);
		printf("rrb\n");
	}
	print_deque(a, b, len);
	//printf("2222222222222222222\n");
	a_to_b(a, b, cnt_pa, len);
	b_to_a(a, b, cnt_rb, len);
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

int	main(int argc, char *argv[])
{
	t_deque a;
	t_deque b;
	int i;
	int num;
	int pivot;
//	int n;

	pivot = 0;
	i = 1;
	init_deque(argc, &a);
	init_deque(argc, &b);
	while (i < argc)
	{
		num = ft_atoi(argv[i++]);
		pivot += num;
		push_rear(&a, num, argc);
	}
	print_deque(&a, &b, argc);
	/*
	while (1)
	{
		scanf("%d", &n);
		if (n == 1)
			a_to_b(&a, &b, argc - 1, argc);	
		else
			b_to_a(&a, &b, argc - 1, argc);
	}
	*/
	a_to_b(&a, &b, argc - 1, argc);	
	
	//push(&b,&a,argc);
	//push(&b,&a,argc);
	//rotate(&b,argc);
	//rev_rotate(&b,argc);
	//printf("%d",b.value[b.front+1]);
	print_deque(&a, &b, argc);
	free(a.value);
	free(b.value);
}
