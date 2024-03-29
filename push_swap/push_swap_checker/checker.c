/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:25:50 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/03 16:06:39 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	sort_check(t_deque *q)
{
	int idx;
	int cnt;
	int len;

	cnt = 0;
	idx = q->front + 1;
	len = q->length;
	if (len != 1)
	{
		while (cnt++ < len - 2)
		{
			if (q->value[idx % len] >= q->value[(idx + 1) % len])
			{
				write(1, "KO\n", 3);
				return ;
			}
			idx++;
		}
	}
	write(1, "OK\n", 3);
}

int		exec(t_deque *a, t_deque *b, char *command)
{
	int tmp;

	tmp = -1;
	if (ft_strcmp(command, "sa") == 0)
		swap(a, &tmp);
	else if (ft_strcmp(command, "sb") == 0)
		swap(b, &tmp);
	else if (ft_strcmp(command, "ss") == 0)
	{
		swap(a, &tmp);
		swap(b, &tmp);
	}
	else if (ft_strcmp(command, "pa") == 0)
		push(a, b, &tmp);
	else if (ft_strcmp(command, "pb") == 0)
		push(b, a, &tmp);
	else if (ft_strcmp(command, "ra") == 0)
		rotate(a, &tmp);
	else if (ft_strcmp(command, "rb") == 0)
		rotate(b, &tmp);
	else
		return (exec2(a, b, command));
	return (1);
}

int		exec2(t_deque *a, t_deque *b, char *command)
{
	int tmp;

	tmp = -1;
	if (ft_strcmp(command, "rr") == 0)
	{
		rotate(a, &tmp);
		rotate(b, &tmp);
	}
	else if (ft_strcmp(command, "rra") == 0)
		rev_rotate(a, &tmp);
	else if (ft_strcmp(command, "rrb") == 0)
		rev_rotate(b, &tmp);
	else if (ft_strcmp(command, "rrr") == 0)
	{
		rev_rotate(a, &tmp);
		rev_rotate(b, &tmp);
	}
	else
	{
		write(2, "Error\n", 6);
		free(a->value);
		free(b->value);
		return (-1);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		len;
	char	*command;
	t_deque a;
	t_deque b;

	if (argc == 1)
		return (1);
	len = get_argc(argc, argv) + 1;
	init_deque(len, &a, 'a');
	init_deque(len, &b, 'b');
	i = 1;
	while (i < argc)
		if (init_a(&a, &b, i++, argv) == -1)
			print_error(&a, &b);
	if (check(&a, len) == 1)
	{
		while (get_next_line(0, &command) >= 1)
			if (exec(&a, &b, command) == -1)
				return (0);
		sort_check(&a);
	}
	free(a.value);
	free(b.value);
}
