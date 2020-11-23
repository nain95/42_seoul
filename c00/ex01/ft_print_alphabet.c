/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:00:13 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/23 21:37:02 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_print_alphabet(void)
{
	char alpha;

	alpha = "a";
	while (alpha <= 'z')
	{
		ft_putchar(alpha++);
	}
}
