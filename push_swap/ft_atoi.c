/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:51:37 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/01 22:11:40 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker(const char *str)
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
			return (-1);
		}
		s++;
	}
	return (1);
}

long long	ft_atoi(t_deque *a, t_deque *b, const char *str)
{
	long long			tmp;
	long long			answer;
	int					flag;
	char				*s;

	flag = 1;
	tmp = 0;
	if (checker(str) == -1)
	{
		free(a);
		free(b);
		exit(1);
	}
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
