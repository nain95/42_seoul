/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:36:28 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/13 18:38:39 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				malloc_size(const char *str, char c)
{
	int	cnt;

	if (!*str)
		return (0);
	cnt = 0;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		if (*str == c)
		{
			cnt++;
			while (*str && *str == c)
				str++;
			continue;
		}
		str++;
	}
	if (*(--str) != c)
		cnt++;
	return (cnt);
}

void			ft_free(char **str, int i)
{
	while (i >= 0)
		free(str[i--]);
	free(str);
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
	while (++i < malloc_size(s, c))
	{
		while (*tmp == c)
			tmp++;
		if (!(answer[i] = split_malloc(tmp, c)))
		{
			ft_free(answer, i - 1);
			return (NULL);
		}
		j = 0;
		while (answer[i][j] != '\0')
			answer[i][j++] = *tmp++;
	}
	answer[i] = NULL;
	return (answer);
}
