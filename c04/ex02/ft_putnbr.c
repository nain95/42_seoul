/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:05:08 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/03 10:45:17 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void            ft_rev_num(char *num, int count)
{
    while (--count >= 0)
    {
        write(1, &num[count], 1);
    }
}

unsigned int    converter(int nb)
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

void            ft_putnbr(int nb)
{
    int             n;
    char            number[11];
    unsigned int    unsigned_nb;

    n = 0;
    unsigned_nb = converter(nb);
    while (unsigned_nb != 0)
    {
        number[n++] = (unsigned_nb % 10) + '0';
        unsigned_nb /= 10;
    }
    ft_rev_num(number, n);
}
