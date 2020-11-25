#include <string.h>
#include <stdio.h>
extern char *ft_strncpy(char *dest, char *src, unsigned int n);

int main()
{
	char dest[4] = "ggg";
	char src[6] = "abcde";
	//strncpy(dest,src,10);
	ft_strncpy(dest,src,10);
	printf("%s",dest);
}
