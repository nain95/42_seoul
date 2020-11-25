/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:33:12 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/25 18:23:00 by ijeon            ###   ########.fr       */
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

void	ft_putnbr(int nb)
{
	int		count;
	int		n;
	char	number[11];
	unsigned int	unsigned_nb;

	count = 0;
	n = 1;
	if (nb < 0)
	{
		unsigned_nb = nb * (-1);
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
