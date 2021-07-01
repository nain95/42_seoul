/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:56:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/01 22:13:40 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		rrr(a, b, command);
	times = cnt_ra - cnt_rb;
	if (times < 0)
		while (times++ < 0)
			rev_rotate(b, command);
	else if (times > 0)
		while (times-- > 0)
			rev_rotate(a, command);
}

void	a_to_b(t_deque *a, t_deque *b, int cnt, int *command)
{
	int cnt_command[3];
	int *pivot;

	cnt_command[0] = 0;
	cnt_command[1] = 0;
	cnt_command[2] = 0;
	if (cnt <= 3)
		return (under_three_a_to_b(a, b, cnt, command));
	pivot = get_pivot(a, cnt);
	while (cnt--)
	{
		if (get_deque(a, 0) > pivot[1] && ++cnt_command[0])
			rotate(a, command);
		else if (++cnt_command[2])
		{
			push(b, a, command);
			if (get_deque(b, 0) > pivot[0] && ++cnt_command[1])
				rotate(b, command);
		}
	}
	free(pivot);
	rev_ra_rb(a, b, cnt_command, command);
	a_to_b(a, b, cnt_command[0], command);
	b_to_a(a, b, cnt_command[1], command);
	b_to_a(a, b, cnt_command[2] - cnt_command[1], command);
}

void	b_to_a(t_deque *a, t_deque *b, int cnt, int *command)
{
	int	cnt_command[3];
	int *pivot;

	cnt_command[0] = 0;
	cnt_command[1] = 0;
	cnt_command[2] = 0;
	if (cnt <= 3)
		return (under_three_b_to_a(a, b, cnt, command));
	pivot = get_pivot(b, cnt);
	while (cnt--)
	{
		if (get_deque(b, 0) < pivot[0] && ++cnt_command[1])
			rotate(b, command);
		else if (++cnt_command[2])
		{
			push(a, b, command);
			if (get_deque(a, 0) < pivot[1] && ++cnt_command[0])
				rotate(a, command);
		}
	}
	free(pivot);
	a_to_b(a, b, cnt_command[2] - cnt_command[0], command);
	rev_ra_rb(a, b, cnt_command, command);
	a_to_b(a, b, cnt_command[0], command);
	b_to_a(a, b, cnt_command[1], command);
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
		if (init_a(&a, &b, i++, argv) == -1)
		{
			free(a.value);
			free(b.value);
			exit(1);
		}
	if (check(&a) != -1)
	{
		a_to_b(&a, &b, len - 1, &command);
		print_command(&a, &command, -1);
	}
	free(a.value);
	free(b.value);
}
