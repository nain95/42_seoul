/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:19:06 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/01 21:52:01 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *d;
	char *s;

	d = dest;
	s = src;
	while (*s != '\0' && n != 0)
	{
		*d++ = *s++;
		n--;
	}
	while (n != 0)
	{
		*d++ = '\0';
		n--;
	}
	return (dest);
}


int main()
{
    char str1[] = "abc";
    char str2[] = "zxcvb";
    char str3[] = "abc";
    char str4[] = "zxcvb";

    printf("ft_strncmp(%s, %s)\t = %s\n", str1, str2, ft_strncpy(str1, str2, 4));
    printf("strncmp(%s, %s)\t = %s\n", str3, str4, strncpy(str3, str4, 4));
}
