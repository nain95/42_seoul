/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:28:13 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/30 11:21:20 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char d;
	char s;

	d = dest;
	s = src;
	while(*d != '\0')
	{
		d++;
	}
	while(*s != '\0')
	{
		*d++ = *s++;
	}
	*s = '\0';
}
