/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:58:13 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/23 19:05:00 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


void	ft_print_combn(int n)
{
	char number[11] = "00000000000";
	int count;
	int tmp;
	int plus;

	count = -1;
	number[n] = '\0';
	plus = n-1;
	tmp = n-2;
	while (number[0]-48 < 9-n+2)
	{
		number[plus] += 1;
		printf("%s\n",number);
		if (number[plus] >= '9')
		{
			number[tmp] += 1;
			if (number[tmp] >= '9')
			{
				tmp--;
				number[tmp] += 1;
				number[tmp+1] = number[tmp];
			}
			tmp = n-2;
			number[plus] = number[plus-1];
		}
	}

}

int main(void)
{
	ft_print_combn(2);

}
