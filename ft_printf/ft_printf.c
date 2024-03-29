/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:18:41 by ijeon             #+#    #+#             */
/*   Updated: 2021/05/13 18:33:58 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_type(va_list ap, const char *str, t_option *options, int idx)
{
	int cnt;

	cnt = 0;
	if (str[idx] == 'd' || str[idx] == 'i')
		cnt = print_nbr((long long)va_arg(ap, int), options, DECIMAL);
	else if (str[idx] == 'u')
		cnt = print_nbr(va_arg(ap, unsigned int), options, DECIMAL);
	else if (str[idx] == 'x')
		cnt = print_nbr((long long)va_arg(ap, unsigned int), options, HEX);
	else if (str[idx] == 'X')
		cnt = print_nbr((long long)va_arg(ap, unsigned int), options, HEX_UP);
	else if (str[idx] == '%')
		cnt = print_char('%', options);
	else if (str[idx] == 'c')
		cnt = print_char(va_arg(ap, int), options);
	else if (str[idx] == 's')
		cnt = print_string(va_arg(ap, char *), options);
	else if (str[idx] == 'p')
		cnt = print_memory(va_arg(ap, unsigned long long), options, HEX);
	return (cnt);
}

void		width_prec(va_list ap, const char *str, t_option *options, int idx)
{
	if (ft_isdigit(str[idx]))
	{
		if (options->dot == -1)
			options->width = options->width * 10 + str[idx] - 48;
		else
			options->dot = options->dot * 10 + str[idx] - 48;
	}
	else if (str[idx] == '*')
	{
		if (options->dot == -1)
		{
			options->width = va_arg(ap, int);
			if (options->width < 0)
			{
				options->minus = 1;
				options->width *= -1;
			}
		}
		else
			options->dot = va_arg(ap, int);
	}
}

int			printf_format(va_list ap, const char *str, int *idx)
{
	t_option	options;
	int			ret;

	options.width = 0;
	options.minus = 0;
	options.dot = -1;
	options.zero = 0;
	while (!ft_strchr(TYPE, str[*idx]))
	{
		if (str[*idx] == '-')
			options.minus = 1;
		else if (str[*idx] == '0' && options.width == 0 && options.dot == -1)
			options.zero = 1;
		else if (str[*idx] == '.')
			options.dot = 0;
		else if (ft_isdigit(str[*idx]) || str[*idx] == '*')
			width_prec(ap, str, &options, *idx);
		if (!str[++(*idx)])
		{
			(*idx)--;
			return (0);
		}
	}
	ret = check_type(ap, str, &options, *idx);
	return (ret);
}

int			ft_printf(const char *str, ...)
{
	int		cnt;
	int		idx;
	va_list ap;

	cnt = 0;
	idx = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%' && str[idx + 1])
		{
			idx++;
			cnt += printf_format(ap, str, &idx);
		}
		else
		{
			write(1, &str[idx], 1);
			cnt++;
		}
		idx++;
	}
	va_end(ap);
	return (cnt);
}
