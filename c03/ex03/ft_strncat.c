/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:30:29 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/01 21:53:20 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *d;
	char *s;

	d = dest;
	s = src;
	while (*d != '\0')
	{
		d++;
	}
	while (*s != '\0' && nb != 0)
	{
		*d++ = *s++;
		nb--;
	}
	*d = '\0';
	return (dest);
}
