/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:58:13 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/24 22:05:36 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_strcpy(char *num, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		num[i] = str[i];
		i++;
	}
}

void	ft_putstring(char *c, int n)
{
	write(1, c, n);
	if (c[0] - 48 != 10 - n)
	{
		write(1, ", ", 2);
	}
}

void	recursive(char *num, int start, int end)
{
	int j;

	j = 0;
	if (start == end)
	{
		ft_putstring(num, end);
	}
	else
	{
		j = num[start - 1] + 1;
		num[start] = num[start - 1];
		while (num[start] < '9')
		{
			num[start] = j;
			recursive(num, start + 1, end);
			j++;
		}
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		count;
	char	number[11];

	ft_strcpy(number, "0000000000");
	count = -1;
	number[n] = '\0';
	i = 0;
	while (i < 10)
	{
		number[0] = '0' + i;
		recursive(number, 1, n);
		i++;
	}
}
