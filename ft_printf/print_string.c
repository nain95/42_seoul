/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 00:01:04 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/01 00:01:12 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(char *ans, t_option *options)
{
	int		print_len;
	char	*string;

	if (ans)
		string = ft_strdup(ans);
	else
		string = ft_strdup("(null)");
	print_len = (int)ft_strlen(string);
	if (options->dot >= 0 && options->dot < print_len)
		print_len = options->dot;
	if (options->width > print_len)
	{
		if (options->minus == 1)
			write(1, string, print_len);
		print_space(options->width - print_len, " ");
		if (options->minus == 0)
			write(1, string, print_len);
	}
	else
		write(1, string, print_len);
	free(string);
	return (max(options->width, print_len));
}
