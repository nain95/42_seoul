/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 22:49:20 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/06 20:22:49 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char		*answer;
	long long	count;

	count = 0;
	while (src[count])
		count++;
	answer = (char *)malloc(sizeof(char) * (count + 1));
	if (answer == NULL)
		return (NULL);
	answer[count] = '\0';
	while (--count >= 0)
	{
		answer[count] = src[count];
	}
	return (answer);
}
