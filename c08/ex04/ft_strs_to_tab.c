/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:24:46 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/08 13:07:56 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*answer;
	int				i;
	int				j;

	if (!(answer = (t_stock_str*)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	i = 0;
	while (i < ac)
	{
		answer[i].size = ft_strlen(av[i]);
		answer[i].str = (char *)malloc(answer[i].size + 1);
		answer[i].copy = (char *)malloc(answer[i].size + 1);
		j = 0;
		while (av[i][j])
		{
			answer[i].str[j] = av[i][j];
			answer[i].copy[j] = av[i][j];
			j++;
		}
		answer[i].str[j] = '\0';
		answer[i].copy[j] = '\0';
		i++;
	}
	answer[i].str = 0;
	return (answer);
}
