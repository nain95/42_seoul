/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:29:14 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/10 15:59:46 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					check_base(char flag, char *base, char num)
{
	int i;
	int j;

	i = -1;
	if (flag == 0)
	{
		while (base[++i])
		{
			if (base[i] == ' ' || base[i] == '\t' || base[i] == '\v' || \
					base[i] == '\f' || base[i] == '\r' || base[i] == '\n' || \
					base[i] == '+' || base[i] == '-')
				return (0);
			j = i;
			while (base[j++])
				if (base[i] == base[j])
					return (0);
		}
		return (1);
	}
	while (base[++i])
		if (base[i] == num)
			return (i);
	return (-1);
}

int					ft_len(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

unsigned int		converter(char *str, char *base)
{
	int				i;
	int				len_base;
	int				num;
	unsigned int	answer;

	num = 1;
	answer = 0;
	i = 0;
	while (str[i])
	{
		if (check_base(1, base, str[i]) == -1)
			break ;
		i++;
	}
	len_base = ft_len(base);
	i--;
	while (i >= 0)
	{
		answer += check_base(1, base, str[i]) * num;
		num *= len_base;
		i--;
	}
	return (answer);
}

char				*converter2(unsigned int num, int flag, char *base)
{
	char	*answer;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	answer = (char*)malloc(34);
	tmp = (char*)malloc(34);
	if (num == 0)
		answer[i++] = base[0];
	else if (flag == -1)
		answer[i++] = '-';
	while (num != 0)
	{
		tmp[j++] = base[num % ft_len(base)];
		num /= ft_len(base);
	}
	while (--j >= 0)
		answer[i++] = tmp[j];
	answer[i] = '\0';
	return (answer);
}

char				*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*nb;
	char			*answer;
	int				flag;

	nb = nbr;
	flag = 1;
	if (ft_len(base_from) <= 1 || ft_len(base_to) <= 1 || \
			check_base(0, base_from, ' ') == 0 ||\
			check_base(0, base_to, ' ') == 0)
		return (0);
	while (*nb == ' ' || *nb == '\t' || *nb == '\n' || *nb == '\v' || \
			*nb == '\r' || *nb == '\f')
		nb++;
	while (*nb == '+' || *nb == '-')
	{
		if (*nb++ == '-')
			flag *= -1;
	}
	answer = converter2(converter(nb, base_from), flag, base_to);
	return (answer);
}
