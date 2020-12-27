/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 20:47:38 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/25 21:07:17 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memccpy(void *dest, const void *src, int c, int n)
{
	const char *s;
	char *d;

	d = dest;
	s = src;
	while (n--)
	{
		*d++ = *s;
		if (*s++ == c)
			return (d);
	}
	return (0);
}
