/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:31:30 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/26 21:18:25 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count + 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		src_len;
	char	*d;
	char	*s;

	d = dest;
	s = src;
	src_len = ft_strlen(src);
	while (src_len--)
	{
		*d++ = *s++;
	}
	return (dest);
}
