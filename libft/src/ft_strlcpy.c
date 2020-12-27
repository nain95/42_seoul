/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:05:14 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/27 16:20:03 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(const char *str)
{
	int answer;

	answer = 0;
	while (*str++)
		answer++;
	return (answer);
}

void *ft_memcpy(void *destination, const void *source, int num)
{
	const char *tmp;
	char *d;

	d = destination;
	tmp = source;
	while (num--)
		*d++ = *tmp++;
	return (destination);
}

int ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int answer;
	int len;

	answer = ft_strlen(src);
	if (dstsize)
	{
		len = (answer >= dstsize)?dstsize - 1 : answer;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (answer);
}
