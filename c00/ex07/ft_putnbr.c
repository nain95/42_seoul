/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:33:12 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/23 21:07:36 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		count;
	int		n;
	char	number[10];

	n = 1;
	count = 0;
	while (nb > n)
	{
		number[count] = (nb / n % 10) + '0';
		count++;
		n *= 10;
	}
	while (--count >= 0)
	{
		ft_putchar(number[count]);
	}
}
