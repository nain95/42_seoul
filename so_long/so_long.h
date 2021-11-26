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

# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_ESC 53

typedef struct s_img
{
	int		bpp;
	int		line_l;
	int		endian;
	int		width;
	int		height;
	char	*addr;
	void	*img;
}				t_img;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	t_img	*img;
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

typedef struct s_info
{
	int					moves;
	int					map_row;
	int					map_col;
	int					collection_count;
	int					exit_count;
	char				**matrix;
	void				*mlx;
	void				*win;
	t_player			*player;
	t_img				*wall;
	t_img				*bottom;
	t_img				*collection;
	t_img				*exit;
	t_img				*img;
}	t_info;

int			checker_map_border(int x, char *line, t_info *info);
int			checker_line_elements(int x, char *line, t_info *info);
int			checker_map_conditions(char *file, t_info *info);
int			checker_map_shape(char *file, t_info *info);
int			checker_map_elements(t_info *info);

int			checker_file_type(char *file);
int			checker(char *file, t_info *info);

int			get_pixel(t_img *img, int x, int y);
void		set_pixel(t_img *img, int x, int y, int color);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
t_img		*load_image(void *mlx, char *path);

void		draw_on_img(t_img *img, t_img *img2, int x, int y);
void		ft_player_draw(t_info *info);
void		ft_draw(t_info *info);
void		ft_element_sub(t_info *info, int i, int j);
void		ft_element(t_info *info);

void		free_map1(t_info *info);
void		free_memory(t_info *info);

void		init_matrix(t_info *info);
t_img		*init_img(void);
t_info		*init_info(void);
t_player	*init_player(void);

int			key_hook(int key, t_info *info);
int			close_clean(t_info *info);
void		pos_check(t_info *info);

void		init_player_image(t_info *info);
void		init_bottom_image(t_info *info);
void		init_wall_image(t_info *info);
void		init_exit_image(t_info *info);
void		init_collection_image(t_info *info);

int			save_player_pos(t_info *info, int x, int y);
void		save_matrix(t_info *info, int x, char *line);

int			print_error(char *error_message, t_info *info);
int			ft_strchr_idx(const char *s, int c, int start);
int			ft_strchr_count(const char *s, int c);
void		ft_putnbr(int nb);
int			ft_putchar(char c);
#endif
