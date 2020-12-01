/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:52:36 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/01 20:42:04 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *src)
{
	int	count;
	char	*s;

	s = src;
	count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

int main()
{
	char tmp[] = "abc";

	printf("%d ",ft_strlen(tmp));
	printf("%lu\n",strlen(tmp));
}