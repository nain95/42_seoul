/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:07:37 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/22 16:27:26 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int first;
	int second;

	first = -1;
	while (++first < 100)
	{
		second = first;
		while (++second < 100)
		{
			ft_putchar((first / 10) + '0');
			ft_putchar((first % 10) + '0');
			ft_putchar(' ');
			ft_putchar((second / 10) + '0');
			ft_putchar((second % 10) + '0');
			if (first != 98 || second != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
