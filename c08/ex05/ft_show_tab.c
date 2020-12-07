/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:50:11 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/07 22:16:56 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	char c;

	c = '0' + nbr % 10;
	ft_putnbr(nbr / 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		par++;
	}
}
