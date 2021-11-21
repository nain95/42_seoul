/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:08:20 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/20 02:08:21 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_error(char *error_message)
{
	write(1, error_message, ft_strlen(error_message));
	return (-1);
}
