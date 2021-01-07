/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:04:49 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/07 01:50:05 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		malloc_size;
	char	*result;
	char	*tmp1;
	char	*tmp2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	malloc_size = ft_strlen(tmp1) + ft_strlen(tmp2);
	if (!(result = (char *)malloc(malloc_size + 1)))
		return (NULL);
	result[0] = '\0';
	result = ft_strcat(result, tmp1);
	result = ft_strcat(result, tmp2);
	return (result);
}
