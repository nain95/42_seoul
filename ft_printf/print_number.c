/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:17:07 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/07 17:53:07 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*precision_number(long long nb, int precision, char *base)
{
	char		*nbr;
	long long	unsigned_nb;

	if (!(nbr = (char *)malloc(sizeof(char) * (precision + 1))))
		return (NULL);
	if (nb < 0)
		unsigned_nb = nb * -1;
	else
		unsigned_nb = nb;
	nbr[precision] = '\0';
	while (precision-- > 0)
	{
		if (unsigned_nb != 0)
		{
			nbr[precision] = base[unsigned_nb % (int)ft_strlen(base)];
			unsigned_nb /= (int)ft_strlen(base);
		}
		else
			nbr[precision] = '0';
	}
	return (nbr);
}

int			plus_print(long long nb, char *nbr, int space, t_option *options)
{
	int	cnt;

	cnt = 0;
	if (options->dot < 0 && options->zero == 1)
	{
		if (nb < 0 && ++cnt)
			write(1, "-", 1);
		cnt += print_space(space, "0");
	}
	else
	{
		cnt += print_space(space, " ");
		if (nb < 0 && ++cnt)
			write(1, "-", 1);
	}
	while (*nbr && ++cnt)
		write(1, nbr++, 1);
	return (cnt);
}

int			width_number(long long nb, char *nbr, int len, t_option *options)
{
	int cnt;
	int space;

	cnt = 0;
	space = max(0, options->width - len);
	if (nb < 0)
		space--;
	if (options->minus == 1)
	{
		if (nb < 0 && ++cnt)
			write(1, "-", 1);
		while (*nbr && ++cnt)
			write(1, nbr++, 1);
		cnt += print_space(space, " ");
	}
	else
		cnt += plus_print(nb, nbr, space, options);
	return (cnt);
}

int			print_nbr(long long nb, t_option *options, char *base)
{
	int			cnt;
	int			precision;
	char		*number;

	precision = max(options->dot, num_len(nb, base));
	if (options->dot < 0 && nb == 0)
		precision++;
	number = precision_number(nb, precision, base);
	cnt = width_number(nb, number, precision, options);
	free(number);
	return (cnt);
}
