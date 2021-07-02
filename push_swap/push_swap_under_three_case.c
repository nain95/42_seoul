/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under_three_case.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:22:26 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/02 17:44:24 by ijeon            ###   ########.fr       */
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
		return (123);
	else if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
		return (213);
	else if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		return (132);
	else if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
		return (312);
	else if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
		return (231);
	else
		return (321);
}

void	three_num_sort(t_deque *a, t_deque *b, int *command, int type)
{
	if (type == 213)
		swap(a, command);
	else if (type == 132 || type == 312)
	{
		if (type == 312 && deque_len(a) == 3)
			return (rotate(a, command));
		if (type == 312)
			swap(a, command);
		push(b, a, command);
		swap(a, command);
		push(a, b, command);
	}
	else if (type == 231 || type == 321)
	{
		if (type == 321)
			swap(a, command);
		if (deque_len(a) == 3)
			return (rev_rotate(a, command));
		push(b, a, command);
		swap(a, command);
		push(a, b, command);
		swap(a, command);
	}
}

void	three_num_rev_sort(t_deque *a, t_deque *b, int *command, int type)
{
	if (type == 231)
		swap(b, command);
	else if (type == 312 || type == 132)
	{
		if (type == 132 && deque_len(b) == 3)
			return (rotate(b, command));
		if (type == 132)
			swap(b, command);
		push(a, b, command);
		swap(b, command);
		push(b, a, command);
	}
	else if (type == 213 || type == 123)
	{
		if (type == 123)
			swap(b, command);
		if (deque_len(b) == 3)
			return (rev_rotate(b, command));
		push(a, b, command);
		swap(b, command);
		push(b, a, command);
		swap(b, command);
	}
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
		return (three_num_sort(a, b, command, get_type_num(a)));
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
	{
		three_num_rev_sort(a, b, command, get_type_num(b));
		push(a, b, command);
		push(a, b, command);
		push(a, b, command);
		return ;
	}
}
