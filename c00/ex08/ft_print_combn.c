/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:58:13 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/23 21:21:46 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstring(char *c, int n)
{
	int i;

	i = -1;
	while (c[++i] != '\0')
	{
		write(1, &c[i], 1);
	}
	if (c[0] - 48 != 9 - n + 1)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	int		tmp;
	int		count;
	char	*number;

	number = "0000000000";
	count = -1;
	number[n] = '\0';
	tmp = n - 2;
	while (number[0] - 48 < 9 - n + 2)
	{
		number[n - 1] += 1;
		ft_putstring(number, n);
		if (number[n - 1] >= '9')
		{
			number[tmp] += 1;
			if (number[tmp--] >= '9' && tmp != 0)
			{
				number[tmp] += 1;
				number[tmp + 1] = number[tmp] + 1;
			}
			tmp = n - 2;
			number[n - 1] = number[n - 2];
		}
	}
}
