/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 23:14:09 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/01 13:27:25 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		check(t_deque *a, int len)
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
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

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
			ft_swap(&arr[l], &arr[r]);
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
