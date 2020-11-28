/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:48:52 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/28 18:57:55 by ijeon            ###   ########.fr       */
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

void	non_printable(char c)
{
	int i;
	int j;
	int hex[2];

	i = c + 0;
	j = 0;
	while (i != 0)
	{
		hex[j++] = i % 16;
		i /= 16;
	}
	j--;
	if (j == 0)
	{
		write(1, "0", 1);
	}
	while (j >= 0)
	{
		print_hex(hex[j]);
		j--;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31)
		{
			write(1, "\\", 1);
			non_printable(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
