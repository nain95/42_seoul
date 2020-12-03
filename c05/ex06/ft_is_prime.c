/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:46:59 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/03 15:51:29 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_is_prime(int nb)
{
	int	s;
	int	e;
	if (nb <= 1)
		return (0);
	e = nb / 2;
	s = 2;
	while (s <= e)
	{
		if (nb % s == 0)
			return (0);
		s++;
	}
	return (1);
}

int main()
{
	printf("%d",ft_is_prime(0));
}
