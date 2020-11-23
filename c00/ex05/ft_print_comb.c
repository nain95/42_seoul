/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:35:48 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/22 15:24:14 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	first;
	int	second;
	int	third;

	first = -1;
	while (++first <= 9)
	{
		second = first;
		while (++second <= 9)
		{
			third = second;
			while (++third <= 9)
			{
				ft_putchar(first + '0');
				ft_putchar(second + '0');
				ft_putchar(third + '0');
				if (first != 7 || second != 8 || third != 9)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}

int		main(void)
{
	ft_print_comb();
}
