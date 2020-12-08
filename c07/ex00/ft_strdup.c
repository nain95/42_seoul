/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:57:37 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/08 09:56:59 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char			*answer;
	unsigned long	count;

	count = 0;
	while (src[count])
		count++;
	answer = (char *)malloc(sizeof(char) * (count + 1));
	answer[count] = '\0';
	while (--count >= 0)
	{
		answer[count] = src[count];
	}
	return (answer);
}
