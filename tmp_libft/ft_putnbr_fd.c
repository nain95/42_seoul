/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:43:45 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/02 23:24:14 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	num_len(unsigned n)
{
	unsigned tmp;

	tmp = 10;
	while (n / tmp != 0)
		tmp *= 10;
	return (tmp / 10);
}

void			ft_write_nbr(unsigned int nb, int fd)
{
	char c;

	if (nb >= 10)
	{
		ft_write_nbr(nb / 10, fd);
		ft_write_nbr(nb % 10, fd);
	}
	else
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int num;

	if (n < 0)
		write(fd, "-", 1);
	num = (n < 0) ? -n : n;
	ft_write_nbr(num, fd);
}
