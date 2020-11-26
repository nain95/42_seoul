/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:26:23 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/26 17:19:37 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_memory(void *addr)
{
	int i;
	int address[16];
	long tmp;
	char print[2];

	i = 0;
	tmp = (long)addr;
	while (tmp != 0)
	{
		address[i++] = tmp % 16;
		tmp /= 16;
	}
	write(1, "0000000000000000", 16 - i);
	while (i-- > 0)
	{
		if (address[i] < 10)
		{
			print[0] = address[i] + '0';
		}
		else
		{
			print[0] = address[i] + '0' + 39;
		}
		write(1, print, 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int tmp;
	char *test;
	long tee;

	print_memory(addr);
	return (addr);
}
