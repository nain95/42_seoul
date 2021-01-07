/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 22:38:08 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/07 16:29:53 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	int		i;
	char	*s;
	char	*t;

	t = (char *)to_find;
	s = (char *)src;
	if (ft_strlen(src) < ft_strlen(to_find) || len < ft_strlen(to_find))
		return (NULL);
	if (!*t)
		return (s);
	len -= ft_strlen(t) - 1;
	while (*s != '\0' && len-- > 0)
	{
		if (*s == *t)
		{
			i = 1;
			while (s[i] == t[i] && t[i] != '\0')
				i++;
			if (t[i] == '\0')
				return (s);
		}
		s++;
	}
	return (NULL);
}
