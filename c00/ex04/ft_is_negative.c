/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:22:36 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/23 21:28:16 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_is_negative(int n)
{
	if (n % 2 == 0)
	{
		ft_putchar('P');
	}
	else
	{
		ft_putchar('N');
	}
}
