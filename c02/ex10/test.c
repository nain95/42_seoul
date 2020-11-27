#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "aaaaaaaaa";
	int i;

	strlcpy(a,"zzz",5);
	for (i = 0; i < 10; i++)
	{
		printf("%c",a[i]);
	}
}
