/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:22:46 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/23 00:22:49 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checker_file_type(char *file)
{
	int	idx;

	idx = ft_strlen(file);
	if (idx < 4 || file[idx - 1] != 'r' || \
			file[idx - 2] != 'e' || file[idx - 3] != 'b')
		return (-1);
	return (1);
}

int	checker(char *file, t_info *info)
{
	if (checker_file_type(file) == -1)
		print_error("file type error", info);
	else if (checker_map_shape(file, info) == -1)
		print_error("map shape error", info);
	else if (checker_map_conditions(file, info) == -1)
		print_error("map conditions error", info);
	else if (checker_map_elements(info) == -1)
		print_error("elements error", info);
	else
		return (1);
	return (-1);
}
