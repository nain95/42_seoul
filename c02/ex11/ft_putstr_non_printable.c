/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:48:52 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/08 15:36:27 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char c)
{
	c = c + '0';
	if (c > '9')
		c += 39;
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] >= 127)
		{
			write(1, "\\", 1);
			print_hex(str[i] / 16);
			print_hex(srt[i] % 16);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
