/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:53:45 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/03 19:09:43 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		str_len(char *str)
{
	int count;
	
	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

void	ft_print(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int 	i;
	int 	j;
	int		z;
	int 	count;
	int		swap;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < str_len(argv[i]))
		{
			z = j + 1;
			while (z < str_len(argv[i]))
			{
				if (argv[i][j] > argv[i][z])
				{
					swap = argv[i][j];
					argv[i][j] = argv[i][z];
					argv[i][z] = swap;
				}
				z++;
			}
			j++;
		}
		ft_print(argv[i]);
		i++;
	}
}
