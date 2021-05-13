/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:10:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/13 17:21:24 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_memory(unsigned long long addr, t_option *options, char *base)
{
	int		len;
	int		res;
	char	*address;

	len = max(options->dot, max(1, unsigned_num_len(addr, HEX))) + 2;
	if (addr == 0 && options->dot == 0)
		len--;
	address = (char *)malloc(len + 1);
	address[len--] = '\0';
	if (addr != 0 || options->dot != 0)
	{
		while (options->dot > 0 || len > 1)
		{
			address[len--] = base[addr % 16];
			addr /= 16;
			options->dot -= 1;
		}
	}
	address[len--] = 'x';
	address[len] = '0';
	options->dot = -1;
	res = print_string(address, options);
	free(address);
	return (res);
}
