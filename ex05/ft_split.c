/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:36:28 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/10 11:20:26 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				check(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int				malloc_size(char *str, char *charset)
{
	int	cnt;
	int flag;

	flag = 1;
	while (check(*str, charset) == 1)
		str++;
	cnt = 1;
	while (*str)
	{
		if (check(*str++, charset) == 1)
		{
			flag = 1;
			while (*str && check(*str, charset) == 1)
				str++;
		}
		else if (flag == 1)
		{
			cnt++;
			flag = 0;
		}
	}
	return (cnt);
}

char			**ft_split(char *str, char *charset)
{
	int					i;
	int					j;
	int					z;
	char				*tmp;
	char				**answer;

	answer = (char **)malloc(sizeof(char*) * malloc_size(str, charset) + 1);
	i = 0;
	tmp = str;
	while (i < malloc_size(str, charset) - 1)
	{
		while (check(*tmp, charset) == 1)
			tmp++;
		j = 0;
		while (tmp[j] && check(tmp[j], charset) == 0)
			j++;
		answer[i] = (char *)malloc(j + 1);
		answer[i][j] = '\0';
		z = 0;
		while (z < j)
			answer[i][z++] = *tmp++;
		i++;
	}
	answer[i] = 0;
	return (answer);
}
