/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/28 01:22:15 by ijeon            ###   ########.fr       */
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

int		get_type_num(t_deque *q, int len)
{
	int num[3];

	num[0] = get_deque(q, 0, len);
	num[1] = get_deque(q, 1, len);
	num[2] = get_deque(q, 2, len);
	if (num[0] < num[1] && num[1] < num[2] && num[0] < num[2])
		return (0); // 123
	else if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
		return (1); // 213
	else if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		return (2); // 132
	else if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
		return (3); // 312
	else if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
		return (4); // 231
	else
		return (5); // 321
}

void	three_num_sort(t_deque *a, t_deque *b, int len, int *command)
{
	int type;

	type = get_type_num(a, len);
	if (type == 1)
		swap(a, len, command);
	else if (type == 2 || type == 3)
	{
		if (type == 3)
			swap(a, len, command);
		push(b, a, len, command);
		swap(a, len, command);
		push(a, b, len, command);
	}
	else if (type == 4 || type == 5)
	{
		if (type == 5)
			swap(a, len, command);
		push(b, a, len, command);
		swap(a, len, command);
		push(a, b, len, command);
		swap(a, len, command);
	}
}

void	three_num_rev_sort(t_deque *a, t_deque *b, int len, int *command)
{
	int type;

	type = get_type_num(b, len);
	if (type == 4)
		swap(b, len, command);
	else if (type == 3 || type == 2)
	{
		if (type == 2)
			swap(b, len, command);
		push(a, b, len, command);
		swap(b, len, command);
		push(b, a, len, command);
	}
	else if (type == 1 || type == 0)
	{
		if (type == 0)
			swap(b, len, command);
		push(a, b, len, command);
		swap(b, len, command);
		push(b, a, len, command);
		swap(b, len, command);
	}
	push(a, b, len, command);
	push(a, b, len, command);
	push(a, b, len, command);
}

void	rev_ra_rb(t_deque *a, t_deque *b, int *cnt_command, int *command)
{
	int times;
	int cnt_ra;
	int cnt_rb;
	int len;

	len = a->length;
	cnt_ra = cnt_command[0];
	cnt_rb = cnt_command[1];
	times = min(cnt_ra, cnt_rb);
	while (times--)
		rrr(a, b, len, command);
	times = cnt_ra - cnt_rb;
	if (times < 0)
		while (times++ < 0)
			rev_rotate(b, len, command);
	else if (times > 0)
		while (times-- > 0)
			rev_rotate(a, len, command);
}

void	a_to_b(t_deque *a, t_deque *b, int cnt, int *command)
{
	int cnt_command[3];		//{cnt_ra, cnt_rb, cnt_pb}
	int *pivot;
	int count;
	int len;

	len = a->length;
	cnt_command[0] = 0;
	cnt_command[1] = 0;
	cnt_command[2] = 0;
	if (cnt <= 1)
		return ;
	else if (cnt == 2)
	{
		if (get_deque(a, 0, len) > get_deque(a, 1, len))
			swap(a, len, command);
		return ;
	}
	else if (cnt == 3)
		return (three_num_sort(a, b, len, command));
	pivot = get_pivot(a, cnt, len);
	count = 0;
	while (get_deque(a, cnt - 1, len) > pivot[1] && ++count)
		cnt--;
	while (cnt--)
	{
		if (get_deque(a, 0, len) > pivot[1] && ++cnt_command[0])
			rotate(a, len, command);
		else if (++cnt_command[2])
		{
			push(b, a, len, command);
			if (get_deque(b, 0, len) > pivot[0] && ++cnt_command[1])
				rotate(b, len, command);
		}
	}
	free(pivot);
	rev_ra_rb(a, b, cnt_command, command);
	a_to_b(a, b, cnt_command[0] + count, command);
	b_to_a(a, b, cnt_command[1], command);
	b_to_a(a, b, cnt_command[2] - cnt_command[1], command);
}

void	b_to_a(t_deque *a, t_deque *b, int cnt, int *command)
{
	int cnt_command[3];		//{cnt_ra, cnt_rb, cnt_pa}
	int *pivot;
	int len;

	len = a->length;
	cnt_command[0] = 0;
	cnt_command[1] = 0;
	cnt_command[2] = 0;
	if (cnt <= 1)
	{
		if (cnt == 1)
			push(a, b, len, command);
		return ;
	}
	else if (cnt == 2)
	{
		if (get_deque(b, 0, len) < get_deque(b, 1, len))
			swap(b, len, command);
		push(a, b, len, command);
		push(a, b, len, command);
		return ;
	}
	else if (cnt == 3)
		return (three_num_rev_sort(a, b, len, command));
	pivot = get_pivot(b, cnt, len);
	while (cnt--)
	{
		if (get_deque(b, 0, len) < pivot[0] && ++cnt_command[1])
			rotate(b, len, command);
		else if (++cnt_command[2])
		{
			push(a, b, len, command);
			if (get_deque(a, 0, len) < pivot[1] && ++cnt_command[0])
				rotate(a, len, command);
		}
	}
	free(pivot);
	a_to_b(a, b, cnt_command[2] - cnt_command[0], command);
	rev_ra_rb(a, b, cnt_command, command);
	a_to_b(a, b, cnt_command[0], command);
	b_to_a(a, b, cnt_command[1], command);
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

void	print_command(int *command, int cur)
{
	char	*command_list[11];
	
	command_list[0] = "sa";
	command_list[1] = "sb";
	command_list[2] = "ss";
	command_list[3] = "pa";
	command_list[4] = "pb";
	command_list[5] = "ra";
	command_list[6] = "rb";
	command_list[7] = "rr";
	command_list[8] = "rra";
	command_list[9] = "rrb";
	command_list[10] = "rrr";
	if ((*command == 0 && cur == 1) || (*command == 1 && cur == 0))
		*command = 2;
	else if ((*command == 5 && cur == 6) || (*command == 6 && cur == 5))
		*command = 7;
	else if ((*command == 8 && cur == 9) || (*command == 9 && cur == 8))
		*command = 10;
	else if (*command != -1)
	{
		write(1, command_list[*command], ft_strlen(command_list[*command]));
		write(1, "\n", 1);
		*command = cur;
	}
	else
		*command = cur;
}

int		main(int argc, char *argv[])
{
	int		i;
	int		len;
	int		command;
	t_deque	a;
	t_deque	b;

	command = -1;
	len = get_argc(argc, argv) + 1;
	init_deque(len, &a, 'a');
	init_deque(len, &b, 'b');
	i = 1;
	while (i < argc)
		init_a(&a, i++, argv, len);
	check(&a, len);
	a_to_b(&a, &b, len - 1, &command);
	print_command(&command, -1);
	//print_deque(&a, &b, len);
	free(a.value);
	free(b.value);
}
