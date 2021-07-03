#include <stdio.h>
#include "libft/libft.h"

int main(int argc, char **argv, char **envp)
{
	int i;
	char **path;

	while(1)
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break;
		i++;
	}
	printf("%s\n", &envp[i][5]);
	path = ft_split(&envp[i][5], ':');
	while(*path)
	{
		printf("%s\n", *path++);
	}
}
