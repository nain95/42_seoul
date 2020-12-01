/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:51:37 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/01 21:08:50 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int		answer;
	int		flag;
	char	*s;

	flag = 1;
	answer = 0;
	s = str;
	while (*s == ' ')
		s++;
	if (*s != '+' && *s != '-')
		return (answer);
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			flag *= -1;
		s++;
	}
	while ('0' <= *s && *s <= '9')
	{
		answer *= 10;
		answer += *s++ - '0';
	}
	return (answer * flag);
}

int main()
{
	char c[] = " ---+--+1234ab567";
	printf("%d",ft_atoi(c));
}
