/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:41:05 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/16 19:41:23 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc == 1)
		write(1, "not found file name\n", 20);
	info = init_info();
	info->collection_list = init_collection_list();
	info->exit_list = init_exit_list();
	if (checker(argv[1], info) == -1)
		return (0);
	system("leaks so_long");
	return (0);
}
