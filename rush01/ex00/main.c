/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:56:52 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/29 00:15:12 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	print(int **result)
{
	int i = 0;
	int j = 0;
	char answer;

	for (i = 0; i < 4; i++)
	{
		for(j=0; j<4 ;j++)
		{
			answer = result[i][j] + '0';
			write(1, &answer, 1);
			if (j != 3)
				write(1, " ", 1);
		}
		write(1,"\n",1);
	}
}

int	see_top_bottom(int col, int tmp, int **result)
{
	int height;
	int count;
	int i;

	count = 1;
	if (tmp == 0)
	{
		height = result[0][col];
		i = 1;
		while (i < 4)
		{
			if (height < result[i][col])
			{
				count++;
				height = result[i][col];
			}
			i++;
		}
	}
	else if (tmp == 1)
	{
		height = result[3][col];
		i = 2;
		while (i >= 0)
		{
			if(height < result[i][col])
			{
				count++;
				height = result[i][col];
			}
			i--;
		}
	}
	return (count);
}

int	see_left_right(int row, int tmp, int **result)
{
	int height;
	int count;
	int i;

	count = 1;
	if (tmp == 0)
	{
		height = result[row][0];
		i = 1;
		while (i < 4)
		{
			if (height < result[row][i])
			{
				count++;
				height = result[row][i];
			}
			i++;
		}
	}
	else if (tmp == 1)
	{
		height = result[row][3];
		i = 2;
		while (i >= 0)
		{
			if(height < result[row][i])
			{
				count++;
				height = result[row][i];
			}
			i--;
		}
	}
	return (count);
}

int	check(int x, int y, int num,int **input, int **result)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < y)
	{
		if (result[x][j++] == num)
			return (0);
	}
	while (i < x)
	{
		if (result[i++][y] == num)
			return (0);
	}
	if (x == 3)
	{
		if (input[0][y] != see_top_bottom(y, 0, result))
			return (0);
		else if(input[1][y] != see_top_bottom(y, 1, result))
			return (0);
	}
	if (y == 3)
	{
		if (input[2][x] != see_left_right(x, 0, result))
			return (0);
		else if(input[3][x] != see_left_right(x, 1, result))
			return (0);
	}
	return (1);
}

void	dfs(int num, int **input, int **result)
{
	int i;
	i = 0;
	if (num == 16)
	{
		print(result);
		return ;
	}
	while (++i < 5)
	{
		result[num / 4][num % 4] = i;
		if (check(num / 4, num % 4, i, input, result))
		{
			dfs(num + 1, input, result);
			result[num / 4][num % 4] = 0;
		}
		else
			result[num / 4][num % 4] = 0;

	}
}

int	main(int argc, char *argv[])
{
	int	**input;
	int	**result;
	int m;
	int i;
	int j;

	m = 0;
	i = 0;
	j = 0;
	input = malloc(sizeof(int *) * 4);
	result = malloc(sizeof(int *) * 4);
	while (m < 4)
	{
		input[m] = malloc(sizeof(int) * 4);
		result[m++] = malloc(sizeof(int) * 4);
	}
	if (argc != 2 || argv[1][31] != '\0')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (j < 31)
	{
		if (argv[1][j] == '\0' || argv[1][j] < '1' || argv[1][j] > '4')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		input[i / 4][i % 4] = argv[1][j] - 48;
		i++;
		j += 2;
	}
	dfs(0, input, result);
	while (m--)
	{
		free(input[m]);
		free(result[m]);
	}
	free(input);
	free(result);
}
