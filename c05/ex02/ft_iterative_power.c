/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 00:49:33 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/03 20:11:45 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int result;
	int int_max;

	int_max = 2147483647;
	result = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0 && power == 0)
		return (1);
	while (power != 0)
	{
		result *= nb;
		power--;
		if (power != 0 && result > int_max / nb)
			return (0);
	}
	return (result);
}
