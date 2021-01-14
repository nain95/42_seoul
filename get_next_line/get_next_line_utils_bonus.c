/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:07:10 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/13 21:12:11 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char		*answer;
	long long	count;

	count = 0;
	while (src[count])
		count++;
	if (!(answer = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	answer[count] = '\0';
	while (--count >= 0)
	{
		answer[count] = src[count];
	}
	return (answer);
}

int		ft_strchr(const char *s, char c)
{
	int		i;

	i = 0;
	if (c == 0)
		return (ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcat(char *dest, char *src)
{
	char *d;
	char *s;

	d = dest;
	s = src;
	if (!src)
		return (dest);
	else if (!dest)
		return (src);
	while (*d != '\0')
		d++;
	while (*s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		malloc_size;
	char	*result;
	char	*tmp1;
	char	*tmp2;

	if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	malloc_size = ft_strlen(tmp1) + ft_strlen(tmp2);
	if (!(result = (char *)malloc(malloc_size + 1)))
		return (NULL);
	result[0] = '\0';
	result = ft_strcat(result, tmp1);
	free(s1);
	result = ft_strcat(result, tmp2);
	return (result);
}
