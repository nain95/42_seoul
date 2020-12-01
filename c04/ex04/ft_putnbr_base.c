/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:09:17 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/01 21:12:16 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *src)
{
	int count;
	char *s;

	s = src;
	while (*s != '\0')
	{
		count++;
	}
	return (count)
}

void	ft_putnbr_base(int nbr, char *base)
{
	int b;

	b = ft_strlen(base);

}
