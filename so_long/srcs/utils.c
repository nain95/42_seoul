/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:08:20 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/20 02:08:21 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_error(char *error_message, t_info *info)
{
	write(1, error_message, ft_strlen(error_message));
	free_memory(info);
	return (-1);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putnbr(int nb)
{
	char	nb_arry[10];
	long	nb_change;
	int		i;

	i = 0;
	nb_change = nb;
	if (nb == 0)
		ft_putchar('0');
	else if (nb < 0)
	{
		ft_putchar('-');
		nb_change = -nb_change;
	}
	while (i < 10)
	{
		nb_arry[i] = nb_change % 10;
		nb_change = nb_change / 10;
		i++;
		if (nb_change == 0)
			break ;
	}
	while (i--)
		ft_putchar(nb_arry[i] + '0');
}

int	ft_strchr_idx(const char *s, int c, int start)
{
	int	res;

	res = start + 1;
	while (s[res])
	{
		if (s[res] == (char)c)
			return (res);
		res++;
	}
	return (-1);
}

int	ft_strchr_count(const char *s, int c)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			count++;
		idx++;
	}
	return (count);
}
