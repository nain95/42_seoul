/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 02:17:55 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/06 20:30:48 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(new = (char *)malloc(len + 1)))
		return (NULL);
	while (start < ft_strlen(s) && len--)
	{
		new[i++] = s[start];
		start++;
	}
	new[i] = '\0';
	return (new);
}
