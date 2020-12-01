/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:33:54 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/30 23:36:53 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *src, char *to_find)
{
	int		i;
	char	*s;
	char	*t;
	
	t = to_find;
	s = src;
	while (*src != '\0')
	{
		if (*src == *t)
		{
			i = 1;
			while (src[i] == t[i] && t[i] != '\0')
			{
				i++;
			}
			if (t[i] == '\0')
			{
				return (src);
			}
		}
		src++;
	}
}
