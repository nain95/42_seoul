/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:51:37 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/25 23:02:21 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void checker(const char *str)
{
	char *s;

	s = (char *)str;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if ( *s < '0' || '9' < *s)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		s++;
	}

}

int	ft_atoi(const char *str)
{
	unsigned int		tmp;
	int					answer;
	int					flag;
	char				*s;

	flag = 1;
	tmp = 0;
	checker(str);
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
