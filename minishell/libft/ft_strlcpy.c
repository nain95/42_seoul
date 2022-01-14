/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:05:14 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/07 01:50:34 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	answer;
	size_t	len;

	if (src == NULL || dst == NULL)
		return (0);
	answer = ft_strlen(src);
	if (dstsize)
	{
		if (answer >= dstsize)
			len = dstsize - 1;
		else
			len = answer;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (answer);
}
