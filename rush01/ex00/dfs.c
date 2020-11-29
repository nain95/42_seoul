/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:49:52 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/29 19:49:49 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_size;
extern int	check(int x, int y, int **visible_number, int **map);

void		print_map(int **map)
{
	int		i;
	int		j;
	char	answer;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			answer = map[i][j] + '0';
			write(1, &answer, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int			dfs(int depth, int **visible_num, int **map)
{
	int	num;
	int	chk;

	num = 0;
	chk = 0;
	if (depth == g_size * g_size)
	{
		print_map(map);
		chk = 1;
		return (1);
	}
	while (++num < g_size + 1)
	{
		map[depth / g_size][depth % g_size] = num;
		if (check(depth / g_size, depth % g_size, visible_num, map))
		{
			chk = dfs(depth + 1, visible_num, map);
			if (chk == 1)
				return (1);
			map[depth / g_size][depth % g_size] = 0;
		}
		else
			map[depth / g_size][depth % g_size] = 0;
	}
	return (chk);
}
