/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:36:28 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/08 21:37:39 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				malloc_size(char const *str, char c)
{
	int	cnt;
	int flag;

	flag = 1;
	while (*str == c)
		str++;
	cnt = 1;
	while (*str)
	{
		if (*str++ == c)
		{
			flag = 1;
			while (*str && *str == c)
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

char			*split_malloc(char *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(res = (char *)malloc(i + 1)))
		return (NULL);
	ft_memset(res, 'a', i);
	res[i] = '\0';
	return (res);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	*tmp;
	char	**answer;

	if (s == NULL || !(answer = \
				(char **)malloc(sizeof(char*) * (malloc_size(s, c) + 1))))
		return (NULL);
	i = -1;
	tmp = (char *)s;
	while (++i < malloc_size(s, c) - 1)
	{
		while (*tmp == c)
			tmp++;
		if (!(answer[i] = split_malloc(tmp, c)))
		{
			free(answer);
			return (NULL);
		}
		j = 0;
		while (answer[i][j] != '\0')
			answer[i][j++] = *tmp++;
	}
	answer[i] = 0;
	return (answer);
}
