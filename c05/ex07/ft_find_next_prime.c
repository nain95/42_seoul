/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:51:47 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/06 12:18:50 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int s;
	int e;

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
