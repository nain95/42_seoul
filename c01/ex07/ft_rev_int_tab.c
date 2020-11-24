/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:36:13 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/24 23:21:32 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int swap;
	int index;

	index = 0;
	size -= 1;
	while (index < size)
	{
		swap = tab[size];
		tab[size] = tab[index];
		tab[index] = swap;
		size--;
		index++;
	}
}
