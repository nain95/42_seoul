/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:19:06 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/28 19:19:09 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *d;
	char *s;

	d = dest;
	s = src;
	while (*s != '\0' && n--)
	{
		*d++ = *s++;
	}
	while (n--)
	{
		*d++ = '\0';
	}
	return (dest);
}
