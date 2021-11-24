#include <stdio.h>
#include <stdlib.h>
typedef struct a
{
	int i;
	int j;
}b;

int test1(b *str)
{
	printf("%d, %d\n", str->i, str->j);
}

int test(b *str)
{
	printf("%d, %d\n", str->i, str->j);
	test1(str);
}

b *make(void)
{
	b str;

	str.i = 1;
	str.j = 2;
	return (&str);
}

int main()
{
	b	*str;
	int a;

	str = (b *)malloc(sizeof(b));
	a = free(str);
}
