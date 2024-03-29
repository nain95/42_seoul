/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:48:05 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/03 16:06:02 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

typedef struct	s_deque
{
	int		*value;
	int		rear;
	int		front;
	int		length;
	char	name;
	char	*command_list[11];
}				t_deque;

void			swap(t_deque *q, int *command);
void			push(t_deque *des, t_deque *src, int *command);
void			rotate(t_deque *q, int *command);
void			rev_rotate(t_deque *q, int *command);
void			rrr(t_deque *a, t_deque *b, int *command);

int				pop_rear(t_deque *q, int len);
int				pop_top(t_deque *q, int len);
int				deque_len(t_deque *q, int len);
void			push_rear(t_deque *q, int data);
void			push_top(t_deque *q, int data);

int				get_deque(t_deque *q, int idx);
int				is_empty(t_deque *q);
int				is_full(t_deque *q);
void			init_deque(int len, t_deque *q, char c);
void			print_command(t_deque *q, int *command, int cur);

int				get_argc(int argc, char **argv);
int				*get_pivot(t_deque *q, int cnt);
void			quicksort(int *arr, int left, int right);
int				init_a(t_deque *a, t_deque *b, int idx, char **argv);
int				check(t_deque *q, int len);

long long		ft_atoi(t_deque *a, t_deque *b, const char *str);
void			print_error(t_deque *a, t_deque *b);

int				ft_strcmp(char *s1, char *s2);
int				get_next_line(int fd, char **line);
int				line_split(char **backup, int idx, char **split_line);
int				backup_read(char **backup, int read_size, char **split_line);
char			*malloc_buf(void);

void			sort_check(t_deque *q);
int				exec(t_deque *a, t_deque *b, char *command);
int				exec2(t_deque *a, t_deque *b, char *command);

int				ft_strchr(const char *s, char c);
int				ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *src);
char			*ft_strcat(char *dest, char *src);
#endif
