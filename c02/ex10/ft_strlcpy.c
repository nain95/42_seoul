/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:42:31 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/26 14:24:31 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;

	i = 0;
	if (size == 1)
	{
		dest[i] = '\0';
		return (size);
	}
	while (src[i] != '\0' && size-- != 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i+1] = '\0';
	return (size);
}

int main()
{
	char dest[5] = "";
	char src[7] = "123456";

	ft_strlcpy(dest,src,5);
	printf("%s\n",dest);
}
