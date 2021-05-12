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

void			ft_rev_num(char *num, int count)
{
	while (--count >= 0)
	{
		write(1, &num[count], 1);
	}
}

unsigned int	converter(int nb)
{
	unsigned int unsigned_nb;

	if (nb < 0)
	{
		unsigned_nb = nb * (-1);
		write(1, "-", 1);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		unsigned_nb = 0;
	}
	else
	{
		unsigned_nb = nb;
	}
	return (unsigned_nb);
}

void			ft_putnbr(int nb)
{
	int				n;
	char			number[11];
	unsigned int	unsigned_nb;

	n = 0;
	unsigned_nb = converter(nb);
	while (unsigned_nb != 0)
	{
		number[n++] = (unsigned_nb % 10) + '0';
		unsigned_nb /= 10;
	}
	ft_rev_num(number, n);
}

int		ft_strlen(char *s)
{
	int cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

char	*ft_strchr(const char *s, int c)
{
	char *tmp;

	tmp = (char *)s;
	if (c == 0)
		return (tmp + ft_strlen(tmp));
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int		tmp;
	int					answer;
	int					flag;
	char				*s;

	flag = 1;
	tmp = 0;
	s = (char *)str;
	while (*s == ' ' || *s == '\t' || *s == '\n' ||\
			*s == '\v' || *s == '\r' || *s == '\f')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			flag *= -1;
		s++;
	}
	while ('0' <= *s && *s <= '9')
	{
		tmp *= 10;
		tmp += *s++ - '0';
	}
	answer = tmp * flag;
	return (answer);
}

void	print_int(va_list ap, t_option *options)
{
	int tmp;
	int i;

	tmp = va_arg(ap,int);
	if (options->width > 0)
	{
		for (i = 0; i < options->width; i++)
			write(1," ",1);
		ft_putnbr(tmp);
	}
	else
	{
		ft_putnbr(tmp);
		for (i = 0; i > options->width; i--)
			write(1," ",1);
	}
}

void	print_char(va_list ap, t_option *options)
{
	char ans;

	ans = va_arg(ap, int);
	write(1, &ans, 1);
}

void	print_string(va_list ap, t_option *options)
{
	char *ans;

	ans = va_arg(ap, char *);
	write(1, ans, ft_strlen(ans));
}


void	print_address(va_list ap, t_option *options)
{
	//long long ans;
	char *ans;

	ans = va_arg(ap, char *);
	print_memory(ans);

}

const char 	*printf_format(va_list ap, const char *str)
{
	char *end;
	char *type;
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
			print_int(ap, options);
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
			print_address(ap,options);
			return (++str);
		}
	}
	free(options);
	return (0);
}

int 	ft_printf(const char *str, ...)
{
	int cnt;
	char *end;
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
	return (cnt);
}
#include <stdio.h>
int main()
{
	int a;
	int b = 1234112;

	a = 1234;
	ft_printf("ab [%*d] def\n",-2,1235);
	ft_printf("abc %s def\n","ab23");
	ft_printf("%p=========%p\n",&a,&b);
	printf("%p=========%p\n",&a,&b);
}
