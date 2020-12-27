/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:56:52 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/29 19:50:54 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int g_size;

int	up(int col, int **map)
{
	int height;
	int count;
	int i;

	count = 1;
	height = map[0][col];
	i = 1;
	while (i < g_size)
	{
		if (height < map[i][col])
		{
			count++;
			height = map[i][col];
		}
		i++;
	}
	return (count);
}

int	down(int col, int **map)
{
	int height;
	int count;
	int i;

	count = 1;
	height = map[g_size - 1][col];
	i = g_size - 2;
	while (i >= 0)
	{
		if (height < map[i][col])
		{
			count++;
			height = map[i][col];
		}
		i--;
	}
	return (count);
}

int	left(int row, int **map)
{
	int height;
	int count;
	int i;

	count = 1;
	height = map[row][0];
	i = 1;
	while (i < g_size)
	{
		if (height < map[row][i])
		{
			count++;
			height = map[row][i];
		}
		i++;
	}
	return (count);
}

int	right(int row, int **map)
{
	int height;
	int count;
	int i;

	count = 1;
	height = map[row][g_size - 1];
	i = g_size - 2;
	while (i >= 0)
	{
		if (height < map[row][i])
		{
			count++;
			height = map[row][i];
		}
		i--;
	}
	return (count);
}

int	check(int x, int y, int **input, int **map)
{
	int i;

	i = 0;
	while (i < y)
	{
		if (map[x][i++] == map[x][y])
			return (0);
	}
	i = 0;
	while (i < x)
	{
		if (map[i++][y] == map[x][y])
			return (0);
	}
	if (x == g_size - 1)
	{
		if (input[0][y] != up(y, map) || input[1][y] != down(y, map))
			return (0);
	}
	if (y == g_size - 1)
	{
		if (input[2][x] != left(x, map) || input[3][x] != right(x, map))
			return (0);
	}
	return (1);
}
