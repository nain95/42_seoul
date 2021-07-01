/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 23:14:09 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/01 19:41:34 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		init_a(t_deque *q, int idx, char **argv)
{
	char		**tmp;
	char		**split_data;
	long long	tmp_num;
	int			num;

	split_data = ft_split(argv[idx], ' ');
	tmp = split_data;
	while (*split_data)
	{
		tmp_num = ft_atoi(*split_data);
		if (tmp_num < -2147483648 || tmp_num > 2147483647)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		num = tmp_num;
		push_rear(q, num);
		free(*split_data);
		split_data++;
	}
	free(tmp);
	return (1);
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
		if (*c == '\0')
			count--;
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

int		check(t_deque *a)
{
	int i;
	int j;

	if (a->length == 1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	i = 0;
	while (i < a->length - 2)
	{
		j = i + 1;
		while (j < a->length - 1)
		{
			if (get_deque(a, i) == get_deque(a, j))
			{
				write(2, "Error\n", 6);
				return (-1);
			}
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

int		*get_pivot(t_deque *q, int cnt)
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
		num_list[idx] = get_deque(q, idx);
		idx++;
	}
	quicksort(num_list, 0, cnt - 1);
	pivot[0] = num_list[cnt / 3];
	pivot[1] = num_list[cnt / 3 * 2];
	free(num_list);
	return (pivot);
}
