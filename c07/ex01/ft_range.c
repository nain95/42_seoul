/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:10:15 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/05 00:19:26 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *answer;
	int i;

	if (min <= max)
		return (0);
	answer = (int *)malloc(sizeof(int) * (unsigned int)(max - min));
	i = 0;
	while (min < max)
		answer[i++] = min++;
	return (answer);
}
