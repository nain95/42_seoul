/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:00:05 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/27 16:26:53 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 int	ft_strlen(char *src)
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

int	ft_strlcat(char *dest, char *src, int size)
{
	char			*d;
	char			*s;
	int	answer;

	d = dest;
	s = src;
	if (size <= ft_strlen(d))
	{
		return (ft_strlen(s) + size);
	}
	answer = ft_strlen(d) + ft_strlen(s);
	size -= 1;
	while (*d != '\0' && size != 0)
	{
		d++;
		size--;
	}
	while (size != 0 && *s)
	{
		*d++ = *s++;
		size--;
	}
	*d = '\0';
	return (answer);
}
