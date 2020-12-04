/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:56:16 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/04 23:42:15 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_count;

void	init(int (*map)[10])
{
	int i;
	int j;

	g_count = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		check(int x, int y, int (*map)[10])
{
	int i;
	int j;

	i = 0;
	while (i < x)
	{
		if (map[i][y] == 1)
			return (0);
		i++;
	}
	i = x;
	j = y;
	while (--i >= 0 && --j >= 0)
	{
		if (map[i][j] == 1)
			return (0);
	}
	while (--x >= 0 && ++y <= 9)
	{
		if (map[x][y] == 1)
			return (0);
	}
	return (1);
}

void	print(int (*map)[10])
{
	int		i;
	int		j;
	char	answer;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (map[i][j] == 1)
			{
				answer = j + '0';
				write(1, &answer, 1);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	recursive(int depth, int (*map)[10])
{
	int		num;

	num = 0;
	if (depth == 10)
	{
		print(map);
		write(1, "\n", 1);
		g_count++;
		return ;
	}
	while (num < 10)
	{
		if (check(depth, num, map) == 1)
		{
			map[depth][num] = 1;
			recursive(depth + 1, map);
			map[depth][num] = 0;
		}
		num++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int map[10][10];

	init(map);
	recursive(0, map);
	return (g_count);
}

int main()
{
	ft_ten_queens_puzzle();
}
