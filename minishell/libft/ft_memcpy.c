/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 20:26:30 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/06 18:00:06 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*d;

	d = (unsigned char *)destination;
	tmp = (unsigned char *)source;
	if (d == NULL && tmp == NULL)
		return (NULL);
	while (n > 0)
	{
		*d++ = *tmp++;
		n--;
	}
	return (destination);
}
