/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 23:14:09 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/02 00:39:33 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		init_a(t_deque *a, t_deque *b, int idx, char **argv)
{
	char		**tmp;
	char		**split_data;
	long long	tmp_num;
	int			num;

	split_data = ft_split(argv[idx], ' ');
	tmp = split_data;
	while (*split_data)
	{
		tmp_num = ft_atoi(a, b, *split_data);
		if (tmp_num < -2147483648 || tmp_num > 2147483647)
		{
			free(*split_data);
			free(tmp);
			return (-1);
		}
		num = tmp_num;
		push_rear(a, num);
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
	int		tmp;
	char	*c;

	idx = 1;
	count = 0;
	while (idx < argc)
	{
		tmp = 0;
		c = argv[idx++];
		while (*c)
		{
			while (*c == ' ')
				c++;
			if (*c)
				tmp++;
			while (*c != ' ' && *c != '\0')
				c++;
		}
		if (tmp == 0)
			return (-1);
		count += tmp;
	}
	return (count);
}

int		check(t_deque *a)
{
	int i;
	int j;

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
