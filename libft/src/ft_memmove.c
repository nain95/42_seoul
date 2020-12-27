/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:08:08 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/27 15:35:04 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memmove(void *dest, void *src, int size)
{
	char *tmp;
	char *s;

	if (dest <= src)
	{
		tmp = dest;
		s = src;
		while (size--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = dest + size;
		//tmp += size;
		s = src + size;
		//s += size;
		while (size--)
			*--tmp = *--s;
	}
	return (dest);
}
