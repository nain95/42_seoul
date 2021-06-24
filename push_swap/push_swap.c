/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/24 23:56:27 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(int *arr, int left, int right)
{
	int l;
	int r;
	int pivot;

	l = left;
	r = right;
	pivot = arr[(l + r) / 2];
	while (l <= r)
	{
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;
		if (l < r)
			swap_num(&arr[l], &arr[r]);
		else if (l == r)
		{
			l++;
			r--;
		}
	}
	if (left < r)
		quicksort(arr, left, r);
	if (l < right)
		quicksort(arr, l, right);
}

int		*get_pivot(t_deque *q, int cnt, int len)
{
	int *pivot;
	int *num_list;
	int idx;

	if (!(num_list = (int *)malloc(sizeof(int) * cnt)))
		return (NULL);
	if (!(pivot = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	idx = 0;
	while (idx < cnt)
	{
		num_list[idx] = get_deque(q, idx, len);
		idx++;
	}
	quicksort(num_list, 0, cnt - 1);
	pivot[0] = num_list[cnt / 3];
	pivot[1] = num_list[cnt / 3 * 2];
	free(num_list);
	return (pivot);
}

void	a_to_b(t_deque *a, t_deque *b, int cnt, int len)
{
	int cnt_ra;
	int cnt_pb;
	int cnt_rb;
	int tmp;
	int *pivot;
	int num[3];

	cnt_ra = 0;
	cnt_pb = 0;
	cnt_rb = 0;
	if (cnt <= 1)
		return ;
	else if (cnt == 2)
	{
		if (get_deque(a, 0, len) > get_deque(a, 1, len))
			swap(a, len);
		return ;
	}
	else if (cnt == 3)
	{
		num[0] = get_deque(a, 0, len);
		num[1] = get_deque(a, 1, len);
		num[2] = get_deque(a, 2, len);
		if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
			swap(a, len);
		else if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		{
			push(b, a, len);
			swap(a, len);
			push(a, b, len);
		}
		else if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
		{
			swap(a, len);
			push(b, a, len);
			swap(a, len);
			push(a, b, len);
		}
		else if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
		{
			push(b, a, len);
			swap(a, len);
			push(a, b, len);
			swap(a, len);
		}
		else if (num[0] > num[1] && num[1] > num[2] && num[0] > num[2])
		{
			swap(a, len);
			push(b, a, len);
			swap(a, len);
			push(a, b, len);
			swap(a, len);
		}
		return ;
	}
	pivot = get_pivot(a, cnt, len);
	while (cnt--)
	{
		if (get_deque(a, 0, len)> pivot[1] && ++cnt_ra)
			rotate(a, len);
		else if (++cnt_pb)
		{
			push(b, a, len);
			if (get_deque(b, 0, len) > pivot[0] && ++cnt_rb)
				rotate(b, len);
		}
	}
	tmp = min(cnt_ra, cnt_rb);
	while (tmp--)
		rrr(a, b, len);
	tmp = cnt_ra - cnt_rb;
	while (tmp++ < 0)
		rev_rotate(b, len);
	tmp = cnt_ra - cnt_rb;
	while (tmp-- > 0)
		rev_rotate(a, len);
	a_to_b(a, b, cnt_ra, len);
	b_to_a(a, b, cnt_rb, len);
	b_to_a(a, b, cnt_pb - cnt_rb, len);
}

void	b_to_a(t_deque *a, t_deque *b, int cnt, int len)
{
	int cnt_rb;
	int cnt_pa;
	int cnt_ra;
	int tmp;
	int *pivot;
	int num[3];

	cnt_rb = 0;
	cnt_pa = 0;
	cnt_ra = 0;
	if (cnt == 0)
		return ;
	else if (cnt == 1)
	{
		push(a, b, len);
		return ;
	}
	else if (cnt == 2)
	{
		if (get_deque(b, 0, len) < get_deque(b, 1, len))
			swap(b, len);
		push(a, b, len);
		push(a, b, len);
		return ;
	}
	else if (cnt == 3)
	{
		num[0] = get_deque(b, 0, len);
		num[1] = get_deque(b, 1, len);
		num[2] = get_deque(b, 2, len);
		if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
			swap(b, len);
		else if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		{
			push(a, b, len);
			swap(b, len);
			push(b, a, len);
		}
		else if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
		{
			swap(b, len);
			push(a, b, len);
			swap(b, len);
			push(b, a, len);
		}
		else if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
		{
			push(a, b, len);
			swap(b, len);
			push(b, a, len);
			swap(b, len);
		}
		else if (num[0] > num[1] && num[1] > num[2] && num[0] > num[2])
		{
			swap(b, len);
			push(a, b, len);
			swap(b, len);
			push(b, a, len);
			swap(b, len);
		}
		rotate(b, len);
		rotate(b, len);
		push(a, b, len);
		rev_rotate(b, len);
		push(a, b, len);
		rev_rotate(b, len);
		push(a, b, len);
		return ;
	}
	pivot = get_pivot(b, cnt, len);
	while (cnt--)
	{
		if (get_deque(b, 0, len) < pivot[0] && ++cnt_rb)
			rotate(b, len);
		else if (++cnt_pa)
		{
			push(a, b, len);
			if (get_deque(a, 0, len) < pivot[1] && ++cnt_ra)
				rotate(a, len);
		}
	}
	a_to_b(a, b, cnt_pa - cnt_ra, len);
	tmp = min(cnt_ra, cnt_rb);
	while (tmp--)
		rrr(a, b, len);
	tmp = cnt_ra - cnt_rb;
	while (tmp++ < 0)
		rev_rotate(b, len);
	tmp = cnt_ra - cnt_rb;
	while (tmp-- > 0)
		rev_rotate(a, len);
	a_to_b(a, b, cnt_ra, len);
	b_to_a(a, b, cnt_rb, len);
}

void	print_deque(t_deque *a, t_deque *b, int len)
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

int		main(int argc, char *argv[])
{
	int		i;
	int		num;
	int		pivot;
	t_deque	a;
	t_deque	b;

	pivot = 0;
	i = 1;
	init_deque(argc, &a, 'a');
	init_deque(argc, &b, 'b');
	while (i < argc)
	{
		num = ft_atoi(argv[i++]);
		pivot += num;
		push_rear(&a, num, argc);
	}
	//print_deque(&a, &b, argc);
	a_to_b(&a, &b, argc - 1, argc);
	//print_deque(&a, &b, argc);
	free(a.value);
	free(b.value);
}
