/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:00:27 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/28 01:16:45 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_deque *q, int len, int *command)
{
    int tmp;

    if (deque_len(q, len) >= 2)
    {
        tmp = q->value[(q->front + 1) % len];
        q->value[(q->front + 1) % len] = q->value[(q->front + 2) % len];
        q->value[(q->front + 2) % len] = tmp;
		if (q->name == 'a')
			print_command(command, 0);
		else	
			print_command(command, 1);
		/*write(1, "#s", 2);
		write(1, &q->name, 1);
		write(1, "\n", 1);*/
    }
}

void push(t_deque *des, t_deque *src, int len, int *command)
{
    int num;

    if (deque_len(src, len) > 0)
    {
        num = pop_top(src, len);
        push_top(des, num, len);
		if (des->name == 'a')
			print_command(command, 3);
		else	
			print_command(command, 4);
		/*write(1, "#p", 2);
		write(1, &des->name, 1);
		write(1, "\n", 1);*/
    }
}

void rotate(t_deque *q, int len, int *command)
{
    int num;

    if (deque_len(q, len) > 1)
    {
        num = pop_top(q, len);
        push_rear(q, num, len);
		if (q->name == 'a')
			print_command(command, 5);
		else	
			print_command(command, 6);
		/*write(1, "#r", 2);
		write(1, &q->name, 1);
		write(1, "\n", 1);*/
    }
}


void rev_rotate(t_deque *q, int len, int *command)
{
    int num;

    if (deque_len(q, len) > 1)
    {
        num = pop_rear(q, len);
        push_top(q, num, len);
		if (q->name == 'a')
			print_command(command, 8);
		else	
			print_command(command, 9);
		/*write(1, "#rr", 4);
		write(1, &q->name, 1);
		write(1, "\n", 1);*/
	}
}

void rrr(t_deque *a, t_deque *b, int len, int *command)
{
	int num;

    if (deque_len(a, len) > 1)
    {
        num = pop_rear(a, len);
        push_top(a, num, len);
	}
    if (deque_len(b, len) > 1)
    {
        num = pop_rear(b, len);
        push_top(b, num, len);
	}
	print_command(command, 10);
	//write(1, "#rrr\n", 5);
}

