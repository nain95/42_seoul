/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:00:05 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/01 21:53:40 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = src;
	while (*tmp != '\0')
	{
		tmp++;
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*d;
	char			*s;
	unsigned int	answer;

	d = dest;
	s = src;
	if (size <= ft_strlen(d))
	{
		return (ft_strlen(s) + size);
	}
	answer = ft_strlen(d) + ft_strlen(s);
	size -= 1;
	while (*d != '\0')
	{
		d++;
		size--;
	}
	while (size != 0)
	{
		*d++ = *s++;
		size--;
	}
	*d = '\0';
	return (answer);
}
