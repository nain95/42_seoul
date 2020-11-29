/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:25:18 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/29 20:02:08 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

extern int	dfs(int depth, int **visible_num, int**map);

const int	g_size = 2;

int			init(int argc, char *argv[], int *visible_num[])
{
	int		index;
	char	data;

	if (argc != 2 || argv[1][(g_size * 4) * 2 - 1] != '\0')
	{
		return (0);
	}
	index = 0;
	while (index < g_size * 4)
	{
		data = argv[1][index * 2];
		if (argv[1][index * 2 + 1] != ' ' && argv[1][index * 2 + 1] != '\0')
			return (0);
		if (data == '\0' || data < '1' || data > '4')
		{
			return (0);
		}
		visible_num[index / g_size][index % g_size] = data - 48;
		index++;
	}
	return (1);
}

int			**init_malloc(int row, int col)
{
	int **malloc_return;
	int i;

	i = 0;
	malloc_return = malloc(sizeof(int *) * row);
	while (i < row)
	{
		malloc_return[i++] = malloc(sizeof(int) * col);
	}
	return (malloc_return);
}

int			main(int argc, char *argv[])
{
	int **visible_num;
	int **map;
	int memory_index;

	memory_index = 0;
	visible_num = init_malloc(4, g_size);
	map = init_malloc(g_size, g_size);
	if (init(argc, argv, visible_num) == 0 || dfs(0, visible_num, map) == 0)
		write(1, "Error\n", 6);
	memory_index = 4;
	while (memory_index--)
		free(visible_num[memory_index]);
	memory_index = g_size;
	while (memory_index--)
		free(map[memory_index]);
	free(visible_num);
	free(map);
}
