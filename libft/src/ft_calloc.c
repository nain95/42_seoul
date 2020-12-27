/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 01:24:19 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/28 01:30:39 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void *ft_memset(void *ptr, int value, int num)
{
        unsigned char *tmp = ptr;
        while (num-- > 0)
                *tmp++ = value;
        return (ptr);
}

void *ft_calloc(int n, int size)
{
	char *new;

	if (!(new = malloc(n * size)))
		return (0);
	new = ft_memset(new, 0, n * size);
	return (new);
}
