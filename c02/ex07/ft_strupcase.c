/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:55:08 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/26 00:58:12 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

int main()
{
	char test[10] = "adcAsdW12";

	ft_strupcase(test);
	printf("%s",test);
}
