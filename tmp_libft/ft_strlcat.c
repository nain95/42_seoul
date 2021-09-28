/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 22:54:54 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/02 22:56:51 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*d;
	char	*s;
	int		answer;

	d = dest;
	s = (char *)src;
	if (size <= ft_strlen(d))
	{
		return (ft_strlen(s) + size);
	}
	answer = ft_strlen(d) + ft_strlen(s);
	size -= 1;
	while (*d != '\0' && size != 0)
	{
		d++;
		size--;
	}
	while (size != 0 && *s)
	{
		*d++ = *s++;
		size--;
	}
	*d = '\0';
	return (answer);
}
