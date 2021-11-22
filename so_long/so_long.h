/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:41:18 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/17 16:10:03 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> /*삭제*/

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

typedef struct s_collection
{
	int						pos_x;
	int						pos_y;
	int						collection_num;
	struct s_collection		*next;
}	t_collection;

typedef struct s_collection_list
{
	t_collection	*first;
}	t_collection_list;

typedef struct s_exit
{
	int				pos_x;
	int				pos_y;
	int				exit_num;
	struct s_exit	*next;
}	t_exit;

typedef struct s_exit_list
{
	t_exit	*first;
}	t_exit_list;

typedef struct s_info
{
	int					item[2];
	int					exit[2];
	int					map_row;
	int					map_col;
	int					collection_count;
	int					exit_count;
	t_player			*player;
	t_collection_list	*collection_list;
	t_exit_list			*exit_list;
}	t_info;

int					checker_file_type(char *file);
int					checker_map(char *file, t_info *info);
int					ft_strchr_idx(const char *s, int c);
int					checker_map_border(int x, char *line, t_info *info);
int					save_info(char *line, t_info *info, int x, int y);
int					checker(char *file, t_info *info);
int					checker_map_shape(char *file, t_info *info);
int					checker_map_elements(t_info *info);
int					checker_map_conditions(char *file, t_info *info);

t_exit_list			*init_exit_list(void);
t_collection_list	*init_collection_list(void);
t_info				*init_info(void);
t_player			*init_player(void);

void				push_c_list(char *line, t_info *info, int x, int y);
void				push_e_list(char *line, t_info *info, int x, int y);

int					print_error(char *error_message, t_info *info);

#endif
