/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:48:52 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/29 22:52:51 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	non_printable(char c)
{
	int		i;
	int		j;
	int		hex_num[3];
	char	*hex;

	hex = "0123456789abcdefg";
	i = c + 0;
	j = 0;
	hex_num[1] = 0;
	while (i != 0)
	{
		hex_num[j++] = i % 16;
		i /= 16;
	}
	j = 1;
	while (j >= 0)
	{
		write(1, &hex[hex_num[j]], 1);
		j--;
	}
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
			non_printable(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
