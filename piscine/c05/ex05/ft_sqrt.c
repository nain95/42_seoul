/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:43:01 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/06 14:03:02 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int num;

	num = 1;
	if (nb < 0)
		return (0);
	while (num * num < (unsigned int)nb)
	{
		num++;
	}
	if (num * num == (unsigned int)nb)
		return ((int)num);
	return (0);
}
