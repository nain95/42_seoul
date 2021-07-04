/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:36:28 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/04 23:09:07 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int			malloc_size(const char *str, char c)
{
	int	cnt;
	int flag;

	flag = 1;
	if (!*str)
		return (0);
	cnt = 0;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		if (*str == '\'')
			flag *= -1;
		if (flag == 1 && *str == c)
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

static char			**ft_free(char **str, int i)
{
	while (i >= 0)
		free(str[i--]);
	free(str);
	return (NULL);
}

static char			*split_malloc(char *s, char c, int *flag)
{
	int		i;
	char	*res;

	i = 0;
	if (*flag == -1)
	{
		c = '\'';
		*flag *= -1;
	}
	while (s[i] && s[i] != c)
		i++;
	if (!(res = (char *)malloc(i + 1)))
		return (NULL);
	ft_memset(res, 'a', i);
	res[i] = '\0';
	return (res);
}

static void			insert_string(char **answer, char **tmp)
{
	int j;

	j = 0;
	while ((*answer)[j] != '\0')
	{
		(*answer)[j++] = **tmp;
		(*tmp)++;
	}
	if (**tmp == '\'')
		(*tmp)++;
}

char				**ft_split(char const *s, char c)
{
	int		i;
	int		flag;
	char	*tmp;
	char	**answer;
	char	*pointer;

	if (s == NULL || !(answer = \
				(char **)malloc(sizeof(char*) * (malloc_size(s, c) + 1))))
		return (NULL);
	i = -1;
	tmp = (char *)s;
	flag = 1;
	while (++i < malloc_size(s, c))
	{
		while (*tmp == c)
			tmp++;
		if (*tmp == '\'' && tmp++)
			flag *= -1;
		if (!(answer[i] = split_malloc(tmp, c, &flag)))
			return (ft_free(answer, i - 1));
		pointer = answer[i];
		insert_string(&pointer, &tmp);
	}
	answer[i] = NULL;
	return (answer);
}
