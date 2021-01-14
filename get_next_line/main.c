#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	int i;
	int ans;

	i = 0;
	if ((fd = open("test.txt", O_RDONLY)) < 0)
			printf("123");
	printf("-------test--------\n");
	while ((ans = get_next_line(fd, &line)) >= 1)
		printf("%d %s\n", ans, line);
	printf("%d %s\n", ans, line);
}
