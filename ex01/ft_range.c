/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:10:15 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/08 19:14:50 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *answer;
	int *tmp;

	if (min >= max)
		return (0);
	answer = (int *)malloc(sizeof(int) * (unsigned int)(max - min));
	if (!answer)
		return (0);
	tmp = answer;
	while (min < max)
		*(tmp++) = min++;
	return (answer);
}
