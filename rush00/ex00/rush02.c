/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:43:58 by jjeon             #+#    #+#             */
/*   Updated: 2020/11/21 12:06:28 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

void		print_line(char head, char mid, char tail, int x)
{
	int i;

	i = x;
	while (i >= 1)
	{
		if (i == x)
		{
			ft_putchar(head);
		}
		else if (i == 1)
		{
			ft_putchar(tail);
		}
		else
		{
			ft_putchar(mid);
		}
		i--;
	}
	ft_putchar('\n');
}

void		rush(int x, int y)
{
	int j;

	j = y;
	while (j >= 1)
	{
		if (j == y)
		{
			print_line('A', 'B', 'A', x);
		}
		else if (j == 1)
		{
			print_line('C', 'B', 'C', x);
		}
		else
		{
			print_line('B', ' ', 'B', x);
		}
		j--;
	}
}
