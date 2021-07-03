/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:00:03 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/03 16:11:38 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker(t_deque *a, t_deque *b, const char *str)
{
	char *s;

	s = (char *)str;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || '9' < *s)
		{
			write(2, "Error\n", 6);
			free(a->value);
			free(b->value);
			exit(1);
		}
		s++;
	}
}

long long	ft_atoi(t_deque *a, t_deque *b, const char *str)
{
	long long			tmp;
	long long			answer;
	int					flag;
	char				*s;

	flag = 1;
	tmp = 0;
	checker(a, b, str);
	s = (char *)str;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			flag *= -1;
		s++;
	}
	while ('0' <= *s && *s <= '9')
	{
		tmp *= 10;
		tmp += *s++ - '0';
	}
	answer = tmp * flag;
	return (answer);
}

void		print_error(t_deque *a, t_deque *b)
{
	write(2, "Error\n", 6);
	free(a->value);
	free(b->value);
	exit(1);
}
