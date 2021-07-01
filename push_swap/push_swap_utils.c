/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:21:19 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/01 17:39:54 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(int len, t_deque *q, char c)
{
	while ((q->value = (int *)malloc(sizeof(int) * len)) == NULL)
		continue;
	q->front = 0;
	q->rear = 0;
	q->name = c;
	q->length = len;
	q->command_list[0] = "sa";
	q->command_list[1] = "sb";
	q->command_list[2] = "ss";
	q->command_list[3] = "pa";
	q->command_list[4] = "pb";
	q->command_list[5] = "ra";
	q->command_list[6] = "rb";
	q->command_list[7] = "rr";
	q->command_list[8] = "rra";
	q->command_list[9] = "rrb";
	q->command_list[10] = "rrr";
}

int		is_empty(t_deque *q)
{
	if (q->front == q->rear)
		return (1);
	else
		return (0);
}

int		is_full(t_deque *q)
{
	if (is_empty(q))
		return (0);
	else if (q->front == (q->rear + 1) % q->length)
		return (1);
	else
		return (0);
}

int		get_deque(t_deque *q, int idx)
{
	return (q->value[(q->front + idx + 1) % q->length]);
}

void	print_command(t_deque *q, int *command, int cur)
{
	if ((*command == 0 && cur == 1) || (*command == 1 && cur == 0))
		*command = 2;
	else if ((*command == 5 && cur == 6) || (*command == 6 && cur == 5))
		*command = 7;
	else if ((*command == 8 && cur == 9) || (*command == 9 && cur == 8))
		*command = 10;
	else if (*command != -1)
	{
		write(1, q->command_list[*command],\
				ft_strlen(q->command_list[*command]));
		write(1, "\n", 1);
		*command = cur;
	}
	else
		*command = cur;
}
