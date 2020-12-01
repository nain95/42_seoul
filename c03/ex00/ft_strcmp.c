/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:04:39 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/30 11:04:29 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s2[i] - s1[i]);
		i++;
	}
	if (s1[i] != s2[i])
		return (s2[i] - s1[i]);
	return (0);
}

int main()
{
	char* str1 = "BlockDMask";
    char* str2 = "Block";
    char* str3 = "BlockDMask";
    char* str4 = "BlockFMask";
    char* str5 = "BlockAMask";

    printf("ft_strcmp(%s, %s)\t = %d\n", str1, str2, ft_strcmp(str1, str2));
    printf("ft_strcmp(%s, %s)\t = %d\n", str1, str3, ft_strcmp(str1, str3));
    printf("ft_strcmp(%s, %s)\t = %d\n", str1, str4, ft_strcmp(str1, str4));
    printf("ft_strcmp(%s, %s)\t = %d\n", str1, str5, ft_strcmp(str1, str5));

}
