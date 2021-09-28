/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:08:12 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/06 20:37:25 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_pow(int num, int i)
{
	int answer;

	answer = 1;
	while (i-- > 0)
		answer *= num;
	return (answer);
}

int				cal_size(unsigned int n)
{
	int				size;
	unsigned int	tmp;

	tmp = 10;
	size = 1;
	while (n / tmp != 0)
	{
		tmp *= 10;
		size++;
	}
	return (size);
}

unsigned int	converter(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void			reverse(char *start, char *end)
{
	char	swap;

	while (start < end)
	{
		swap = *start;
		*start = *end;
		*end = swap;
		end--;
		start++;
	}
}

char			*ft_itoa(int n)
{
	int				flag;
	int				malloc_size;
	char			*new;
	char			*answer;
	unsigned int	num;

	flag = (n < 0) ? 1 : 0;
	num = (n < 0) ? -n : n;
	malloc_size = cal_size(num);
	if (!(new = (char *)malloc(flag + malloc_size + 1)))
		return (NULL);
	answer = new;
	if (num == 0)
		*new++ = '0';
	while (num > 0)
	{
		*new++ = (num % 10) + '0';
		num /= 10;
	}
	if (flag == 1)
		*new++ = '-';
	*new-- = '\0';
	reverse(answer, new);
	return (answer);
}
