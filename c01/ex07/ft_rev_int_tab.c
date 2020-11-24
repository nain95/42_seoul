/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:36:13 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/24 14:01:18 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int swap;
	int index;

	index = 0;
	size -= 1;
	while (index <= size / 2)
	{
		swap = tab[size - index];
		tab[size - index] = tab[index];
		tab[index] = swap;
		index++;
	}
}
