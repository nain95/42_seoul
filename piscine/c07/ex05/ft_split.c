/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:36:28 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/10 03:45:04 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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

unsigned int	malloc_size(char *str, char *charset)
{
	int	cnt;
	
	while (check(*str, charset) == 1)
		str++;
	cnt = 1;
	while (*str)
	{
		if (check(*str, charset) == 1)
		{
			cnt++;
			while (*str && check(*str, charset) == 1)
				str++;
		}
		str++;
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
	int		size;

	size = malloc_size(str, charset);
	answer = (char **)malloc(sizeof(char**) * (size + 1));
	i = 0;
	tmp = str;
	while (i < size)
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
		printf("%s\n",answer[i]);
		i++;
	}
	answer[i] = 0;
	return (answer);
}

int main()
{
	char **t;

	t = ft_split("1234asdf1234","34");
	printf("-----------\n");
	while (*t)
		printf("%s\n",*t++);
}
