#include "get_next_line.h"
#include <stdio.h>

/*
int main()
{
	char *line;
	int i;
	int ans;

	i = 1;
	while ((ans = get_next_line(0, &line)) >= 1)
		printf("%d %s\n", ans, line);
	printf("%d %s\n", ans, line);
}
*/

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
    return (0);
}

void	checker(t_deque *q)
{
	int i;

	i = 0;
	while (i < (q->length) - 1 )
	{
		if (q->value[i] >= q->value[i+1])
		{
			write(1, "KO\n", 3);
		}
		i++;
	}
	write(1, "OK\n", 3);
}

void	exec(t_deque *a, t_deque *b, char *command, int *tmp)
{
	if (ft_strcmp(command, "sa"))
		swap(a, tmp);
	else if (ft_strcmp(command, "sb"))
		swap(b, tmp);
	else if (ft_strcmp(command, "ss"))
	{
		swap(a, tmp);
		swap(b, tmp);
	}
	else if (ft_strcmp(command, "pa"))
		push(a, b, tmp);
	else if (ft_strcmp(command, "pb"))
		push(b, a, tmp);
	else if (ft_strcmp(command, "ra"))
		rotate(a, tmp);
	else if (ft_strcmp(command, "rb"))
		rotate(b, tmp);
	else if (ft_strcmp(command, "rr"))
	{
		rotate(a, tmp);
		rotate(b, tmp);
	}
	else if (ft_strcmp(command, "rra"))
		rev_rotate(a, tmp);
	else if (ft_strcmp(command, "rrb"))
		rev_rotate(b, tmp);
	else if (ft_strcmp(command, "rrr"))
	{
		rev_rotate(a, tmp);
		rev_rotate(b, tmp);
	}
}

int     main(int argc, char *argv[])
{
    int     i;
    int     len;
    char	*command;
	t_deque a;
    t_deque b;

    len = get_argc(argc, argv) + 1;
    init_deque(len, &a, 'a');
    init_deque(len, &b, 'b');
    i = 1;
    while (i < argc)
        init_a(&a, i++, argv, len);
    check(&a, len);
	while ((ans = get_next_line(0, &command)) >= 1)
		exec(&a, &b, command, -1);
    checker(&a);
	free(a.value);
    free(b.value);
}}
