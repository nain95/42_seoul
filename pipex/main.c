#include <stdio.h>
#include <unistd.h>
int main()
{
	int x = 42;
	int a;

	a = fork();
	printf("PID : %d\n", getpid());
	printf("a : %d\n", a);
	return (0);
}
