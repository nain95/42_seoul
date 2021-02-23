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

t_list	

int 	ft_printf(const char *str, ...)
{
	int cnt;
	char *end;
	va_list ap;
	t_list *list;

	cnt = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!(list = (t_list*)malloc(sizeof(t_list))))
				return (0);
			str++;
			end = ft_strchr("cspdiuxX", *str);
			list -> conversions = *end;

			str = end;
			free(list);
		}
		else
			write(1, str, 1);
		str++;
	}
	return (cnt);
}

int main()
{
	ft_printf("abc %d def",123);
}
