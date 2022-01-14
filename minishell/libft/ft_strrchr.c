/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 02:01:03 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/02 22:37:40 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		len;

	tmp = (char *)s;
	len = ft_strlen(tmp);
	tmp += len;
	while (len-- >= 0)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp--;
	}
	return (0);
}
