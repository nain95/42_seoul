/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:48:05 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/29 22:40:15 by ijeon            ###   ########.fr       */
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
typedef struct  s_deque
{
    int     *value;
    int     rear;
    int     front;
    int     length;
    char    name;
    char    *command_list[11];
}               t_deque;

//-------------------------------- command
void swap(t_deque *q, int *command);
void push(t_deque *des, t_deque *src, int *command);
void rotate(t_deque *q, int *command);
void rev_rotate(t_deque *q, int *command);
void rrr(t_deque *a, t_deque *b, int *command);
//-------------------------------- deque_command
void push_rear(t_deque *q, int data, int len);
void push_top(t_deque *q, int data, int len);
int pop_rear(t_deque *q, int len);
int pop_top(t_deque *q, int len);
int deque_len(t_deque *q, int len);
//-------------------------------- deque_utils
int get_deque(t_deque *q, int idx, int len);
void init_deque(int len, t_deque *q, char c);
int is_empty(t_deque *q);
int is_full(t_deque *q, int len);
//-------------------------------- utils
void swap_num(int *num1, int *num2);
int max(int a, int b);
int min(int a, int b);
//-------------------------------- main
void a_to_b(t_deque *a, t_deque *b, int cnt, int *command);
void b_to_a(t_deque *a, t_deque *b, int cnt, int *command);
void print_deque(t_deque *a, t_deque *b, int len);
int *get_pivot(t_deque *q, int cnt, int len);
void quicksort(int *arr, int left, int right);
void print_command(t_deque *q, int *command, int cur);
int get_type_num(t_deque *q, int len);
void    three_num_sort(t_deque *a, t_deque *b, int len, int *command);
void    three_num_rev_sort(t_deque *a, t_deque *b, int len, int *command);
void    rev_ra_rb(t_deque *a, t_deque *b, int *cnt_command, int *command);
//==========================================================================
int			get_next_line(int fd, char **line);

int			ft_strchr(const char *s, char c);
int			line_split(char **backup, int idx, char **split_line);
int			ft_strlen(const char *str);
int			backup_read(char **backup, int read_size, char **split_line);
char		*malloc_buf(void);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *src);
char		*ft_strcat(char *dest, char *src);
#endif
