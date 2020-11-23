/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:11:25 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/23 21:36:57 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	alpha;

	alpha = "z";
	while (alpha >= 'a')
	{
		ft_putchar(alpha++);
	}
}
