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

# include "minilibx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> /*삭제*/

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT	17
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_ESC 53

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_player
{
	t_img	*img;
	int		pos_x;
	int		pos_y;
}	t_player;

typedef struct s_draw
{
	int		x;
	int		y;
	int		color;
	int		pos_x;
	int		pos_y;
	int		p_data_x;
	int		p_data_y;
	float	r_y;
	float	r_x;
}				t_draw;

typedef struct s_collection
{
	int						pos_x;
	int						pos_y;
	struct s_collection		*next;
}	t_collection;

typedef struct s_collection_list
{
	t_collection	*first;
	t_img			*img;
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
	t_img	*img;
}	t_exit_list;

typedef struct s_info
{
	char				**matrix;
	int					map_row;
	int					map_col;
	int					collection_count;
	int					exit_count;
	void				*mlx;
	void				*win;
	t_img				*wall;
	t_img				*bottom;
	t_player			*player;
	t_collection_list	*collection_list;
	t_exit_list			*exit_list;
	t_img				*img;
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

t_info				*init_info(void);
t_player			*init_player(void);

void				push_c_list(char *line, t_info *info, int x, int y);
void				push_e_list(char *line, t_info *info, int x, int y);

void				free_memory(t_info *info);

int					print_error(char *error_message, t_info *info);

void				init_player_image(t_info *info);
void				init_wall_image(t_info *info);
void				init_exit_image(t_info *info);
void				init_collection_image(t_info *info);
void				init_matrix(t_info *info);
void				init_bottom_image(t_info *info);

void				draw_on_img(t_img *img, t_img *img2, int x, int y);
void				ft_player_draw(t_info *info);
void				ft_draw(t_info *info);
void				ft_element_sub(t_info *info, \
			 t_collection *collect, int i, int j);
void				ft_element(t_info *info);
int					save_matrix(t_info *info, int x, char *line);
t_img				*load_image(void *mlx, char *path);
t_img				*init_img(void);

int					get_pixel(t_img *img, int x, int y);
void				set_pixel(t_img *img, int x, int y, int color);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
int					key_hook(int keycode, t_info *info);

#endif
