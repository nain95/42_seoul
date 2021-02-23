#include "ft_printf.h"

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

char	*printf_format(va_list ap, char *str)
{
	char *end;
	char *type;
	t_list *options;
	
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (0);
	while (str++)
	{
		if (*str == '-')
			options -> minus = 1;
		else if (*str == '0')
			options -> zero = 1;
		else if (*str == '*')
			options -> width = va_arg(ap, int);
		else if (end = ft_strchr("cspdiuxX", *str))
			if (*end == 'd')
				print_int(ap, list)
	}
	free(list);
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
		{
			str = printf_format(ap, str++);
			//end = ft_strchr("cspdiuxX", *str);
		}
		else
			write(1, str++, 1);
	}
	return (cnt);
}

int main()
{
	ft_printf("abc %d def",123);
}
