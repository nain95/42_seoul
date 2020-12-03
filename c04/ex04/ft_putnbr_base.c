/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:09:17 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/03 13:23:25 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_strlen(char *src)
{
	int		count;
	char	*s;

	count = 0;
	s = src;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

void		print_nbr(char *nbr, int i)
{
	while (i >= 0)
	{
		write(1, &nbr[i], 1);
		i--;
	}
}

int			check(int len_b, char *base)
{
	int i;
	int j;

	i = 0;
	while (i < len_b - 1)
	{
		j = i + 1;
		while (j < len_b)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-')
			return (1);
		base++;
	}
	return (0);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int				len_b;
	int				i;
	char			answer[32];
	unsigned int	unsigned_nbr;

	len_b = ft_strlen(base);
	if (len_b <= 1 || check(len_b, base))
		return ;
	if (nbr < 0)
	{
		unsigned_nbr = nbr * -1;
		write(1, "-", 1);
	}
	else
		unsigned_nbr = nbr;
	i = 0;
	while (unsigned_nbr != 0)
	{
		answer[i] = base[unsigned_nbr % len_b];
		unsigned_nbr = unsigned_nbr / len_b;
		i++;
	}
	print_nbr(answer, i);
}
