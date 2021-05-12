/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:15:42 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/07 18:33:04 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(char ans, t_option *options)
{
	if (options->width > 0 && options->minus == 0)
	{
		if (options->zero == 1)
			print_space(options->width - 1, "0");
		else
			print_space(options->width - 1, " ");
		write(1, &ans, 1);
	}
	else if (options->width > 0 && options->minus == 1)
	{
		write(1, &ans, 1);
		print_space(options->width - 1, " ");
	}
	else
	{
		write(1, &ans, 1);
		return (1);
	}
	return (options->width);
}
