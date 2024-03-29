/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:20:46 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/08 10:04:28 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int count;
	int *tmp;

	if (min >= max)
		return (0);
	count = max - min;
	*range = (int *)malloc(sizeof(int) * count);
	if (!*range)
		return (-1);
	tmp = *range;
	while (min < max)
		*tmp++ = min++;
	return (count);
}
