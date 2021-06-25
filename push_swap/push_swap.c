/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/26 02:03:52 by ijeon            ###   ########.fr       */
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

void	a_to_b(t_deque *a, t_deque *b, int cnt, int len, int *command)
{
	int cnt_ra;
	int cnt_pb;
	int cnt_rb;
	int tmp;
	int *pivot;
	int num[3];
	int count;

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
	count = 0;
	while (get_deque(a, cnt - 1, len) > pivot[1] && ++count)
		cnt--;
	while (cnt--)
	{
		if (get_deque(a, 0, len) > pivot[1] && ++cnt_ra)
			rotate(a, len);
		else if (++cnt_pb)
		{
			push(b, a, len);
			if (get_deque(b, 0, len) > pivot[0] && ++cnt_rb)
				rotate(b, len);
		}
	}
	free(pivot);
	tmp = min(cnt_ra, cnt_rb);
	while (tmp--)
		rrr(a, b, len);
	tmp = cnt_ra - cnt_rb;
	while (tmp++ < 0)
		rev_rotate(b, len);
	tmp = cnt_ra - cnt_rb;
	while (tmp-- > 0)
		rev_rotate(a, len);
	a_to_b(a, b, cnt_ra + count, len, command);
	b_to_a(a, b, cnt_rb, len, command);
	b_to_a(a, b, cnt_pb - cnt_rb, len, command);
}

void	b_to_a(t_deque *a, t_deque *b, int cnt, int len, int *command)
{
	int cnt_rb;
	int cnt_pa;
	int cnt_ra;
	int tmp;
	int *pivot;
	int num[3];
	int count;

	cnt_rb = 0;
	cnt_pa = 0;
	cnt_ra = 0;
	if (cnt <= 1)
	{
		if (cnt == 1)
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
		if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
			swap(b, len);
		else if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
		{
			push(a, b, len);
			swap(b, len);
			push(b, a, len);
		}
		else if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		{
			swap(b, len);
			push(a, b, len);
			swap(b, len);
			push(b, a, len);
		}
		else if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
		{
			push(a, b, len);
			swap(b, len);
			push(b, a, len);
			swap(b, len);
		}
		else if (num[0] < num[1] && num[1] < num[2] && num[0] < num[2])
		{
			swap(b, len);
			push(a, b, len);
			swap(b, len);
			push(b, a, len);
			swap(b, len);
		}
		push(a, b, len);
		push(a, b, len);
		push(a, b, len);
		return ;
	}
	pivot = get_pivot(b, cnt, len);
	count = 0;
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
	free(pivot);
	a_to_b(a, b, cnt_pa - cnt_ra, len, command);
	tmp = min(cnt_ra, cnt_rb);
	while (tmp--)
		rrr(a, b, len);
	tmp = cnt_ra - cnt_rb;
	while (tmp++ < 0)
		rev_rotate(b, len);
	tmp = cnt_ra - cnt_rb;
	while (tmp-- > 0)
		rev_rotate(a, len);
	a_to_b(a, b, cnt_ra, len, command);
	b_to_a(a, b, cnt_rb + count, len, command);
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

void	init_a(t_deque *q, int idx, char **argv, int len)
{
	char	**tmp;
	char	**split_data;
	int		num;

	split_data = ft_split(argv[idx], ' ');
	tmp = split_data;
	while (*split_data)
	{
		num = ft_atoi(*split_data);
		push_rear(q, num, len);
		free(*split_data);
		split_data++;
	}
	free(tmp);
}

int		get_argc(int argc, char **argv)
{
	int		idx;
	int		count;
	char	*c;

	idx = 1;
	count = 0;
	while (idx < argc)
	{
		count++;
		c = argv[idx];
		while (*c)
		{
			if (*c == ' ')
				count++;
			c++;
		}
		idx++;
	}
	return (count);
}

void	check(t_deque *a, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len - 2)
	{
		j = i + 1;
		while (j < len - 1)
		{
			if (get_deque(a, i, len) == get_deque(a, j, len))
				exit(1);
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		len;
	int		command;
	t_deque	a;
	t_deque	b;

	command = -1;
	i = 1;
	len = get_argc(argc, argv) + 1;
	init_deque(len, &a, 'a');
	init_deque(len, &b, 'b');
	while (i < argc)
		init_a(&a, i++, argv, len);
	check(&a, len);
	//print_deque(&a, &b, len);
	a_to_b(&a, &b, len-1, len, &command);
	//print_deque(&a, &b, len);
	free(a.value);
	free(b.value);
}
