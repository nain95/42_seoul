/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:31:48 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/06 19:35:23 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	char *d;
	char *s;

	d = dest;
	s = src;
	while (*d != '\0')
		d++;
	while (*s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (dest);
}

int		ft_len(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		malloc_size;
	int		i;
	int		tmp_size;
	char	*result;

	if (size <= 0)
	{
		result = (char *)malloc(1);
		result[0] = 0;
		return (result);
	}
	malloc_size = (size - 1) * ft_len(sep);
	tmp_size = size;
	while (--size >= 0)
		malloc_size += ft_len(strs[size]);
	result = (char *)malloc(malloc_size + 1);
	result[0] = 0;
	result = ft_strcat(result, strs[0]);
	i = 1;
	while (--tmp_size)
	{
		result = ft_strcat(result, sep);
		result = ft_strcat(result, strs[i++]);
	}
	return (result);
}
