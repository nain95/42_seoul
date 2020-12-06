/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:51:47 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/06 17:01:37 by ijeon            ###   ########.fr       */
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
	return (num);
}

int	ft_is_prime(int nb)
{
	int s;
	int e;

	if (nb <= 1)
		return (0);
	e = ft_sqrt(nb);
	s = 2;
	while (s <= e)
	{
		if (nb % s == 0)
			return (0);
		s++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int answer;

	if (nb <= 2)
		return (2);
	else if (ft_is_prime(nb) == 1)
		return (nb);
	answer = nb;
	while (1)
	{
		answer += 1;
		if (ft_is_prime(answer) == 1)
			return (answer);
	}
}
