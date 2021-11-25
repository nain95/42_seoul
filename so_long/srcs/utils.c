/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:08:20 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/20 02:08:21 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	*load_image(void *mlx, char *path)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		return (img);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
								&img->line_l, &img->endian);
	return (img);
}

int	print_error(char *error_message, t_info *info)
{
	write(1, error_message, ft_strlen(error_message));
	free_memory(info);
	return (-1);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putnbr(int nb)
{
	char	nb_arry[10];
	long	nb_change;
	int		i;

	i = 0;
	nb_change = nb;
	if (nb == 0)
		ft_putchar('0');
	else if (nb < 0)
	{
		ft_putchar('-');
		nb_change = -nb_change;
	}
	while (i < 10)
	{
		nb_arry[i] = nb_change % 10;
		nb_change = nb_change / 10;
		i++;
		if (nb_change == 0)
			break ;
	}
	while (i--)
		ft_putchar(nb_arry[i] + '0');
}
