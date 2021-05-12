/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:19:43 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/01 03:36:28 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_space(int size, char *space)
{
	int i;

	i = 0;
	while (i++ < size)
		write(1, space, 1);
	return (--i);
}

int		num_len(long long nb, char *base)
{
	int	cnt;

	cnt = 0;
	while (nb != 0)
	{
		nb = nb / (int)ft_strlen(base);
		++cnt;
	}
	return (cnt);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
