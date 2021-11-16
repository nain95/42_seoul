/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:28:06 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/16 19:04:20 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strchr_idx(const char *s, int c)
{
	int	res;

	res = 0;
	while (s[res])
	{
		if (s[res] == (char)c)
			return (res);
		res++;
	}
	return (-1);
}
