/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:08:08 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/02 22:05:18 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char *d;
	unsigned char *s;

	if (dest == src || size == 0)
		return (dest);
	if (dest <= src)
	{
		d = (unsigned char*)dest;
		s = (unsigned char*)src;
		while (size--)
			*d++ = *s++;
	}
	else
	{
		d = (unsigned char*)dest + size;
		s = (unsigned char*)src + size;
		while (size-- > 0)
			*--d = *--s;
	}
	return (dest);
}
