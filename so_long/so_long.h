/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:41:18 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/16 19:05:48 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_player
{
	int pos_x;
	int pos_y;
}	t_player;

typedef struct s_info
{
	t_player *player;
	int item[2];
	int exit[2];
}	t_info;

int	checker_map_type(char *file);
int	checker_map(char *file, t_info *info);
int	ft_strchr_idx(const char *s, int c);

#endif
