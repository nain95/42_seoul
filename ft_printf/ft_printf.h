/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:59:07 by ijeon             #+#    #+#             */
/*   Updated: 2021/04/30 23:44:24 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

# define TYPE "csdiupxX%"
# define DECIMAL "0123456789"
# define HEX "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

typedef struct	s_option
{
	int minus;
	int zero;
	int dot;
	int width;
}				t_option;

void			print_hex(int num);
int				print_memory(long long addr, t_option *options, char *base);
int				print_char(char ans, t_option *options);
int				print_address(char *ans, t_option *options);
int				print_string(char *ans, t_option *options);
int				num_len(long long nb, char *base);
int				print_char(char ans, t_option *options);

int				ft_printf(const char *str, ...);

int				print_nbr(long long nb, t_option *options, char *base);
unsigned int	converter(int nb);
void			ft_rev_num(char *num);

int				print_space(int size, char *space);
int				num_len(long long nb, char *base);
int				max(int a, int b);

#endif
