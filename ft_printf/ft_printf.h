#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_option
{
	int minus;
	int zero;
	int dot;
	int width;
}					t_option;


//=================================
void	print_hex(int num);
void	print_memory(char *addr);
int		ft_strlen(char *s);








// =============================
void	print_nbr(va_list ap, t_option *options);
void	ft_putnbr(int nb);
unsigned int	converter(int nb);
void	ft_rev_num(char *num, int count);
