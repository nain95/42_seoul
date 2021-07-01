/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under_three_case.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:22:26 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/01 17:30:34 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_type_num(t_deque *q)
{
	int num[3];

	num[0] = get_deque(q, 0);
	num[1] = get_deque(q, 1);
	num[2] = get_deque(q, 2);
	if (num[0] < num[1] && num[1] < num[2] && num[0] < num[2])
		return (0);
	else if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
		return (1);
	else if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		return (2);
	else if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
		return (3);
	else if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
		return (4);
	else
		return (5);
}

void	three_num_sort(t_deque *a, t_deque *b, int *command)
{
	int type;

	type = get_type_num(a);
	if (type == 1)
		swap(a, command);
	else if (type == 2 || type == 3)
	{
		if (type == 3)
			swap(a, command);
		push(b, a, command);
		swap(a, command);
		push(a, b, command);
	}
	else if (type == 4 || type == 5)
	{
		if (type == 5)
			swap(a, command);
		push(b, a, command);
		swap(a, command);
		push(a, b, command);
		swap(a, command);
	}
}

void	three_num_rev_sort(t_deque *a, t_deque *b, int *command)
{
	int type;

	type = get_type_num(b);
	if (type == 4)
		swap(b, command);
	else if (type == 3 || type == 2)
	{
		if (type == 2)
			swap(b, command);
		push(a, b, command);
		swap(b, command);
		push(b, a, command);
	}
	else if (type == 1 || type == 0)
	{
		if (type == 0)
			swap(b, command);
		push(a, b, command);
		swap(b, command);
		push(b, a, command);
		swap(b, command);
	}
	push(a, b, command);
	push(a, b, command);
	push(a, b, command);
}

void	under_three_a_to_b(t_deque *a, t_deque *b, int cnt, int *command)
{
	if (cnt <= 1)
		return ;
	else if (cnt == 2)
	{
		if (get_deque(a, 0) > get_deque(a, 1))
			swap(a, command);
		return ;
	}
	else if (cnt == 3)
		return (three_num_sort(a, b, command));
}

void	under_three_b_to_a(t_deque *a, t_deque *b, int cnt, int *command)
{
	if (cnt <= 1)
	{
		if (cnt == 1)
			push(a, b, command);
		return ;
	}
	else if (cnt == 2)
	{
		if (get_deque(b, 0) < get_deque(b, 1))
			swap(b, command);
		push(a, b, command);
		push(a, b, command);
		return ;
	}
	else if (cnt == 3)
		return (three_num_rev_sort(a, b, command));
}
