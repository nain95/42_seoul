#include <stdio.h>
#include <stdlib.h>
char **ft_split(char const *s, char c);

int main()
{
	//char *tmp = "test 'test3 123' 456 '' 123   23 testing 44";
	char *tmp = "..//pipex 'assets/deepthought.txt' 'wc -w' 'cat' 'outs/test-xx.txt'";
	char **split;

	split = ft_split(tmp, ' ');
	printf("%s\n", tmp);
	while (*split)
		printf("%s\n",*split++);
}
