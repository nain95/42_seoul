/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:36:28 by ijeon             #+#    #+#             */
/*   Updated: 2021/09/27 16:39:58 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	malloc_size(const char *str, char c)
{
	int	cnt;
	int	flag;

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
			continue ;
		}
		str++;
	}
	if (*(--str) != c)
		cnt++;
	return (cnt);
}

static char	**ft_free(char **str, int i)
{
	while (i >= 0)
		free(str[i--]);
	free(str);
	return (NULL);
}

static char	*split_malloc(char *s, char c, int *flag)
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
	res = (char *)malloc(i + 1);
	ft_memset(res, 'a', i);
	res[i] = '\0';
	return (res);
}

static void	insert_string(char **answer, char **tmp)
{
	int	j;

	j = 0;
	while ((*answer)[j] != '\0')
	{
		(*answer)[j++] = **tmp;
		(*tmp)++;
	}
	if (**tmp == '\'')
		(*tmp)++;
}

char	**ft_split(char const *s, char c)
{
	char	*tmp;
	char	**answer;
	t_split	split_var;

	answer = (char **)malloc(sizeof(char *) * (malloc_size(s, c) + 1));
	if (s == NULL || answer == NULL)
		return (NULL);
	split_var.idx = -1;
	tmp = (char *)s;
	split_var.flag = 1;
	while (++split_var.idx < malloc_size(s, c))
	{
		while (*tmp == c)
			tmp++;
		if (*tmp == '\'' && tmp++)
			split_var.flag *= -1;
		answer[split_var.idx] = split_malloc(tmp, c, &split_var.flag);
		if (answer[split_var.idx] == NULL)
			return (ft_free(answer, split_var.idx - 1));
		split_var.pointer = answer[split_var.idx];
		insert_string(&split_var.pointer, &tmp);
	}
	answer[split_var.idx] = NULL;
	return (answer);
}
