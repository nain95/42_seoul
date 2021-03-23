/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:18:41 by ijeon             #+#    #+#             */
/*   Updated: 2021/03/24 00:10:26 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	print_hex(int num)
{
	char hex;

	if (num < 10)
	{
		hex = num + '0';
	}
	else
	{
		hex = num + 39 + '0';
	}
	write(1, &hex, 1);
}

void	print_memory(char *addr)
{
	int		i;
	int		address[16];
	long	long_addr;

	i = 0;
	long_addr = (long)addr;
	while (long_addr != 0)
	{
		address[i++] = long_addr % 16;
		long_addr /= 16;
	}
	write(1, "0X000000000000", 14 - i);
	while (i-- > 0)
	{
		print_hex(address[i]);
	}
}

int		ft_strlen(char *s)
{
	int cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

void	print_char(va_list ap, t_option *options)
{
	char ans;
	int i;

	ans = va_arg(ap, int);
	if (options->width > 0)
	{
		for (i = 0; i < options->width; i++)
			write(1," ",1);
		write(1, &ans, 1);
	}
	else
	{
		write(1, &ans, 1);
		for (i = 0; i > options->width; i--)
			write(1," ",1);
	}
}

void	print_string(va_list ap, t_option *options)
{
	char *ans;
	int i;

	ans = va_arg(ap, char *);
	if (options->width > 0)
	{
		for (i = 0; i < options->width; i++)
			write(1," ",1);
		write(1, ans, ft_strlen(ans));
	}
	else
	{
		write(1, ans, ft_strlen(ans));
		for (i = 0; i > options->width; i--)
			write(1," ",1);
	}
}


void	print_address(va_list ap)
{
	//long long ans;
	char *ans;

	ans = va_arg(ap, char *);
	print_memory(ans);

}

const char 	*printf_format(va_list ap, const char *str)
{
	t_option *options;
	
	if (!(options = (t_option*)malloc(sizeof(t_option))))
		return (0);
	while (str++)
	{
		if (*str == '-')
			options -> minus = 1;
		else if (*str == '0')
			options -> zero = 1;
		else if (*str == '*')
			options -> width = va_arg(ap, int);
		else if (*str == 'd')
		{
			print_nbr(ap, options);
			return (++str);
		}
		else if (*str == 'c')
		{
			print_char(ap, options);
			return (++str);
		}
		else if (*str == 's')
		{
			print_string(ap, options);
			return (++str);
		}
		else if (*str == 'p')
		{
			print_address(ap);
			return (++str);
		}
	}
	free(options);
	return (0);
}

int 	ft_printf(const char *str, ...)
{
	int cnt;
	//char *end;
	va_list ap;

	cnt = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			str = printf_format(ap, str++);
		else
			write(1, str++, 1);
	}
	va_end(ap);
	return (cnt);
}
