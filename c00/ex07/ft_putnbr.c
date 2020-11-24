/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:33:12 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/24 22:11:37 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_num(char *num, int count)
{
	while (--count >= 0)
	{
		write(1, &num[count], 1);
	}
}

int		check(int num)
{
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		return (-1);
	}
	else
	{
		return (1);
	}
}

void	ft_putnbr(int nb)
{
	int		count;
	int		n;
	char	number[11];

	count = 0;
	n = check(nb);
	if (nb == -2147483648)
	{
		nb = ((nb + 1) * (-1)) / 10;
		number[0] = '8';
		count = 1;
		n = 1;
	}
	while (nb % n != nb)
	{
		number[count++] = (nb / n % 10) + '0';
		if (n == 1000000000)
		{
			number[count] = (nb / 1000000000) + '0';
			break ;
		}
		n *= 10;
	}
	ft_rev_num(number, count);
}
