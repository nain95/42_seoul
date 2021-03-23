
#include "ft_printf.h"

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

void	print_nbr(va_list ap, t_option *options)
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
