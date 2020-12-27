/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:33:54 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/27 16:49:33 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char * str)
{
	int answer;

	answer = 0;
	while (*str++)
		answer++;
	return (answer);
}

char	*ft_strnstr(char *src, char *to_find, int len)
{
	int		i;
	char	*s;
	char	*t;
	
	len -= ft_strlen(to_find);
	t = to_find;
	s = src;
	if (*t == '\0')
		return (s);
	while (*s != '\0' && len-- > 0)
	{
		if (*s == *t)
		{
			i = 1;
			while (s[i] == t[i] && t[i] != '\0')
			{
				i++;
			}
			if (t[i] == '\0')
			{
				return (s);
			}
		}
		s++;
	}
	return (0);
}
