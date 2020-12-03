/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:56:16 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/03 16:15:40 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_ten_queens_puzzle(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		ft_ten_queens_puzzle();
	}
}

int main()
{
	ft_ten_queens_puzzle();
}
