/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:26:23 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/28 19:40:25 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int num)
{
	char hex;

	if (num < 10)
	{
		hex = num + '0';
	}
	else
	{
		hex = num + 39 + '0';
	}
	write(1, &hex, 1);
}

void	print_memory(void *addr)
{
	int		i;
	int		address[16];
	long	long_addr;

	i = 0;
	long_addr = (long)addr;
	while (long_addr != 0)
	{
		address[i++] = long_addr % 16;
		long_addr /= 16;
	}
	write(1, "0000000000000000", 16 - i);
	while (i-- > 0)
	{
		print_hex(address[i]);
	}
	write(1, ": ", 2);
}

char	print_hex_contents(char c)
{
	int tmp;
	int i;
	int hex[2];

	i = 1;
	hex[0] = 0;
	hex[1] = 0;
	tmp = c;
	while (tmp != 0)
	{
		hex[i--] = tmp % 16;
		tmp /= 16;
	}
	i = 0;
	while (i < 2)
	{
		print_hex(hex[i++]);
	}
	return (c);
}

void	print_contents(char *contents, unsigned int count, unsigned int size)
{
	int i;

	i = 0;
	while (i < 16 && (count < size))
	{
		if (0 <= contents[i] && contents[i] <= 31)
		{
			write(1, ".", 1);
		}
		else
		{
			write(1, &contents[i], 1);
		}
		i++;
		count++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int					i;
	char				print[16];
	char				*add;
	unsigned int		count;

	count = 0;
	add = addr;
	while (count < size)
	{
		i = 0;
		print_memory(add);
		while (i < 16 && count != size)
		{
			print[i++] = print_hex_contents(*add++);
			if (i % 2 == 0)
			{
				write(1, " ", 1);
			}
			count++;
		}
		write(1, "                                 ", (16 - i) / 2 * 5);
		print_contents(print, count - i, size);
	}
	return (addr);
}
int main()
{
	char c[] = "aaaaaaaaaaaaaaaabbbbbb";
	ft_print_memory(c,22);
}
