/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:02:25 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/03 00:02:43 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *src)
{
	int count;
	char *s;

	count = 0;
	s = src;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

int		check(char c, char *base)
{	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		init(char **s)
{
	int flag;

	flag = 1;
	while (**s == ' ' || **s == '\t' || **s == '\n' ||\
			**s == '\v' || **s == '\r' || **s == '\f')
		(*s)++;
	while (**s == '+' || **s == '-')
	{
		if (**s == '-')
			flag *= -1;
		(*s)++;
	}
	return (flag);
}

int		ft_atoi_base(char *str, char *base)
{
	int	flag;
	int	num;
	int	i;
	int	answer;
	char	*s;

	num = 1;
	answer = 0;
	s = str;
	flag = init(&s);
	i = 0;
	while (check(s[i], base) != -1)
		i++;
	i -= 1;
	while(i >= 0)
	{
		answer += check(s[i], base) * num;
		num *= ft_strlen(base);
		i--;
	}
	return (answer * flag);
}

int main()
{
	printf("%d",ft_atoi_base("---+-+ab12cabq567", "0123456789abcdef"));
}
