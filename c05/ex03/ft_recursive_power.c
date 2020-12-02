/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 01:03:07 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/03 01:37:15 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_recursive_power(int nb, int power)
{
	int	int_max;
	int	tmp;

	int_max = 2147483647;
	if (nb < 0)
		return (0);
	else if (nb == 0 && power == 0)
		return (0);
	if (power == 1)
		return (nb);
	tmp = nb * ft_recursive_power(nb, power-1);
	if (power == 9 && tmp > int_max / nb)
		return (0);
	return (tmp);
}

int main()
{
	printf("%d",ft_recursive_power(10,10));
}
