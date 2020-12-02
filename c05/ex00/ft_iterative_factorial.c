/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 00:07:02 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/03 00:48:58 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	answer;
	int	i;

	i = 1;
	answer = 1;
	if (nb <= 0 || nb > 12)
		return (0);
	while (i <= nb)
	{
		answer *= i++;
	}
	return (answer);
}

int main()
{
	printf("%d",ft_iterative_factorial(5));
}
